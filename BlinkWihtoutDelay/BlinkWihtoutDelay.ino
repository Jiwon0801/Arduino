#include <Led.h>

//#include "Led.h"

Led led(LED_BUILTIN);

unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    led.toggle();
  }

}
