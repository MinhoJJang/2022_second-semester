// C++ code
//
void setup()
{

}


  

void loop()
{
  
  int red = 0;
int blue = 255;

  for(int i=0; i<=255; i+= 17){
   
  analogWrite(11, red); 
  analogWrite(10, blue); 
     red += 17;
    blue -= 17;
 	delay(100);
  }
  
 
  red = 255;
  blue = 0;
  
  for(int i=0; i<=255; i+= 17){
    
  analogWrite(11, red); 
  analogWrite(10, blue); 
red -= 17;
    blue += 17;
delay(100);
  }
  
}