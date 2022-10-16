# robotics_6

# Servo Motor

서보모터의 전선 색깔에 맞춰 연결해줘야 한다.

red: 5V
black & brown: GND
yellow, orange or white: input

# 주요 함수

1. #include <Servo.h>
2. Servo myservo;
3. myservo.attach(9 or 10);
   servo library가 9와 10만 지원하기 때문이다.
4. myservo.write(angle);
   angle은 0부터 180사이 숫자이다.

```c
#include <Servo.h>

Servo myservo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(10, OUTPUT);
}

void loop()
{
  int radious = analogRead(A0);
  radious = map(radious,0,1023,0,180);
  myservo.write(radious);
}
```
