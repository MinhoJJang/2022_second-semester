#include <LiquidCrystal.h>
#include <DHT11.h>

int bell[27] = {277, 370, 349, 311, 277, 233, 247, 277, 311, 208, 233, 247, 233, 277,
277, 370, 349, 311, 277, 370, 370, 415, 370, 349, 311, 349, 370};
int times[27] = {300, 100, 100, 100, 300, 300, 100, 100, 100, 100, 100, 100, 300,
300, 300, 100, 100, 100, 300, 300, 100, 100, 100, 100, 100, 100, 600};

// 온습도센서
DHT11 dht11(A0);

// 수위센서 : A1 
#define FALSE 0
#define TRUE 1

// 워터펌프
#define mot1 11
#define mot2 13
#define mot3 12

// 버튼
#define cock1 5
#define cock2 6
#define cock3 7

// 초음파센서
#define tr 52
#define ec 53

// LED
#define Redled 37
#define Blueled 35

// 버저 
#define buz 8

LiquidCrystal lcd(22,24,26,28,30,32);

LiquidCrystal lcd2(38,40,42,44,46,48);

int cock[3]; 
int message;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(cock3, INPUT);
  pinMode(cock2, INPUT);
  pinMode(cock1, INPUT);
  lcd.begin(16,2);
  lcd2.begin(16,2);
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  pinMode(mot3, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
  pinMode(Redled, OUTPUT);
  pinMode(Blueled, OUTPUT);
  pinMode(buz, OUTPUT);
}

// LCD에 글자 띄우는 함수
void showStrInLCD(char str[]){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(str);
}

// LED 불 켜는 센서. 문제 발생 시 빨간불 나오게 한다. 
void checkError(char reason[]){

    digitalWrite(Redled, HIGH);
    showStrInLCD(reason);
    delay(3000);
    digitalWrite(Redled, LOW);
    lcd.clear();
}



// 수위센서, 온습도센서가 모두 true값 반환할 때에만 작동할 수 있도록

// 온습도 센서 
int checkTemperatureHumidity(){

   float temp, humi;

   int result = dht11.read(humi, temp); 

   lcd2.clear();
   lcd2.setCursor(0,0);
   lcd2.print("humi: ");
   lcd2.print(humi);
   lcd2.setCursor(0,1);
   lcd2.print("temp: ");
   lcd2.print(temp);

   if(result == 0){
        if(humi < 40 && temp < 25){
            // 적절 온습도일 경우           
            return TRUE;
        }
        else{
            checkError("Error:Temp&Humi");
            return FALSE;
        }
   }
   return FALSE;
}

// 수위센서 
int checkWaterLevel(){

    int waterSensorVal = analogRead(A1); 
    if(waterSensorVal > 300){
        // 적절 수위일 경우
        return TRUE;
    }
    else{
        checkError("Error:Waterlevel");
    }
    return FALSE; 
}

// 컵과의 거리 재는 함수 
int checkDistance(){

  digitalWrite(tr, LOW);
  delayMicroseconds(10);
  digitalWrite(tr, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr, LOW);
  
  long duration = pulseIn(ec, HIGH);
  float distance = duration / 58.2; 

  if(distance < 10 && distance > 6){
    // 컵의 위치가 적절할 경우 
    return TRUE;
  }
  else{
    checkError("Error:SetYourCup");
  }
  
  return FALSE; 
}

// lcd에 어떤 칵테일 만들 것인지 보여주는 함수
int selectCocktail(){

    int num;
    showStrInLCD("Press Button");
  
    while(1){
        if (digitalRead(cock1) == HIGH){
            showStrInLCD("cock1");
            num = cock1;
            break;
        }
        else if (digitalRead(cock2) == HIGH){
            showStrInLCD("cock2");
            num = cock2;  
            break;
        }
        else if (digitalRead(cock3) == HIGH){
            showStrInLCD("cock3");
            num = cock3;  
            break;
        }
    }
    delay(1000);
    showStrInLCD("Selected!");
    delay(2000);

    return num;
}

void activateWaterPump(int moter1, int moter2){
    digitalWrite(moter1, HIGH);
    delay(3000);
    digitalWrite(moter1, LOW);
    delay(1000);    
    digitalWrite(moter2, HIGH);
    delay(3000);
    digitalWrite(moter2, LOW);
    delay(1000)
}

// 칵테일 만드는 함수
void makeCocktail(int num){

    showStrInLCD("Loading..."); 

    if(num == cock1){            
        activateWaterPump(mot1, mot2);
    }        
    else if(num == cock2){
        activateWaterPump(mot1, mot3);
    }
    else if(num == cock3){          
        activateWaterPump(mot3, mot2);
    }
}

// 다 끝나고 버저 출력 
void Buzzer(){
    digitalWrite(Blueled, HIGH);
    showStrInLCD("Success!");

    for(int i=0; i< 27; i++){
        tone(8, bell[i],times[i]);
        delay(times[i]*2);
        noTone(8);
    }
      
    digitalWrite(Blueled, LOW);
    lcd.clear();
}

void loop()
{
    int num = 0;

    if(checkTemperatureHumidity()){
        if(checkWaterLevel()){
            if(checkDistance()){            
                num = selectCocktail();                 
                makeCocktail(num);              
                Buzzer();              
            }
        }
    } 
}