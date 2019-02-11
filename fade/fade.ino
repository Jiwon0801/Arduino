#include <Led.h>
#include <Interval.h>

Led leds[] = {Led(3), Led(5), Led(9) };


int currentLed = 0; // 현재 작업 LED 인덱스
int brightness = 0; // 밝기
int fadeAmount = 5; // 밝기 조정 간격

inline void updateBrightness() {
  brightness = brightness + fadeAmount;
  if(brightness <=0 || brightness >=255) {
    fadeAmount = -fadeAmount;
    }
   if (brightness ==0){
    leds[currentLed].setValue(0);
    currentLed = (currentLed+1)%3;
   }
}

Interval interval (30, []() -> void {
  
  leds[currentLed].setValue(brightness);
  updateBrightness();
});



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 interval.check();


}
