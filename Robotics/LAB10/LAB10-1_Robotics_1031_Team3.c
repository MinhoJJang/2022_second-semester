
#define LEFT_MOTOR motorA
#define RIGHT_MOTOR motorD
#define ROTATE 450
#define STRAIGHT 500
#define MOTER_POWER 50
#define MAX_LENGTH 20
#define STOP 0

void turnR(){
	motor[LEFT_MOTOR] = +MOTER_POWER; motor[RIGHT_MOTOR] = STOP;
	wait1Msec(ROTATE);
}

void turnL(){
	motor[LEFT_MOTOR] = STOP; motor[RIGHT_MOTOR] = +MOTER_POWER;
	wait1Msec(ROTATE);
}

void goStraight(){
	motor[LEFT_MOTOR] = +MOTER_POWER; motor[RIGHT_MOTOR] = +MOTER_POWER;
	wait1Msec(STRAIGHT);
}

void direction(char dir){

		switch(dir){
		 	case 'R':
		 		turnR();
		 	break;

		 	case 'F':
		 		goStraight();
		 	break;

		 	case 'L':
		 		turnL();
		 	break;

		 	case 'X':
				return;
		 	break;
	}

	playSound(soundBeepBeep);
	sleep(300);
}

task main()
{
   char dir[MAX_LENGTH];
   strcpy(dir, "RFFRFFRFFLFFLFFX");

   int len = strlen(dir);

   for(int i=0; i<len; i++){
  		direction(dir[i]);
   }
}
