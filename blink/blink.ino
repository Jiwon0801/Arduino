#include <Interval.h>

#include <Led.h>
#include "Interval.h"


void blink1();
void blink2();
void blink3();

Led led1(2);
Led led2(3);
Led led3(4);

Interval interval1(200, blink1);
Interval interval2(500, blink2);
Interval interval3(1000, blink3);

void blink1() {
  led1.toggle();
}
void blink2() {
  led2.toggle();
}
void blink3() {
  led3.toggle();
}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  interval1.check();
  interval2.check();
  interval3.check();

}
