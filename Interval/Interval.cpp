#include <Arduino.h>
#include "interval.h"

Interval:: Interval(int interval, void(*process)()) {
  m_interval = interval;
  m_process = process;
  m_previousMillis = 0;
  m_state = 0;
}

void Interval :: check() {

	if (m_state) {
		unsigned long currentMillis = millis();
		if (currentMillis - m_previousMillis >= m_interval) {
			m_previousMillis = currentMillis;
			if (m_process) m_process();
		}

	}
  
}
