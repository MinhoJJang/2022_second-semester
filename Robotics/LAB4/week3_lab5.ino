// C++ code
//
void setup()
{
 	Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available() >0){
   	int count = Serial.parseInt();
    Serial.print("Input Number is : ");
    Serial.println(count);
    for(int i = 0; i<count; i++){
     	digitalWrite(13, HIGH);
      	delay(1000);
      	digitalWrite(13, LOW);
      	delay(1000);
    }
  }
}