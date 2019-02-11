#include <Interval.h>
#include <Led.h>
#include <Button.h>

Led red(4);
Led yellow(5);
Led green(6);

Button redBtn(8, []() -> void{red.toggle();});

Interval yelInterval(500, []() -> void{yellow.toggle();});
Button yelBtn(9, []() -> void{
  if(yelInterval.getState()) {
    yellow.off();
    yelInterval.pause();
  } 
  else {
    yelInterval.start();
  }
 });

Button grnBtn(10, []() -> void{green.toggle();});



void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

   redBtn.read([](int v) -> void{red.set(v); });
   yelInterval.check();
   yelBtn.check();
   grnBtn.check();

}
