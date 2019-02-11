// SensorLight.h

#ifndef _SENSORLIGHT_h
#define _SENSORLIGHT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Led.h>
#define NUM 10

class SensorLight
{
 protected:
	 int m_sensorPin;
	 Led m_led;
	 int m_threshold;
	

	 int m_sensorValue[NUM];

	 
	 int m_total = 0;
	 int m_average = 0;
	 int m_Index = 0;

	 
	
 public:
	
	SensorLight(int sensorpin, int ledPin, int threshold);
	void check();
	int getAvg();
	int setBright();
};

//extern SensorLight SensorLight;

#endif

