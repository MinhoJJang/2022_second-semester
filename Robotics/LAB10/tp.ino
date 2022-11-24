#include <LiquidCrystal.h>
#include <DHT11.h>

int bell[27] = {277, 370, 349, 311, 277, 233, 247, 277, 311, 208, 233, 247, 233, 277,
277, 370, 349, 311, 277, 370, 370, 415, 370, 349, 311, 349, 370};
int times[27] = {300, 100, 100, 100, 300, 300, 100, 100, 100, 100, 100, 100, 300,
300, 300, 100, 100, 100, 300, 300, 100, 100, 100, 100, 100, 100, 600};

DHT11 dht11(A0);

#define fan 4

#define cock1 5
#define cock2 6
#define cock3 7

#define tr 3
#define ec 2

#define led 8

#define FALSE 0
#define TRUE 1

#define buz 9

LiquidCrystal lcd(13,12,11,10,9,8);

int cock[3]; 

void setup()
{
  Serial.begin(9600);
  pinMode(cock3, INPUT);
  pinMode(cock2, INPUT);
  pinMode(cock1, INPUT);
  lcd.begin(16,2);
  pinMode(fan, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);
}

// LED 불 켜는 센서. 문제 발생 시 빨간불 나오게 한다. 
void ledRedLight(char[] reason){

    digitalWrite(led, HIGH);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(reason);
    delay(5000);
    digitalWrite(led, LOW);
    lcd.clear();
}

// 수위센서, 온습도센서가 모두 true값 반환할 때에만 작동할 수 있도록

// 온습도 센서 
int getTemperatureHumidity(){

   float temp, humi;

   int result = dht11.read(humi, temp);

   if(result == 0){
        if(humi > 30 && temp < 25){
            // 적절 온습도일 경우 
            
            return TRUE;
        }
        else{
            ledRedLight("Temp&Humi");
        }
   }
  
  // delay(DHT11_RETRY_DELAY);
    return FALSE;
}

// 수위센서 
int getWaterLevel(){

    int waterSensorVal = analogRead(A0); 
    if(waterSensorVal > 150){
        // 적절 수위일 경우
        return TRUE;
    }
    else{
        ledRedLight("WaterLevel");
    }
    return FALSE; 
}

// 컵과의 거리 재는 함수 
int getDistance(){

  digitalWrite(tr, LOW);
  delayMicroseconds(10);
  digitalWrite(tr, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr, LOW);
  
  long duration = pulseIn(ec, HIGH);
  float distance = duration / 58.2; 

  if(distance < 10){
    // 컵의 위치가 적절할 경우 
    return TRUE;
  }
  else{
    ledRedLight("CupDistance");
  }
  
  return FALSE; 
}

// lcd에 어떤 칵테일 만들 것인지 보여주는 함수
int showCocktail(){

    int num;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Select Cocktail");
    char str[10];

    if (digitalRead(5) == HIGH){
        str = "Cock1";
        num = 1;
    }
    else if (digitalRead(6) == HIGH){
        str = "Cock2";
        num = 2;
    }
    else if (digitalRead(7) == HIGH){
        str = "Cock3";
        num = 3;
    }

    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(str);
    
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,1);
    
    lcd.print("Selected!");
    
    return num;
}

// 칵테일 만드는 함수
void cocktailMaker(int num){

    lcd.print("Loading...");

    switch(num){
        case 1:
        // 술 1번 2번 나오게 
            digitalWrite(fan, HIGH);
            delay(2000);
            digitalWrite(fan, LOW);
            delay(2000);

        break; 

        case 2:
        // 술 3번 2번 나오게 


        break; 

        case 3:
        // 술 3번 1번 나오게 

        break; 
    }
  
}

// 다 끝나고 버저 출력 
void Buzzer(){

    lcd.print("SUCCESS!");

    for(int i=0; i< 27; i++){
        tone(8, bell[i],times[i]);
        delay(times[i]*2);
        noTone(8);
    }

    lcd.clear();
}

void loop()
{
    // 온습도와 수위, 컵 위치가 모두 True를 반환하였을 경우
    if(getTemperatureHumidity() && getWaterLevel && getDistance()){

        // lcd에 어떤 칵테일 만들 것인지 보여주고, 칵테일 제조
        cocktailMaker(showCocktail());  

        // 다 만들면 버저 울리고 종료   
        Buzzer();
    }   
}
