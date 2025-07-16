#ifndef BUZZERCONTROL_H
#define BUZZERCONTROL_H
#include <Arduino.h>
#include "PIR.h" 
#include "ultrasound.h"
#include <string.h>

const int buzzerPin = 4;

void BuzzerControl_init() {
    pinMode(buzzerPin, OUTPUT); 
    PIR_init();
}

void setBuzzerVolume(int volume) {
    tone(buzzerPin, volume); 
    delay(500);
}
void BuzzerOff(){
    noTone(buzzerPin);
}
void update() {
        int pirState = digitalRead(PIR_signal); 

        char color_name = RGB_check();

        
        if (pirState == HIGH && color_name=='R') { 
            Serial.println("위험");
            setBuzzerVolume(HIGH);
        } else {
            noTone(buzzerPin);
            
        }
    
    
}
#endif
