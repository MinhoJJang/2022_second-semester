// C++ code
//
void setup()
{

}

void loop()
{
  analogWrite(11, 255); 
  delay(1000); 
  analogWrite(11, 0); 
  delay(100);
  analogWrite(10, 255); 
  delay(1000); 
  analogWrite(10, 0); 
}