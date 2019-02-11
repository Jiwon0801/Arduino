/*
 Name:		SensorClient.ino
 Created:	2019-01-23 오후 2:23:27
 Author:	student
*/



// the setup function runs once when you press reset or power the board

#include <JsonUtil.h>
#include <ArduinoJson.h>
#include <Interval.h>
#include <WiFiUtil.h>
#include <DHT11.h>
#include <WiFiEsp.h>
#include <SoftwareSerial.h>



DHT11 dht11(12);

const int lightPin = A0;


float temp, humi, illum;

const char *sensorType[] = { "temp", "humi", "illum" };




// WiFi
SoftwareSerial softSerial(2, 3); // RX, TX

char ssid[] = "MULTI_GUEST";
char password[] = "guest1357";

char server[] = "70.12.112.137";

// WiFi client 초기화
WiFiEspClient client;

String str = "";


Interval interval(5000, []() -> void {
	
	String msg = readSensors();
	// 센서 값 서버로 전송
	if (client.connect(server, 9002)) {
		client.println(msg);
		client.flush();
		client.stop();
	}
	else {
		Serial.println("Connection Fail");
	}


	Serial.println(msg);
} );

String readSensors() {
	illum = analogRead(lightPin);
	dht11.read(humi, temp);

	String msg = jsonEncArr(3, [](int ix, JsonObject &element) -> void {
		element["sensorType"] = sensorType[ix];
		element["owner"] = "autocar";
		element["place"] = "livingroom";

		switch (ix) {
		case 0:
			element["value"] = temp; break;
		case 1:
			element["value"] = humi; break;
		case 2:
			element["value"] = illum; break;

		}
	});

	return msg;

}


/*
String sendArrayValues() {

	String msg = jsonEncArr(3, [](int ix, JsonObject &element) -> void {
		switch (ix) {
		case 0:
			element["sensorType"] = "temp";
			element["value"] = values[0];
			break;
		case 1:
			element["sensorType"] = "humi";
			element["value"] = values[1];
			break;
		case 2:
			element["sensorType"] = "illum";
			element["value"] = values[2];
			break;
		}
		element["owner"] = "Mike";
		element["place"] = "A";
	});
	return msg;
}
*/

/*
String receiveArrayValues(String msg) {
	jsonDecArr(msg, [](int ix, JsonObject &element) -> void {

		String name = element["sensorType"];
		float value = element["value"];
		Serial.print(name);
		Serial.print(":");
		Serial.println(value);

	});

}*/


void setup() {

	Serial.begin(9600);
	pinMode(lightPin, INPUT);
	interval.start();
	wifi_init(ssid, password);
	
}

// the loop function runs over and over again until power down or reset
void loop() {
	interval.check();

	/*
	if (!str.equals("")) {
		Serial.println();
		Serial.print("Starting connection to server...");
		if (client.connect(server, 10000)) {
			Serial.println("Connected");
			client.println(str);
			Serial.println("Send message: ");
			Serial.println(str);
		}
		client.stop();
		str = "";
	}
	*/
	

}
