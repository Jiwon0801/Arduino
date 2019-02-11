/*
 Name:		UltraSensor.ino
 Created:	2019-01-17 오후 5:40:20
 Author:	student
*/

// the setup function runs once when you press reset or power the board
#include "Ultra.h"
#include <Interval.h>
#define THRESHOLD 50

const int buzzerPin = 4;
Ultra ultra(2, 3);
long dist;

Interval interval(30, []() -> void {
	tone(buzzerPin, 262, dist*2);
});

void setup() {
	pinMode(buzzerPin, OUTPUT);
	Serial.begin(9600);
	interval.start();
}

// the loop function runs over and over again until power down or reset
void loop() {

	dist = ultra.getDistance();

	if (dist > THRESHOLD)
		digitalWrite(buzzerPin, LOW);
	else
		interval.check();

	Serial.print(dist);
	Serial.println(" cm");
 
}
