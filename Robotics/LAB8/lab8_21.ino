// LAB8_2

#define pp 13
const int hz[] = {261, 293, 329, 349, 391, 440, 493};


void setup()
{
  for(int i=4; i<11; i++){  
    pinMode(i, INPUT);
  }
}

int readButton(){
 
  while(true){
    for(int i=4; i<11; i++){
      if(digitalRead(i) == HIGH){
        return i-4;
      }
    }
  }
}  
  

void loop()
{
  tone(pp, hz[readButton()], 300);
  delay(300);
  noTone(pp);
}