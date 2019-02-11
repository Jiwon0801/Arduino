/*
 Name:		wifi_at.ino
 Created:	2019-01-23 오전 11:30:10
 Author:	student
*/

#include <SoftwareSerial.h>
#define BT_RXD 2
#define BT_TXD 3

SoftwareSerial ESP_wifi(BT_RXD, BT_TXD);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	ESP_wifi.begin(9600); // 펌웨어 초기 설정 115200, 추후 9600
	ESP_wifi.setTimeout(5000);
	delay(1000);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (Serial.available()) {
		ESP_wifi.write(Serial.read());
	}
	if (ESP_wifi.available()) {
		Serial.write(ESP_wifi.read());
	}
  
}
