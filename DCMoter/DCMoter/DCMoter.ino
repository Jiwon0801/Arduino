/*
 Name:		DCMoter.ino
 Created:	2019-01-21 오후 2:50:03
 Author:	student
*/

#include "Bluetooth.h"
#include "Motor.h"


//SoftwareSerial BTSerial(2, 3); // SoftwareSerial(Rx, Tx)

String myString = ""; // 받는 문자열


Motor motor(9, 8, 10, 7, 6, 5);

Bluetooth BTSerial(2, 3, 9600);


// the setup function runs once when you press reset or power the board
void setup() {

	BTSerial.begin(9600);
	 

	//pinMode(13, OUTPUT);

	//motor.forward();
	//delay(2000);

}




// the loop function runs over and over again until power down or reset
void loop() {
	String message = BTSerial.readLine();


	// 13번 led
	if (message != "") {
		if (message == "on") {
			digitalWrite(13, HIGH);
			BTSerial.println("LED ON");
		}
		else if (message == "off") {
			digitalWrite(13, LOW);
			BTSerial.println("LED OFF");
		}Serial.println(message);
		
	}	

	// 방향 제어
	if (message != "") {
		if (message == "go") {
			motor.forward(255);
			
			
		}
		else if (message == "back") {
			motor.back(255);
			

		}
		else if (message == "left") {
			motor.turnLeft(255);
			
			
		}
		else if (message == "right") {
			motor.turnRight(255);
			

		}
		else if (message == "stop") {
			motor.stop();
		}

	}

	/*
	while (BTSerial.available()) { // BTSerial에 전송된 값이 있으면

		//BTSerial int 값을 char 형식으로 변환
		char myChar = (char)BTSerial.read();

		// 수신되는 문자를 myString에 모두 붙임
		myString += myChar;
		delay(5);

	}

	if (!myString.equals("")) { // myString 값이 있다면

		Serial.println("input value: " + myString);
		BTSerial.println("input value: " + myString);
		myString = ""; //myString 변수값 초기화
	}

	// 중계
	if (BTSerial.available()) {
		Serial.write(BTSerial.read()); // 블루투스 측 내용을 시리얼 모니터에 출력
	}

	if (Serial.available()) {
		BTSerial.write(Serial.read()); // 시리얼 모니터 내용을 블루투스 측에 출력
	}
	*/

}
