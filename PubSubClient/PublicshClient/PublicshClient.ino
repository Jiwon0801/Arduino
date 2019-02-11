/*
 Name:		PublicshClient.ino
 Created:	2019-01-25 오전 11:23:52
 Author:	student
*/

// the setup function runs once when you press reset or power the board
#include <WiFiUtil.h>
#include <SoftwareSerial.h>
#include <Interval.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <JsonUtil.h>
#include <DHT11.h>
#include <ArduinoJson.h>

SoftwareSerial softSerial(2, 3);

DHT11 dht11(12);
const int lightPin = A0;

float temp, humi, illum;

char ssid[] = "MULTI_GUEST";
char password[] = "guest1357";
const char mqtt_server[] = "70.12.112.137";


WiFiEspClient espClient;
PubSubClient client(espClient);

void mqtt_init() {
	client.setServer(mqtt_server, 1883);
}

// MQTT 서버에 접속될 때까지 재접속 시도
void reconnect() {
	while (!client.connected()) {
		Serial.print("Attempting MQTT connection...");

		if (client.connect("ESP8266Client")) {
			Serial.println("connected");
			// subscriber로 등록
			client.subscribe("home/livingroom/led");
		}
		else {
			Serial.print("failed, rc=");
			Serial.print(client.state());
			Serial.println(" try again in 5 seconds");
			delay(5000);
		}
	}
}

void publish() {

	illum = analogRead(lightPin);
	dht11.read(humi, temp);

	//센서 값 측정하여 문자열 변환
	//String temp(23.5), humi(80.0), illum(56.0);

	String s_temp(temp), s_humi(humi), s_illum(illum);
	
	client.publish("autocar/livingroom/temp", s_temp.c_str());
	client.publish("autocar/livingroom/humi", s_humi.c_str());
	client.publish("autocar/livingroom/illum", s_illum.c_str());

	
}

// 2초 간격으로 publish
Interval publishTicker(2000, publish);


void setup() {
	wifi_init(ssid, password);
	Serial.begin(9600);
	mqtt_init();

	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
	publishTicker.start();

}

// the loop function runs over and over again until power down or reset
void loop() {

	if (!client.connected()) {
		reconnect();
	}
	client.loop();
	publishTicker.check();

}
