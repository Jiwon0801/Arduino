/*
 Name:		JsonEx.ino
 Created:	2019-01-24 오전 10:21:28
 Author:	student
*/

// the setup function runs once when you press reset or power the board

#include "JsonUtil.h"
#include <ArduinoJson.h>


void setup() {

	Serial.begin(9600);

}

String sendValues() {

	String msg = jsonEnc([](JsonObject &root) -> void {
		root["name"] = "temp";
		root["value"] = 10.1;
	});

	return msg;

}

void receiveValues(String msg) {
	jsonDec(msg, [](JsonObject &root) -> void {
		String name = root["name"];
		float value = root["value"];

		Serial.print(name);
		Serial.print(":");
		Serial.println(value);
	});
}

String sendArrayValues() {
	
	String msg = jsonEncArr(3, [](int ix, JsonObject &element) -> void {
		switch (ix) {
		case 0:
			element["name"] = "temp";
			element["value"] = 10.1;
			break;
		case 1:
			element["name"] = "humi";
			element["value"] = 20.5;
			break;
		case 2:
			element["name"] = "illum";
			element["value"] = 80;
			break;

		}	
	});
	return msg;
}

String receiveArrayValues(String msg) {
	jsonDecArr(msg, [](int ix, JsonObject &element) -> void {

		String name = element["name"];
		float value = element["value"];
		Serial.print(name);
		Serial.print(":");
		Serial.println(value);

	});

}

// the loop function runs over and over again until power down or reset
void loop() {
	/*
	String jsondata = jsonEnc("temp", 10.2);
	Serial.println(jsondata);

	delay(1000);

	jsonDec(jsondata);
	delay(1000);
	*/

	
	// 단일 객체 처리
	/*String msg = sendValues();
	delay(1000);
	receiveValues(msg);
	delay(1000);*/

	// 배열 객체 처리
	String msg = sendArrayValues();
	Serial.println(msg);
	delay(1000);
	receiveArrayValues(msg);
	delay(1000);


}
