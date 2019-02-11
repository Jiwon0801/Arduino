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

const int NUMBER_COUNT = 10; // ��ȣ IR ���� �迭 ��� ��
const int PW_COUNT = 6; // ��й�ȣ ����

int myPassword[PW_COUNT] = { 2,3,4,5 ,6,7}; // ��й�ȣ �迭
int password[PW_COUNT]; //����� �Է� ��й�ȣ �迭
int inputIndex = 0; // ���� ��й�ȣ �Է� �ε���

int numbers[NUMBER_COUNT] = {
	IR_0, IR_1, IR_2, IR_3, IR_4,
	IR_5, IR_6, IR_7, IR_8, IR_9
};

int melody[] = {
	NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4,
};

int noteDurations[] = { 4,8,8,4,4,4,4,4 };

Buzzer buzzer(8, melody, noteDurations, 8, LOOP);

//IR ��ȣ ���ڷ� ��ȯ
// �ش� ���� ����, ���� �ƴϸ� ���� -1
int getNumber(long code) {
	for (int i = 0; i < NUMBER_COUNT; i++) {
		if (numbers[i] == code) {
			return i;
		}
		return -1;
	}
}

// �Է��� ���� ��й�ȣ ����
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

// ��й�ȣ Ȯ��
// ��ġ�ϸ� true
// ��ġ���� ������ false ����
boolean checkPassword() {
	for (int i = 0; i < PW_COUNT; i++) {
		if (password[i] != myPassword[i])
			return false;
	}
	return true;
}

// �Է¿Ϸ� ���� Ȯ��
// �Է� �Ϸ�� true
// �� �Ϸ�� false
boolean isFinish() {
	return inputIndex == PW_COUNT;
}

// �Է� �ʱ�ȭ
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
			if (results.value == IR_PLUS ) { // �Է� ����
				digitalWrite(ledPin, HIGH);
				reset();

			}
			else {
				makePassword(results.value); //��й�ȣ �ۼ�
				if (isFinish()) { // 4�ڸ� �Ϸ��
					if (checkPassword()) { // ��й�ȣ �˻�
						//��ȣ ��ġ

						// ���� ��ε�
						buzzer.start();
						buzzer.check();

						// ���� ����
						servoMotor.write(0);
						delay(3000);
						servoMotor.write(179);
						delay(3000);
						
					}
					else {
						//��ȣ ����ġ
					}
					reset(); //�ٽ� �Է� ����
				}
			}
		}
		irrecv.resume();
  }
}
