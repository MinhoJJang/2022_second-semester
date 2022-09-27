// countdown timer

int LED[] = {2, 3, 4, 5, 6, 7, 8, 9};

int numArray = 8;

int digitLED[10][8] = {
	{0, 0, 0, 0, 0, 0, 1, 1}, //0
	{1, 0, 0, 1, 1, 1, 1, 1}, //1
	{0, 0, 1, 0, 0, 1, 0, 1}, //2
	{0, 0, 0, 0, 1, 1, 0, 1}, //3
	{1, 0, 0, 1, 1, 0, 0, 1}, //4
	{0, 1, 0, 0, 1, 0, 0, 1}, //5
	{0, 1, 0, 0, 0, 0, 0, 1}, //6
	{0, 0, 0, 1, 1, 1, 1, 1}, //7
	{0, 0, 0, 0, 0, 0, 0, 1}, //8
	{0, 0, 0, 0, 1, 0, 0, 1}  //9
  
};

void setup() {
	for (int i = 0 ; i < numArray ; i++) {
		pinMode(LED[i], OUTPUT);
	}
}

void loop() {
	
	for (int i=9; i>=0; i--) {
		
		for (int j = 0 ; j < numArray ; j++) {
			digitalWrite(LED[j], digitLED[i][j]);
		}
		
		delay(1000);
	}
}