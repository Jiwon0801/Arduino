#ifndef LED_H
#define LED_H

class Led {
private:
  const int m_pin; // ?λ²νΈ
  boolean m_state; // LED??ON/OFF ?ν

public:
  Led(int pin, boolean state=LOW);
  void setValue(int brightness);
  void on();
  void off();
  void set(boolean state);
  void toggle(); // ?μ¬ ?νλ₯?λ°μ ?μΌ μΆλ ₯??
  boolean getState() {
  return m_state; // ?μ¬ ?ν λ°ν
  }
};

#endif
