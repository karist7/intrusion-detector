#ifndef ULTRASOUND_H
#define ULTRASOUND_H

const int trig_pin = 6;
const int echo_pin = 7;
const int RED = 8;
const int GREEN = 9;
const int BLUE = 10;
//char* color= "none";
char color;
void ultrasound_init(){
  
    pinMode(trig_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
    pinMode(RED,OUTPUT);
    pinMode(BLUE,OUTPUT);
    pinMode(GREEN,OUTPUT);
}
void ultrasound_off() {
    digitalWrite(trig_pin, LOW);  // 초음파 신호 끄기
    digitalWrite(echo_pin,LOW);
    digitalWrite(RED, LOW);       // LED 꺼짐
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
}

char RGB_check(){
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin,LOW);
  
    long duration = pulseIn(echo_pin,HIGH);
    long distance = duration/58.2;
    //Serial.println(distance);

    digitalWrite(RED,LOW);
    digitalWrite(BLUE,LOW);
    digitalWrite(GREEN,LOW);
    if(distance<10){
        digitalWrite(RED,HIGH);
        color='R';
        return color;

    }
    else if(distance<30){
        digitalWrite(GREEN,HIGH);
        digitalWrite(RED,HIGH);
        color='Y';
        return color;
    }
    else{
        digitalWrite(GREEN,HIGH);
        color='G';
        return color;
        
    }
    //delay(500);

}

#endif
