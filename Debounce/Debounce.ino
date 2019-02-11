const int buttonPin = 2;
const int ledPin = 13;

int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // 측정 지연 시간

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite (ledPin, ledState);

}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);

  if(reading != lastButtonState) {
    lastDebounceTime  = millis();
    }

    // 지연 시간 이내의 변화라면 무시
    if((millis() - lastDebounceTime) > debounceDelay) {
      if (reading != buttonState) {
        buttonState = reading;
        if(buttonState == HIGH) {
          ledState = !ledState;
        }
      }
  }
  digitalWrite(ledPin, ledState);

 lastButtonState:
    lastButtonState = reading;

}
