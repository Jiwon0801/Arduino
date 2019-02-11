// Ultra.h

#ifndef _ULTRA_h
#define _ULTRA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Ultra
{
 protected:
	 int m_trigPin;
	 int m_echoPin;

 public:
	 void init();
	 Ultra(int trigPin, int echoPin);
	 long getDistance();
};

// extern Ultra Ultra;

#endif

