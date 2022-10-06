# Buzzer, Ultrasonic sensor, LCD

---

# Buzzer

양극, 음극 두 핀으로 이루어져 있다. 양극에 디지털 핀을 연결하고, OUTPUT으로 설정해준다. 음극은 GND와 연결해주면 된다. 버저에서 소리를 내는 함수는 tone()이다.

## tone()

소리를 내는 함수

```c
tone(pin, frequency)
tone(pin, frequency, duration)
```

## noTone()

n번 핀에서 출력되는 소리를 끄는 함수

```c
noTone(pin)
```

## Code

```c
void setup(){
    pinMode(8, OUTPUT);
}

void loop(){
    tone(8, 523, 500);
    // 523Hz 만큼의 소리 == 높은 도 를 0.5초동안 발생
    or
    tone(8, 523);
    // 시간 제한 없이 계속 발생
    notone(8);
    // 스피커 꺼짐
}
```

# Ultrasonic sensor

VCC, GND, TRIG, ECHO 4개의 핀으로 구성되어 있다. VCC는 +, 5V에 연결하고 GND는 -, GND에 연결하면 된다. TRIG와 ECHO는 디지털 핀에 연결하면 되는데, ECHO에 연결된 핀을 INPUT, TRIG에 연결된 핀을 OUTPUT으로 설정해준다.

## pulseIn()

```c
pulseIn(pin, value)
pulseIn(pin, value, timeout)
```

value가 HIGH이면, 해당 핀의 입력이 LOW 에서 HIGH로 변하는 순간부터 시간을 측정하여 다시 LOW로 바뀌는 시점까지의 시간을 마이크로초(us)단위로 반환한다. 만약 timeout까지 펄스가 만들어지지 않았을 경우 0을 반환한다. value는 일반적으로 HIGH를 사용한다. LOW는 거의 사용되지 않는다. timeout의 기본값은 1초이다.

## delayMicroseconds()

```c
delayMicroseconds(us)
```

## Code

```c
void setup()
{
  pinMode(7, OUTPUT); //7번핀이 출력핀
  pinMode(6, INPUT);  //6번핀이 입력핀 / 초음파센서
}

void loop()
{
 digitalWrite(7, LOW); //7번핀에 LOW값을 출력
 delayMicroseconds(7); //단위는 마이크로초이고 1초=1000밀리초
 digitalWrite(7, HIGH);
 delayMicroseconds(10);
 digitalWrite(7, LOW); //TRIG에서 LOW->HIGH->LOW

long duration = pulseIn(6, HIGH);
  //핀으로 입력되는 펄스의 시간을 측정하는 함수.
  //pinMode에서 INPUT설정. 6번핀의 입력이 LOW->HIGH->LOW되는 과정의 시간을 마이크로초 단위로 변환

 long distance = duration / 58.2;
 //초음파가 갔다 온 거리를 58.2로 나눔. (29.1microseconds마다 1cm이동하기 때문)
}
```

# LCD

GND : GND
VCC : 5V
VO : 저항 + GND (밝기조절)
RS(rs) : Register. pin과 연결
RW : GND
E(enable) : 쓰기 활성화. pin과 연결
d4, d5, d6, d7 : pin과 연결
LED 양극: 저항 + 5V
LED 음극: GND

## LiquidCrystal()

```c
LiquidCrystal object(rs, enable, d4, d5, d6, d7)
```

## object.begin()

Initializing the interface to the LCD screen, and specifies the dimensions (width and height) of the display. begin() needs to be called before any other LCD library commands.

`object.begin(cols, rows)`
object: a variable of type LiquidCrystal
cols: the number of columns that the display has
rows: the number of rows that the display has

`lcd.begin(16,2)`
-> lcd가 16\*2로 이루어져 있기 때문이다

## object.print()

```c
object.print(data)
object.print(data, BASE)
```

object: a variable of type LiquidCrystal
data: the data to print (char, byte, int, long, or string)
BASE (optional): the base in which to print numbers: BIN for binary (base 2), DEC for
decimal (base 10), OCT for octal (base 8), HEX for hexadecimal (base 16)

`lcd.print("PERPECT!");`

## setCursor()

Positioning the LCD cursor
This function sets the location at which subsequent text written to the LCD will be displayed

`object.setCursor(col, row)`

object: a variable of type LiquidCrystal
col: the column at which to position the cursor (with 0 being the first column)
row: the row at which to position the cursor (with 0 being the first row)

`lcd.setCursor(0,1);`

LCD 구조: 만약 lcd.setCursor(1,0) 을 하고 PERFECT!을 출력시키면 아래와 같이 출력된다.
col0 col1 col2 col3 ... col 15
row0 P E R ...
row1

## object.display() / object.noDisplay()

lcd의 화면을 켜고 끄는 함수이다.

## object.clear()

lcd에 적힌 글자들을 모두 지우는 함수이다.

```c
#include <LiquidCrystal.h> //lcd 사용을 위한 라이브러리 지정
LiquidCrystal lcd(12,11,2,3,4,5);
// 이제 lcd가 object 이름이 된다.

void setup(){
    lcd.begin(16,2); // lcd의 (열,행) 명시
}

void loop(){
    lcd.clear(); //LCD 초기화
    lcd.setCursor(0,0);
    lcd.print("PERPECT!");
    delay(1000);
}
```
