/*
 Name:		Melody.ino
 Created:	2019-01-16 오후 2:17:26
 Author:	student
*/

#include "Buzzer.h"
#include <Button.h>
#include "pitches.h"
#include <Interval.h>

int melody[] = {
	NOTE_G3, NOTE_G3, NOTE_E3, NOTE_F3, NOTE_G3, 0, NOTE_A3, NOTE_A3, NOTE_G3,
};

int noteDurations[] = { 4,4,8,8,8,4,4,4,4 };

Buzzer buzzer(8, melody, noteDurations, 8, LOOP);

Interval interval(0, []() -> void {
	buzzer.mute();
	int duration = buzzer.play();
	interval.setInterval(duration*1.3);
});

Button melBtn(10, []() -> void {
	if (buzzer.getState()) {
		buzzer.mute();
		buzzer.stop();
	}
	else {
		buzzer.start();
		
	}
});

// the setup function runs once when you press reset or power the board
void setup() {
}

// the loop function runs over and over again until power down or reset
void loop() {
	
	melBtn.check();
	//interval.check();
	buzzer.check();
}
