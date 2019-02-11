// Buzzer.h

#ifndef _BUZZER_h
#define _BUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

const int LOOP=0;
const int ONCE = 1;

class Buzzer
{
 protected:
	 int m_pin;			// 핀 번호
	 int *m_pMelody;	// 멜로디 배열
	 int *m_pDurations;	// 음 길이 배열
	 int m_length;		// 멜로디 배열 길이
	 int m_state;		// 연주 상태 
	 int m_index;		// 다음 연주 위치
	 int m_count;		// 연주 회수 

	 // Interval을 안쓰는 경우 
	 unsigned long m_previousMillis;
	 unsigned long m_interval;

public:
	Buzzer(int pin, int *pMelody, int *pDuration, int length, 
			int count=ONCE);
	int start();	// 연주 시작 - 첫 음 재생하고, 대기 시간 리턴
	int play();		// 음 하나 재생, 대기 시간 리턴
	void stop();	// 연주 멈춤
	void mute() { noTone(m_pin); }	// 음 재생 정지
	int getState() { return m_state; }
	// Interval을 안쓰는 경우 
	void check();
};



#endif

