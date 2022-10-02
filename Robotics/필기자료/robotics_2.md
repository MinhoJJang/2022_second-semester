# Robotics_2

아두이노 코딩은 두가지 함수를 사용하는데, setup()과 loop()이다. setup() 은 아두이노 보드에 전원을 공급했을 때 1회 작동하는 코드이고, loop()은 문자 그대로 전원이 공급되는 한 계속해서 반복하는 코드이다.

```c
void setup(){
  pinMode(13, OUTPUT); //13번 핀을 출력 모드로 설정
}

void loop(){
  digitalWrite(13, HIGH); //LED 켜기
  delay(1000); //1초 기다리기
  digitalWrite(13, LOW); // LED 끄기
  delay(1000); //1초 기다리기
}
```

## 대표 함수

### pinMode(pin, mode);

pin: 설정하려는 핀의 번호
mode: OUTPUT, INPUT

-> OUTPUT: 출력모드. LED를 켜거나 모터를 구동하는 데 사용
-> INPUT: 입력모드. 센서값을 읽어오는데 사용

### digitalWrite(pin, mode);

해당 핀에 HIGH, LOW 값을 입력할 수 있다. HIGH면 전원이 공급되고 LOW면 전원이 차단된다.

### delay(msec);

delay(1000) = 1000 microsecond = 1 second
