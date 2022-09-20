// C++ code
//
void setup()
{
   Serial.begin(9600);
   pinMode(10,OUTPUT);
}

void loop()
{
  int val = analogRead(A0);
  val = map(val,0,1023,0,255);
  Serial.println(val);

  analogWrite(10,val);
}