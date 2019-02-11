// Buzzer.h

#ifndef _BUZZER_h
#define _BUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

const int LOOP = 0;
const int ONCE = 1;



class Buzzer
{
 protected:
	 int m_pin; // 핀 번호
	 int *m_pMelody; // 멜로디 배열
	 int *m_pDurations; // 음 길이 배열
	 int m_length; // 멜로디 배열 길이
	 int m_state; // 연주 상태
	 int m_index; // 다음 연주 위치
	 int m_count; // 연주 회수

	 // Interval 안쓸 때
	 unsigned long m_interval; // 시간 간격
	 unsigned long m_previousMillis; // 마지막 상태 변경 시의 시간

 public:
	void init();
	Buzzer(int pin, int *pMelody, int *pDuration, int length, int count = ONCE);
	void start();
	int play();
	void stop();
	void mute() { noTone(m_pin); }
	int getState() { return m_state; }
	// Interval 안쓸 때
	void check();
};

//extern Buzzer Buzzer;

#endif

