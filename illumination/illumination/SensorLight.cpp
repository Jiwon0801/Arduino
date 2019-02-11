// 
// 
// 

#include "SensorLight.h"
#include <Led.h>



//SensorLight SensorLight;

int SensorLight::setBright()
{
	int sensorValue = getAvg();

	if (sensorValue < m_threshold) {
		int brightness = map(sensorValue, 300, m_threshold, 255, 0);
		m_led.setValue(brightness);
	}
	else
		m_led.off();
}

int SensorLight::getAvg()
{
	//int value = analogRead(m_sensorPin);

	m_total -= m_sensorValue[m_Index];
	m_sensorValue[m_Index] = analogRead(m_sensorPin);
	m_total += m_sensorValue[m_Index];

	m_Index = ++m_Index % NUM;

	m_average = m_total / NUM;

	return m_average;

}

SensorLight::SensorLight(int sensorpin, int ledPin, int threshold) : m_led(ledPin)
{
	m_sensorPin = sensorpin;
	m_threshold = threshold;
}

void SensorLight::check()
{
	int sensorValue = getAvg();
	
	/*int sensorValue = analogRead(m_sensorPin);
	Serial.println(sensorValue);*/

	if (sensorValue < m_threshold) 
		m_led.on();
	else
		m_led.off();

}
