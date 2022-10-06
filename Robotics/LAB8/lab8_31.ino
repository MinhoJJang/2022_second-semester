// LAB8_3
//
#define pp 13
#define tr 8
#define ec 7

const int hz[] = {261, 293, 329, 349, 391};

void setup()
{
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
}

void loop()
{
  digitalWrite(tr, LOW);
  delayMicroseconds(10);
  digitalWrite(tr, HIGH);
  delayMicroseconds(10);
  digitalWrite(tr, LOW);
  
  long duration = pulseIn(ec, HIGH);
  float distance = duration / 58.2;
  float time = distance * 10;
  
  if(distance > 200){
    tone(pp, hz[0], time/2); 
   
  }
  else if(distance > 100){
    tone(pp, hz[1], time/2.5); 
    
  }
  else if(distance > 50){
    tone(pp, hz[2], time/3); 
    
  }
  else if(distance > 10){
    tone(pp, hz[3], time/3.5); 
    
  }
  else {
    tone(pp, hz[4], time/4); 
    
  }
  
	delay(time);
    noTone(pp);  
}













