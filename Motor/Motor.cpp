// 
// 
// 

#include "Motor.h"


Motor::Motor(int ma1, int ma2, int mas, int mb1, int mb2, int mbs) : 
		MotorA1(ma1), MotorA2(ma2), MotorAS(mas), MotorB1(mb1), MotorB2(mb2), MotorBS(mbs)
									
{
	pinMode(ma1, OUTPUT);
	pinMode(ma2, OUTPUT);
	pinMode(mas, OUTPUT);
	pinMode(mb1, OUTPUT);
	pinMode(mb2, OUTPUT);
	pinMode(mbs, OUTPUT);

}

void Motor::forward(int speed)
{
	digitalWrite(MotorA1, LOW);
	digitalWrite(MotorA2, HIGH);
	analogWrite(MotorAS, speed);
	digitalWrite(MotorB1, LOW);
	digitalWrite(MotorB2, HIGH);
	analogWrite(MotorBS, speed);
}

void Motor::back(int speed)
{
	digitalWrite(MotorA1, HIGH);
	digitalWrite(MotorA2, LOW);
	analogWrite(MotorAS, speed);
	digitalWrite(MotorB1, HIGH);
	digitalWrite(MotorB2, LOW);
	analogWrite(MotorBS, speed);
}

void Motor::turnLeft(int speed)
{
	digitalWrite(MotorA1, HIGH);
	digitalWrite(MotorA2, LOW);
	analogWrite(MotorAS, speed);
	digitalWrite(MotorB1, LOW);
	digitalWrite(MotorB2, HIGH);
	analogWrite(MotorBS, speed);
}

void Motor::turnRight(int speed)
{
	digitalWrite(MotorA1, LOW);
	digitalWrite(MotorA2, HIGH);
	analogWrite(MotorAS, speed);
	digitalWrite(MotorB1, HIGH);
	digitalWrite(MotorB2, LOW);
	analogWrite(MotorBS, speed);
}

void Motor::stop()
{
	digitalWrite(MotorA1, LOW);
	digitalWrite(MotorA2, LOW);
	analogWrite(MotorAS, 0);
	digitalWrite(MotorB1, LOW);
	digitalWrite(MotorB2, LOW);
	analogWrite(MotorBS, 0);

}



