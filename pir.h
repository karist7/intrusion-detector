#ifndef PIR_H
#define PIR_H

int PIR_signal=3;   // PIR signal  3번핀 부여
int PIR_value = LOW;   // PIR signal 기본값 LOW
void PIR_init(){    // 메인코드에서 setup() 함수에서 선언할 pinMode 등 함수
  pinMode(PIR_signal,INPUT);
}
void PIR_OFF(){
  PIR_value=LOW;
}

int PIR_active(){    // 루프문에서 선언할 함수
    PIR_value = digitalRead(PIR_signal);
    if(PIR_value==HIGH){
      return 1;
    }
    else{
      return 0;  
    }
}
#endif
