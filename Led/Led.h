#ifndef LED_H
#define LED_H

class Led {
private:
  const int m_pin; // ?€ë²ˆí˜¸
  boolean m_state; // LED??ON/OFF ?íƒœ

public:
  Led(int pin, boolean state=LOW);
  void setValue(int brightness);
  void on();
  void off();
  void set(boolean state);
  void toggle(); // ?„ì¬ ?íƒœë¥?ë°˜ì „?œì¼œ ì¶œë ¥??
  boolean getState() {
  return m_state; // ?„ì¬ ?íƒœ ë°˜í™˜
  }
};

#endif
