#ifndef INTERVAL_H
#define INTERVAL_H

class Interval {
private:
  unsigned long m_interval; // ?�간 간격
  unsigned long m_previousMillis; // 마�?�??�태 변�??�의 ?�간
  int m_state;
  void (*m_process) ();
  
 public:
  Interval(int interval, void(*process)()); 

  void check();

  int getState() { return m_state; }

  void start() {
	  m_state = 1;
	  m_previousMillis = millis(); // 중요
  }

  void pause() { m_state = 0; }

  void setInterval(unsigned long interval) {
	  m_interval = interval;
  }
};

#endif
