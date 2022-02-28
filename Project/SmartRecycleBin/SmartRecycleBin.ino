#include<Servo.h>   //서브모터 헤더파일

Servo motor;

int motorDegree = 0;  //서브모터의 위치 저장 변수

int echo = 7;
int trig = 8;


void setup(){
    motor.attach(9);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

void loop(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH); //echo 핀이 HIGH를 유지한 시간. 즉, 초음파를 보냈다가 다시 돌아온 시간

  float distance = duration / 58.8;

  if(distance < 10){
    for(int i = 0; i < 30; i++){
      motorDegree += 2;
      motor.write(motorDegree);
      delay(10);
    }
    delay(2000);
    for(int i = 0; i < 30; i++){
      motorDegree -= 2;
      motor.write(motorDegree);
      delay(10);
    }
  }
  delay(50);
}
