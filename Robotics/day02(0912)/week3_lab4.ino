// C++ code
//
void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(7, INPUT);
}

void loop()
{
  if(digitalRead(13) == HIGH){
    analogWrite(11, 255);
  }
  else if(digitalRead(12) == HIGH){
    analogWrite(10, 255);
  }
  else if(digitalRead(7) == HIGH){
    analogWrite(9, 255);
  }
  else {
   analogWrite(11, 0);
    analogWrite(10, 0);
     analogWrite(9, 0);
  }
  
}