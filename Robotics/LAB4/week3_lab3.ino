// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT);
}

int count = 0;

void loop()
{
  
  Serial.println(count++);
  delay(1000);
  if(digitalRead(8) == HIGH){
   	count = 0; 
  }
}