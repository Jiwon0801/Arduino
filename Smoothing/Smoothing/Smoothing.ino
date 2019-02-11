/*
 Name:		Smoothing.ino
 Created:	1/17/2019 10:06:18 AM
 Author:	student
*/

const int numReadings = 10;

int readings[numReadings];
int total = 0;
int readIndex = 0;
int average = 0;

int inputPin = A0;



// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {

	total = total - readings[readIndex];

	readings[readIndex] = analogRead(inputPin);
	total = total + readings[readIndex];

	readIndex = readIndex + 1;
	if (readIndex >= numReadings)
		readIndex = 0;

	average = total / numReadings;
	Serial.println(average);
	delay(1);
  
}
