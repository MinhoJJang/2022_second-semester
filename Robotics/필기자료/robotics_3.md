# Robotics_3, LED

LED를 연결할 때에는, LED의 발이 더 긴 쪽이 (+) 쪽이고 그곳에 저항을 연결한다. +를 anode, -를 cathode 라고 하며, +에서 -로 전류가 흐를 때에만 점등된다.

VCC = +
GND = -

핵심은, +쪽이 -쪽 보다 공급 전압이 높아야 전기가 흐른다. 즉, +와 -의 전압이 같으면 당연히 전류가 없으므로 LED가 점등하지 않는다. 이 말인 즉슨 LED의 연결 방식에 따라 `digitalWrite(pin, HIGH)` 를 한다고 반드시 LED가 켜지지 않는다는 것이다.

[LED 점멸](https://m.blog.naver.com/kaiserkhan21/221043751112)

## digitalRead(pin);

해당 핀이 HIGH인지 LOW인지 체크한다. int 값을 반환한다. 만약 7번 pin과 5V가 연결될 경우 HIGH일 것이고, GND가 연결될 경우 LOW일 것이다.

```c
void setup()
{
   pinMode(13, OUTPUT);        // 13번 핀을 출력으로 설정
   pinMode(7, INPUT);          // 7번 핀을 입력으로 설정
}

void loop()
{
   int val = digitalRead(7);   // 7번 핀을 읽어와서 val이라는 값에 저장
   digitalWrite(13, val);      // val값에 따라서 13번 핀의 LED를 조절
}
```

## analogWrite(pin, value)

[What is PWM?](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=roboholic84&logNo=220333343346)

아두이노의 PWM(Pulse Width Modulation) 으로 digital의 HIGH, LOW 말고 연속적인 값을 출력할 수 있다. 아두이노에서는 오직 ~ 기호가 앞에 붙은 핀에서만 PWM출력이 가능하다.

```c
#define PIN 11

void setup()
{
  pinMode(PIN, OUTPUT);
}

void loop()
{
  for(int val = 0; val<255; val+=15){
    analogWrite(PIN, val);
    delay(200);
  }
}
```
