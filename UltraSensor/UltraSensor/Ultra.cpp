// 
// 
// 

#include "Ultra.h"

void Ultra::init()
{


}

Ultra::Ultra(int trigPin, int echoPin) : m_trigPin(trigPin), m_echoPin(echoPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

long Ultra::getDistance()
{
	digitalWrite(m_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(m_trigPin, LOW);

	//Echo pin
	long duration = pulseIn(m_echoPin, HIGH);
	long distance = duration / 58; // 거리 cm로 변환

	return distance;
}

//Ultra Ultra;

