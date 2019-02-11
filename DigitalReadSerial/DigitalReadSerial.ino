#include <Led.h>

Led led(3);
int pushButton = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pushButton, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(pushButton);
  if (buttonState){
    led.on();
  }
  else {
    led.off();
  }
  //Serial.println(buttonState);
  //delay(1);
  
}
