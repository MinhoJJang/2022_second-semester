int light=0;
int buttonState = 0;
void setup()
{
pinMode(10, OUTPUT);
pinMode(8, INPUT);
pinMode(A0, INPUT);
Serial.begin(9600);

}

void loop()
{
light = analogRead(A0);
buttonState = digitalRead(8);
light = map(light, 0, 1023, 255, 0);
Serial.println(light);

analogWrite(10, light);

if (buttonState == HIGH)
   analogWrite(10, LOW);
}