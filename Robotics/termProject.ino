#define LIQUOR 9 // 칵테일 재료 개수
#define COCKTAIL 5 // 만들 수 있는 칵테일 개수

// 예시
#define CIDER 1
#define COLA 2
#define ORANGE 3
#define JIN 4
#define RUM 5
#define VODKA 6
#define TEQUILA 7
#define WHISKEY 8
#define TONIC 9

#define JIN_TONIC 0
#define JACK_COCK 1
#define LONGISLAND_ICETEA 2
#define COCKTAIL_4 3
#define COCKTAIL_5 4

int liquor[LIQUOR] = {CIDER, COLA, ORANGE, JIN, RUM, VODKA, TEQUILA, WHISKEY, TONIC}; // 칵테일 재료 저장 배열

int cocktail[COCKTAIL][LIQUOR] = {
    {JIN, TONIC, },
    {CIDER, ORANGE, RUM, },
    //...
}; // 칵테일에 만드는 데 필요한 술 저장 배열

int ratio[COCKTAIL][LIQUOR] = {
    {1, 1, },
    {2, 1, 3, },
}; // 필요한 술의 비율 저장 배열

void setup(){
    // bluetooth 연결
    // 기타 센서 초기값 설정
}

void loop(){

    // 1. 사용자 입력 받기 (만들고자 하는 칵테일 번호 받기)

    // 2. 입력받은 칵테일이 필요로 하는 술(cocktail, ratio배열 참고)의 용량 체크(수압센서/수위센서)

    // 2-1. 만약 용량이 충분치 않을 경우, 오류 메세지 반환 후 1번으로 돌아감 (용량의 기준은 1잔을 만드는 데 필요한 각 술의 양)

    // 2-2. 용량이 충분할 경우...

        // 3. 칵테일 따르는 곳에 잔이 위치했는지 체크(초음파센서?)

        // 3-1. 잔이 위치하지 않았을 경우 오류 메세지 반환 후 1번으로 돌아감 

        // 3-2. 잔이 위치했을 경우...

            // 4. cocktail과 ratio 배열을 참고하여, 도합 100ml을 기준으로 비율에 맞게 펌프를 가동시킨다. 

            // 5. 펌프를 가동시키면서, LCD에 칵테일의 진행 순서를 보여준다. 

            // 6. 칵테일 제조가 완료될 경우 소리를 내서 알린다. 

            // 7. 1번으로 돌아간다. 
}

/*      
int fan = 2;

void setup() {
    pinMode(fan, OUTPUT);
}

void loop() {
    digitalWrite(fan, HIGH);
    delay(2000);
     digitalWrite(fan, LOW);
     delay(2000);
}
*/   

/*
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int liquor[3] = {};

void setup()
{
    // 버튼 3개 
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  lcd.begin(16,2);
}

void showCocktail(char str[]){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(str);
}

void loop()
{
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("SelectCocktail");

    if (digitalRead(7) == HIGH){
        showCocktail("Cock1");
    }
    else if (digitalRead(6) == HIGH){
        showCocktail("Cock2");
    }
    else if (digitalRead(5) == HIGH){
        showCocktail("Cock3");
    }

    delay(3000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Selected!");
}

*/


/*
void setup(){
  Serial.begin(9600);
}
void loop(){
  int waterSensorVal = analogRead(A0); 
  Serial.print("Water Sensor : ");
  Serial.println(waterSensorVal);
  delay(100);  
}
*/

/*
#include <DHT11.h>
DHT11 dht11(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp, humi;

  int result = dht11.read(humi, temp);

  if(result == 0){
    Serial.print("temp : ");
    Serial.println(temp);
    Serial.print("humi : ");
    Serial.println(humi);
  }

  else{
    Serial.print("Error");
  }
  
  delay(DHT11_RETRY_DELAY);
}
*/

/*
int bell[27] = {277, 370, 349, 311, 277, 233, 247, 277, 311, 208, 233, 247, 233, 277,
277, 370, 349, 311, 277, 370, 370, 415, 370, 349, 311, 349, 370};
int times[27] = {300, 100, 100, 100, 300, 300, 100, 100, 100, 100, 100, 100, 300,
300, 300, 100, 100, 100, 300, 300, 100, 100, 100, 100, 100, 100, 600};

void setup() {
  pinMode(8,OUTPUT);
}

void loop() {

  for(int i=0; i< 27; i++){
    tone(8, bell[i],times[i]);
    delay(times[i]*2);
    noTone(8);
  }

}
*/

/*
#define tr 8
#define ec 7

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  }

void loop(){
digitalWrite(tr, LOW);
  delayMicroseconds(10);
  digitalWrite(tr, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr, LOW);
  
  long duration = pulseIn(ec, HIGH);
  float distance = duration / 58.2; 
  
  Serial.println(distance);
  delay(1000);
}
*/