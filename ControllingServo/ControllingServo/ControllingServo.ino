/*
 Name:		ControllingServo.ino
 Created:	2019-01-18 오전 11:11:37
 Author:	student
*/

// the setup function runs once when you press reset or power the board
#include <Button.h>
#include <Servo.h>

Servo servoMotor;
const int servoMotorPin = 3;
int potPin = A0;
int val;
int angle;

Button openBtn(5, []()->void {
	servoMotor.write(0);
});

Button closeBtn(6, []()->void {
	servoMotor.write(179);

});

void setup() {
	servoMotor.attach(servoMotorPin);
	servoMotor.write(0);
	delay(15);
}

// the loop function runs over and over again until power down or reset
void loop() {

	
	/*val = analogRead(potPin);
	val = map(val, 0, 1023, 0, 255);

	servoMotor.write(val);
	delay(15);

	/*
	for (angle = 0; angle <= 179; angle++) {
		servoMotor.write(angle);
		delay(10);
  }
	delay(100);

	for (angle = 179; angle >= 0; angle--) {
		servoMotor.write(angle);
		delay(10);
	}
	delay(100);
	*/
	openBtn.check();
	closeBtn.check();
}
