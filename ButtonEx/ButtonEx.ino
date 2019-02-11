#include <Button.h>
#include <Led.h>

Led led(13);

//Button btn(2, []()->void{led.toggle();});

void click() { led.toggle();}
Button btn(2, click);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
   btn.check();

  //int value = btn.read();
  //led.set(value);

}
