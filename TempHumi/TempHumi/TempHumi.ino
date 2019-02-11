/*
 Name:		TempHumi.ino
 Created:	2019-01-17 오후 1:43:54
 Author:	student
*/

#include <DHT11.h>

int pin = 5;
DHT11 dht11(pin);
const int illumPin = A0;


// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

char tempStr[10]; // 포인터 배열
char humiStr[10];
char message[256]; // 전송문자 배열

// the loop function runs over and over again until power down or reset
void loop() {
  
	int err;
	float temp, humi, illum;

	delay(2000); // 2초 미만으로 측정하면 안됨

	err=dht11.read(humi, temp);

	if (err == 0) { // 성공

		/*
		//dtostrf (실수 값, 전체 자리수, 소수점 이하 자리수, char *버퍼)
		dtostrf(temp, 3, 2, tempStr);
		dtostrf(humi, 3, 2, humiStr);

		sprintf(message, "temperature: %s  humidity: %s", tempStr, humiStr);

		Serial.println(message);*/

		// String으로
		String tempT(temp);
		String tempH(humi);
		String str = "temparature:" + tempT + " "+ "humidity: " + tempH;

		str.toCharArray(message, str.length());
		Serial.println(message);

		/*
		Serial.print("temperature : ");
		Serial.println(temp);
		Serial.print("humidity : ");
		Serial.println(humi);
		Serial.println();*/
	}
	else {
		Serial.print("ERROR : ");
		Serial.println(err);

	}
}
