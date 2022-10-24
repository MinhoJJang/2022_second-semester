#define LEFT_MOTOR motorA
#define RIGHT_MOTOR motorD
#define ROTATE 700
#define STRAIGHT 650

task main()
{

    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = 0;
    wait1Msec(STRAIGHT);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = 0;
    wait1Msec(STRAIGHT);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = 0;
    wait1Msec(STRAIGHT);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
    motor[LEFT_MOTOR] = -60;
    motor[RIGHT_MOTOR] = +60;
    wait1Msec(STRAIGHT);

    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
    motor[LEFT_MOTOR] = 0;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(STRAIGHT);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
    motor[LEFT_MOTOR] = 0;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(STRAIGHT);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
    motor[LEFT_MOTOR] = 0;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(STRAIGHT);
    motor[LEFT_MOTOR] = +50;
    motor[RIGHT_MOTOR] = +50;
    wait1Msec(ROTATE);
}