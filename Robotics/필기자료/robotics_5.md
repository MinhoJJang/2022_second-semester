# Robotics_4, Analog

# Photo resister

왼쪽 다리에 5V를 연결하고 오른쪽 다리에 GND를 연결하면 된다. 이때 5V를 바로 연결하는 게 아니라 저항을 끼고 연결해야 한다. 또한 5V를 연결하는 쪽에 ANALOGIN 핀을 연결해주어야 한다.

포토레지스터는 빛이 들어오면 저항이 낮아지고 어두워지면 저항이 올라간다.

```c
#define PIN A0
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reg = analogRead(PIN);
  Serial.println(reg);
  delay(1000);
}
```

# Potentiometer

가변저항. 왼쪽 핀을 5V, 오른쪽 핀을 GND에 연결한다. 가운데 핀을 ANALOGIN 핀에 연결해주면 된다. 아날로그 값으로 0~1023을 읽어온다.

```c

Servo myservo;

void setup()
{
  myservo.attach(9);
}

void loop()
{
  int radious = analogRead(A0);
  // analogRead로 단순하게 값을 읽어온다.
  radious = map(radious,0,1023,0,180);
  myservo.write(radious);
}
```

# Temperature sensor

맨 왼쪽에 +, 오른쪽에 -, 가운데를 ANALOGIN에 연결하면 된다. 저항도 필요 없다. 온도 센서의 값을 적절하게 변형하면 Celcious단위의 온도가 나온다.

```c
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(A0);
  float voltage = val * 5.0 / 1024.0;
  float temp = 100.0 * voltage - 50;
  Serial.println(temp);
  delay(1000);
}
```

# analogRead(PIN)

input된 전압 0~5V를 0~1023의 int 값으로 변형시켜준다.

# map(value, fromLow, fromHigh, toLow, toHigh)

fromLow~High은 value를 받는 범위이다. 주로 0~1023을 택한다.

toLow~High은 받은 value를 적절하게 toLow부터 toHigh까지 변형시켜준다.

```c
void loop()
{
  int radious = analogRead(A0);
  radious = map(radious,0,1023,0,180);

    0~1023까지의 값을 0~180으로 바꿔준다.

  myservo.write(radious);
}
```
