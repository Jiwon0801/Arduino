/*
 Name:		TrackingMotor.ino
 Created:	2019-01-25 오후 4:10:23
 Author:	student
*/

// the setup function runs once when you press reset or power the board
#include <Motor.h>

Motor motor(9, 8, 10, 7, 6, 5);

const int rightPin = 3;
const int leftPin = 4;

int left_state = 0;
int right_state = 0;

void setup() {

	pinMode(rightPin, INPUT);
	pinMode(leftPin, INPUT);
	Serial.begin(9600);

}

// the loop function runs over and over again until power down or reset
void loop() {

	

	right_state = digitalRead(rightPin);
	left_state = digitalRead(leftPin);

	if (!left_state && !right_state) {
		motor.forward(100);
		
	}
	else if (!left_state && right_state) {

		motor.stop();
		delay(500);
		
		while (true)
		{
			motor.turnRight(220);
			right_state = digitalRead(rightPin);
			left_state = digitalRead(leftPin);

			if (left_state && !right_state)
				break;
		}
		while (true) {
			motor.turnLeft(220);
			right_state = digitalRead(rightPin);
			left_state = digitalRead(leftPin);

			if (!left_state && !right_state)
				break;
		}
		
	}
	else if (left_state && !right_state){
		motor.stop();
		delay(500);

		while (true)
		{
			motor.turnLeft(220);
			right_state = digitalRead(rightPin);
			left_state = digitalRead(leftPin);

			if (!left_state && right_state)
				break;
		}

		while (true) {
			motor.turnRight(220);
			right_state = digitalRead(rightPin);
			left_state = digitalRead(leftPin);

			if (!left_state && !right_state)
				break;
		}
		
	}
	else if (left_state && right_state) {
		
		motor.stop();
		
	}
	
}
