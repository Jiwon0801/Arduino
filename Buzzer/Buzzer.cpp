// 
// 
// 

#include "Buzzer.h"

Buzzer::Buzzer(int pin, int * pMelody, int * pDuration, 
			int length, int count) 
	: m_pin(pin)
{
	m_pMelody = pMelody;
	m_pDurations = pDuration;
	m_length = length;
	m_state = 0;
	m_index = 0;
	m_count = count;

	m_previousMillis = 0;
	m_interval = 0;
}

int Buzzer::start()
{
	m_state = 1;
	m_index = 0;
	m_interval = 0;
	m_previousMillis = millis();
	return play();
}

void Buzzer::stop()
{
	m_state = 0;
	noTone(m_pin);		// ¸á·Îµð ¸ØÃã
}

int Buzzer::play()
{
	if (m_state == 0) return;

	m_interval = 1000 / m_pDurations[m_index];
	tone(m_pin, m_pMelody[m_index], m_interval);

	m_index++;
	if (m_index == m_length) {	// ÇÑ °î ¿¬ÁÖ ³¡
		if (m_count == ONCE) {
			m_index = -1;
			m_state = 0;
		}
		else {
			m_index = 0;
		}
	}
	   
	return m_interval;
}


// IntervalÀ» »ç¿ëÇÏÁö ¾Ê´Â °æ¿ì 
void Buzzer::check() {
	if (!m_state) return;  

	unsigned long currentMillis = millis();
	if (currentMillis - m_previousMillis >= m_interval) {
		m_previousMillis = currentMillis;
		m_interval = play() * 1.3;
	}
}
