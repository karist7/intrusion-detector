#include "ultrasound.h"
#include "BuzzerControl.h"
const int buttonPin = 2;

int lastButtonReading = HIGH;
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50;
int pressCount = 0;
bool flag = false;

void readButton() {
         
  int currentReading = digitalRead(buttonPin);
  if (currentReading != lastButtonReading) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentReading != buttonState) {
      buttonState = currentReading;  
      if (buttonState == LOW) {
        flag = !flag;
        Serial.println(flag);
      }
    }
  }
  lastButtonReading = currentReading;
 
}

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  ultrasound_init();
  Serial.begin(115200);
  BuzzerControl_init();

}

void loop() {
  
  readButton();
  if(flag) {
    update();
  }
  else{
   
    BuzzerOff();
    PIR_OFF();
    ultrasound_off();
  }
  delay(10);
}
  