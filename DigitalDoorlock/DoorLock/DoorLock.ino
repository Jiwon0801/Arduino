/*
 Name:		DoorLock.ino
 Created:	2019-01-18 오후 5:54:13
 Author:	student
*/

// the setup function runs once when you press reset or power the board
#include <Led.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <IrConst.h>
#include <boarddefs.h>
#include <Servo.h>
#define DOOROPEN 179
#define DOORCLOSE 0



const int MotorPin = 3;
const int irPin = 11;
int buzzerPin = 3;
Led green(9);
Led red(7);

String password = "12345";
String passwordBuf;

IRrecv irrecv(irPin);
Servo servo;
decode_results results;

int startFlag = 0;

String pw(long code) {
	String pw = "";
	switch (code)
	{
	case IR_0: pw = "0"; break;
	case IR_1: pw = "1"; break;
	case IR_2: pw = "2"; break;
	case IR_3: pw = "3"; break;
	case IR_4: pw = "4"; break;
	case IR_5: pw = "5"; break;
	case IR_6: pw = "6"; break;
	case IR_7: pw = "7"; break;
	case IR_8: pw = "8"; break;
	case IR_9: pw = "9"; break;

	default: pw = "*";
	}
	return pw;
}

void success(){
	servo.write(DOOROPEN);
	green.on();
	digitalWrite(buzzerPin, HIGH);
	delay(3000);
	servo.write(DOORCLOSE);
	green.off();
	digitalWrite(buzzerPin, LOW);
}


void fail() {
	red.on();
	delay(3000);
	red.off();
}
void setup() {
	Serial.begin(9600);
	//리모컨
	irrecv.enableIRIn();

	irrecv.blink13(true);
	pinMode(buzzerPin, OUTPUT);
	servo.attach(MotorPin);
	servo.write(DOORCLOSE);
	delay(1000);
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (irrecv.decode(&results)) {
		if (results.value != 0xFFFFFFFF) {

			if (results.value == IR_PLUS) {
				Serial.println("--------비밀번호 4자리를 입력하시오.----------");
				startFlag = 1;
				passwordBuf = "";
			}
			else {
				if (results.value == IR_EQ) {
					startFlag = 0;
					if (password.equals(passwordBuf)) {
						Serial.println("Success");
						success();
					}
					else {
						Serial.println("Fail");
						fail();
					}


				}
				else {
					if (startFlag) {
						String temp = pw(results.value);
						passwordBuf += temp;
						Serial.println(temp);
					}
				}
		
			}
			if (results.value == IR_MINUS) {
				if (servo.read() == DOOROPEN) {
					servo.write(DOORCLOSE);
				}
			}
			
				
		}
		irrecv.resume();
	}
  
}
