// C++ code
//

int redPin = 11;
int greenPin = 9;
int bluePin = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

void loop()
{
  int val1 = analogRead(A0);
  val1 = map(val1,0,1023,0,255);
  analogWrite(redPin,val1);
  
  int val2 = analogRead(A2);
  val2 = map(val2,0,1023,0,255);
  analogWrite(greenPin,val2);
  
  int val3 = analogRead(A4);
  val3 = map(val3,0,1023,0,255);
  analogWrite(bluePin,val3);
  
  Serial.print(val1);
  Serial.print(val2);
  Serial.println(val3);
  
}