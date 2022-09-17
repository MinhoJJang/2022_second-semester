void setup(){
  Serial.begin(9600);
}

int count = 1;

void loop(){
  Serial.print(count++);
 Serial.println(" sec");
  delay(1000);
}