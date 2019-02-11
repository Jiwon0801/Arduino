#ifndef LED_H
#define LED_H

class Led {
private:
  const int m_pin; // ?�번호
  boolean m_state; // LED??ON/OFF ?�태

public:
  Led(int pin, boolean state=LOW);
  void setValue(int brightness);
  void on();
  void off();
  void set(boolean state);
  void toggle(); // ?�재 ?�태�?반전?�켜 출력??
  boolean getState() {
  return m_state; // ?�재 ?�태 반환
  }
};

#endif
