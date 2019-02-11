/*
 Name:		DigitalDoorlock.ino
 Created:	1/18/2019 1:51:43 PM
 Author:	student
*/

// the setup function runs once when you press reset or power the board
#include <pitches.h>
#include <Buzzer.h>
#include <Button.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <IrConst.h>
#include <boarddefs.h>
#include <Servo.h>

const int irPin = 11;
const int ledPin = 9;
const int servoMoterPin = 9;

decode_results results;

IRrecv irrecv(irPin);
Servo servoMotor;

const int NUMBER_COUNT = 10; // 번호 IR 매핑 배열 요소 수
const int PW_COUNT = 6; // 비밀번호 길이

int myPassword[PW_COUNT] = { 2,3,4,5 ,6,7}; // 비밀번호 배열
int password[PW_COUNT]; //사용자 입력 비밀번호 배열
int inputIndex = 0; // 현재 비밀번호 입력 인덱스

int numbers[NUMBER_COUNT] = {
	IR_0, IR_1, IR_2, IR_3, IR_4,
	IR_5, IR_6, IR_7, IR_8, IR_9
};

int melody[] = {
	NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4,
};

int noteDurations[] = { 4,8,8,4,4,4,4,4 };

Buzzer buzzer(8, melody, noteDurations, 8, LOOP);

//IR 신호 숫자로 변환
// 해당 숫자 리턴, 숫자 아니면 리턴 -1
int getNumber(long code) {
	for (int i = 0; i < NUMBER_COUNT; i++) {
		if (numbers[i] == code) {
			return i;
		}
		return -1;
	}
}

// 입력한 숫자 비밀번호 생성
int makePassword(long code) {
	if (inputIndex >= 0 && inputIndex < PW_COUNT) {
		int number = getNumber(code);
		if (number != -1) {
			password[inputIndex] = number;
			inputIndex++;
			return number;
		}
	}
	return -1;
}

// 비밀번호 확인
// 일치하면 true
// 일치하지 않으면 false 리턴
boolean checkPassword() {
	for (int i = 0; i < PW_COUNT; i++) {
		if (password[i] != myPassword[i])
			return false;
	}
	return true;
}

// 입력완료 여부 확인
// 입력 완료시 true
// 미 완료시 false
boolean isFinish() {
	return inputIndex == PW_COUNT;
}

// 입력 초기화
void reset() {
	inputIndex = 0;
}


void setup() {
	Serial.begin(9600);

	irrecv.enableIRIn();

	irrecv.blink13(true);
	pinMode(ledPin, OUTPUT);

	servoMotor.attach(servoMoterPin);
	servoMotor.write(0);
	delay(1000);
	
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (irrecv.decode(&results)) {
		if (results.value != 0xFFFFFFFF) {
			if (results.value == IR_PLUS ) { // 입력 시작
				digitalWrite(ledPin, HIGH);
				reset();

			}
			else {
				makePassword(results.value); //비밀번호 작성
				if (isFinish()) { // 4자리 완료시
					if (checkPassword()) { // 비밀번호 검사
						//암호 일치

						// 부저 멜로디
						buzzer.start();
						buzzer.check();

						// 서보 모터
						servoMotor.write(0);
						delay(3000);
						servoMotor.write(179);
						delay(3000);
						
					}
					else {
						//암호 불일치
					}
					reset(); //다시 입력 시작
				}
			}
		}
		irrecv.resume();
  }
}
