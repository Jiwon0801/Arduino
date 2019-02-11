/*
 Name:		illumination.ino
 Created:	1/17/2019 10:25:50 AM
 Author:	student
*/
#include "SensorLight.h"
#include <Led.h>


SensorLight sl(A1, 5, 750);

/*
Led led(5);
int brightness = 0;

int photoRegistorValue;
int photoRegistorPin = A1;*/


// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	

	//sl.check();
	sl.setBright();

	

	
}
