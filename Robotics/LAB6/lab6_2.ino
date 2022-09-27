#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(9);
}

void loop()
{
  int radious = analogRead(A0);
  radious = map(radious,0,1023,0,180);
  myservo.write(radious);
}