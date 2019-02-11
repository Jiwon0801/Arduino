/*
 Name:		Tracking.ino
 Created:	1/17/2019 2:46:19 PM
 Author:	student
*/

#include <Led.h>

Led led(12);

const int trackPin;


// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(trackPin, INPUT);
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {

	int val = digitalRead(trackPin);


	if (!val) {
		led.on();
	}
	else
		led.off();
}
