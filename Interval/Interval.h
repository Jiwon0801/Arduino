#ifndef INTERVAL_H
#define INTERVAL_H

class Interval {
private:
  unsigned long m_interval; // ?œê°„ ê°„ê²©
  unsigned long m_previousMillis; // ë§ˆì?ë§??íƒœ ë³€ê²??œì˜ ?œê°„
  int m_state;
  void (*m_process) ();
  
 public:
  Interval(int interval, void(*process)()); 

  void check();

  int getState() { return m_state; }

  void start() {
	  m_state = 1;
	  m_previousMillis = millis(); // ì¤‘ìš”
  }

  void pause() { m_state = 0; }

  void setInterval(unsigned long interval) {
	  m_interval = interval;
  }
};

#endif
