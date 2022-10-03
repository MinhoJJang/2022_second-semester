# Robotics_4, Serial

## Serial.begin()

시리얼 통신 속도이다. 일반적으로 9600bps 을 사용한다.

```c
void setup() {
Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
```

## Serial.print()

print를 사용하는 방법은 두가지가 있다.

1. `Serial.print(val)`

- val을 그대로 화면에 출력한다.

2. `Serial.print(val, format)`

- val이 int 혹은 float 타입일 경우에 사용 가능하다.
- val이 int타입일 경우, format으로는 `BIN, OCT, DEC, HEX` 을 사용하여 십진법 숫자를 이진법으로 표현할 수 있다.
- val이 float 타입일 경우, format으로 숫자를 사용해 소수점 아래 n 번째 자리까지 나타낼 수 있으며 자동 반올림되어 출력된다.

```c
    Serial.print(val)
    Serial.print(val, format)

void loop() {
    Serial.print(78) gives "78"
    Serial.print(1.23456) gives "1.23"
    Serial.print('N') gives "N"
    Serial.print("Hello world.") gives "Hello world."
    Serial.print(78, BIN) gives "1001110"
    Serial.print(78, OCT) gives "116"
    Serial.print(78, DEC) gives "78"
    Serial.print(78, HEX) gives "4E"
    Serial.println(1.23456, 0) gives "1"
    Serial.println(1.23456, 2) gives "1.23"
    Serial.println(1.23456, 4) gives "1.2346"
}
```

## Serial.write()

`Serial.write(val)`

print와는 다르게, val을 아스키코드로 자동 변환한다.

```c
Serial.write(49); // 1
Serial.write(85); // U
```

## Serial.available()

시리얼에 사용자가 값을 입력했을 경우, read 가능한 byte를 리턴한다. 당연하게도, 값을 입력하면 byte가 존재하므로 리턴값은 0보다 크다. 따라서 아래와 같이, Serial.read()를 할 수 있는 상태인지 체크하기 위해 if문 내부에 Serial.available()을 자주 사용한다.

```c
int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}
```

## Serial.read()

사용자가 입력한 데이터값을 바이트로 받는다. 예를 들어 12를 입력하면 1 따로 2 따로 받는다. 입력을 바이트로 받기 때문에, 아래 예제에서 write로 출력하면 입력한 숫자 그대로 출력되고 print로 출력하면 아스키코드로 변환하여 출력된다. 즉 1을 입력하면 print는 49를, write는 1을 출력한다.

```c
void loop() {
    if (Serial.available() > 0) {
    // send data only when you receive data
        int incomingByte=Serial.read(); // read the incoming byte
        Serial.print("Serial.print : ");
        Serial.println(incomingByte);
        Serial.print("Serial.write : ");
        Serial.write(incomingByte);
}
```

## Serial.parseInt()

입력한 값을 유효한 int 타입 숫자로 변경한다. 문자가 입력되면 0이 출력되고, 숫자가 입력되면 그대로 입력한 숫자값이 출력된다.

```c
void loop() {
    if (Serial.available() > 0) {
        // send data only when you receive data
        int par=Serial.parseInt();
        Serial.print("Serial.parseInt : ");
        Serial.println(par);
    }
}
```
