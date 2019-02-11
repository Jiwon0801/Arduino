// Motor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Motor
{
 protected:

	 const int MotorA1;
	 const int MotorA2;
	 const int MotorAS;


	 const int MotorB1;
	 const int MotorB2;
	 const int MotorBS;


 public:
	 Motor(int ma1, int ma2, int mas, int mb1, int mb2, int mbs);
	 void forward(int speed = 100);
	 void back(int speed = 100);
	 void turnLeft(int speed = 100);
	 void turnRight(int speed = 100);
	 void stop();

};



#endif

