#include <Arduino.h>
#include "Led.h"

Led ::  Led(int pin, boolean state = LOW) : m_pin(pin) {
  m_state=state;
  pinMode(m_pin, OUTPUT);
  set(m_state);
}

void Led ::setValue(int brightness) { // analog light
	analogWrite(m_pin, brightness);
}

void Led:: on() {
  m_state = HIGH;
  digitalWrite(m_pin, m_state);
}

void Led::off() {
  m_state = LOW;
  digitalWrite(m_pin, m_state);
}

void Led :: set(boolean state) {
  m_state = state;
  digitalWrite(m_pin, m_state);
}

void Led :: toggle() {
  m_state = !m_state;
  digitalWrite(m_pin, m_state);
}
