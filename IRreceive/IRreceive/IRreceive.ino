/*
 Name:		IRreceive.ino
 Created:	2019-01-18 오전 9:38:23
 Author:	student
*/

// the setup function runs once when you press reset or power the board

#include <pitches.h>
#include <Buzzer.h>
#include <Led.h>
#include <IrConst.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <boarddefs.h>


const int irPin = 11;
const int ledPin = 9;
const int bz = 8;

int ledBright = 0;
int br_step = 30;

IRrecv irrecv(irPin);
decode_results results;


long oldSignal = 0;
long oldCode = 0;

void led_Bright(long code) {
	if (code == IR_PLUS) {
		if (ledBright < 255) {
			ledBright += br_step;
		}
	}
	else if (code == IR_MINUS) {
		if (ledBright > 0) {
			ledBright -= br_step;
		}
	}
}

void sound(long code) {

	int pitch = 0;

	if (code == IR_1) {
		tone(bz, NOTE_C3);
	}
	switch (code)
	{
	case IR_1: pitch = 100; break;
	case IR_2: pitch = NOTE_D3; break;
	case IR_3: pitch = NOTE_E3; break;
	case IR_4: pitch = NOTE_F3; break;
	case IR_5: pitch = NOTE_G3; break;
	case IR_6: pitch = NOTE_A3; break;
	case IR_7: pitch = NOTE_B3; break;
	case IR_8: pitch = NOTE_C4; break;
	case IR_0:
	case IR_9: noTone(bz); return;

	}
	if (pitch != 0) tone(bz, pitch, 250);

}

void setup() {
	Serial.begin(9600);
	// 적외선 리모컨 수신 시작
	irrecv.enableIRIn();
	// 13 번 핀에 연결된 LED
	irrecv.blink13(true);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	if (irrecv.decode(&results)) {
		if (results.value != 0xFFFFFFF) {

			sound(results.value);
			oldCode = results.value;

			if (results.value == IR_PLUS) {
				led_Bright(results.value);
				oldSignal = results.value;

			}
			else if (results.value == IR_MINUS) {
				
				led_Bright(oldSignal);
				
			}

		}
		else {
			sound(oldCode);
		}
		// 다음 수신 준비
		analogWrite(ledPin, ledBright);
		irrecv.resume();

	}
}
