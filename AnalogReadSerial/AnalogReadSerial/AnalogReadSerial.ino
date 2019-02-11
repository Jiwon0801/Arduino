/*
 Name:		AnalogReadSerial.ino
 Created:	2019-01-17 오전 9:30:49
 Author:	student
*/
#include <Led.h>

Led led(5);

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(9600);
	
}

// the loop function runs over and over again until power down or reset
void loop() {

	int sensorValue = analogRead(A0);
	// 구간 재 측정 비율  (측정값, 입력 값 범위1, 범위2, 재해석 구간1, 재해석 구간2)
	int val = map(sensorValue, 0, 1023, 0, 255);

	led.setValue(val);

	//Serial.println(sensorValue);
	delay(1);
  
}
