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
	 int m_pin; // �� ��ȣ
	 int *m_pMelody; // ��ε� �迭
	 int *m_pDurations; // �� ���� �迭
	 int m_length; // ��ε� �迭 ����
	 int m_state; // ���� ����
	 int m_index; // ���� ���� ��ġ
	 int m_count; // ���� ȸ��

	 // Interval �Ⱦ� ��
	 unsigned long m_interval; // �ð� ����
	 unsigned long m_previousMillis; // ������ ���� ���� ���� �ð�

 public:
	void init();
	Buzzer(int pin, int *pMelody, int *pDuration, int length, int count = ONCE);
	void start();
	int play();
	void stop();
	void mute() { noTone(m_pin); }
	int getState() { return m_state; }
	// Interval �Ⱦ� ��
	void check();
};

//extern Buzzer Buzzer;

#endif

