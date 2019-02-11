/*
 Name:		Temperature.ino
 Created:	1/17/2019 1:12:55 PM
 Author:	student
*/

const int temperaturePin = A1;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	int reading = analogRead(temperaturePin);

	// 센서 값을 섭씨 온도로 변함
	float val = (5.0*reading*100.0) / 1024.0;

	Serial.println(val);

	delay(1000);
  
}
