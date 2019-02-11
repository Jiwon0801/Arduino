/*
 Name:		Digital_Doorlock.ino
 Created:	2019-01-18 오후 2:56:54
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

//#include <pitches.h>
//#include <Buzzer.h>

const int irPin = 11;
Led green(9);
Led red(7);

decode_results results;

IRrecv irrecv(irPin);
Servo servoMotor;

const int servoMotorPin = 3;
const int NUMBER_COUNT = 10; // 번호 IR 매핑 배열 요소 수
const int PW_COUNT = 4; // 비밀번호 길이

int myPassword[PW_COUNT] = { 2,3,4,5}; // 비밀번호 배열
int password[PW_COUNT]; //사용자 입력 비밀번호 배열
int inputIndex = 0; // 현재 비밀번호 입력 인덱스

long numbers[NUMBER_COUNT] = {
	IR_0, IR_1, IR_2, IR_3, IR_4,
	IR_5, IR_6, IR_7, IR_8, IR_9
};


/////////////// 비밀 번호 /////////////////
//IR 신호 숫자로 변환
// 해당 숫자 리턴, 숫자 아니면 리턴 -1
int getNumber(long code) {
	for (int i = 0; i < NUMBER_COUNT; i++) {
		if (numbers[i] == code) {
			return i;
		}
	}
	return -1;
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

	//리모컨
	irrecv.enableIRIn();

	//서보 모터
	servoMotor.attach(servoMotorPin);
	servoMotor.write(0);
	delay(1000);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (irrecv.decode(&results)) {
		if (results.value != 0xFFFFFFFF) {

			if (results.value == IR_MINUS) {
				servoMotor.write(0);
				//delay(3000);
				Serial.println("도어락이 초기화 됐습니다.");

			}

			if (results.value == IR_PLUS) { // 입력 시작
				Serial.println("--------비밀번호 4자리를 입력하시오.----------");
				reset();
				//green.off();
				//red.off();

				
			}
			else if(results.value == IR_EQ) {
												
					if (isFinish()) { // 4자리 완료시

						if (checkPassword()) { // 비밀번호 검사
							//암호 일치
							Serial.println("암호가 일치합니다.");
							green.on();
							delay(3000);
							green.off();

							

							servoMotor.write(179);
							delay(3000);
						}
						else {
							//암호 불일치
							Serial.println("암호가 불일치합니다.");
							red.on();
							delay(3000);
							red.off();
						}
						reset(); //다시 입력 시작

					}
					else 
					{
						Serial.println(" 암호 자리수가 일치하지 않습니다.");
						red.on();
					}
					
				
			}
			else {
				int mp = makePassword(results.value); //비밀번호 작성
				
				Serial.println(mp);
			}

			
		}
		
		irrecv.resume();
	}
  
}
