/*
 Name:		EchoClient.ino
 Created:	2019-01-23 오후 1:17:27
 Author:	student
*/

// the setup function runs once when you press reset or power the board


#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include "WiFiUtil.h"

SoftwareSerial softSerial(2, 3); // RX, TX

char ssid[] = "MULTI_GUEST";
char password[] = "guest1357";

char server[] = "70.12.112.137";

// WiFi client 초기화
WiFiEspClient client;

void setup() {
	wifi_init(ssid, password);
}

// the loop function runs over and over again until power down or reset
void loop() {

	Serial.println();
	Serial.println("Starting connection to server...");
	// Echo 서버 연결
	if (client.connect(server, 20000))
	{
		Serial.println("Connected to server");
		client.println("Hello World"); // 메시지 전송
		Serial.println("Send message : Hello World"); 
	} 
	// 메시지 수신 
	while (client.available()) {
		char c = client.read();
		Serial.write(c); 
	}

	client.stop();
	delay(3000);
  
}
