https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sisosw&logNo=221466848808

#include<Servo.h>   //서브모터 헤더파일

Servo motor;

int motorDegree = 150;  //서브모터의 위치 저장 변수

int trig = 8;
int echo = 9;

void setup(){
    motor.attach(9);
    motor.write(150);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

void loop(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  float duration = pulseIn(echo, HIGH); //echo 핀이 HIGH를 유지한 시간. 즉, 초음파를 보냈다가 다시 돌아온 시간

  float distance = duration / 58.8

  if(5 < distance && distance < 20){
    for(int i = 0; i < 20; i++){    //20도 까지만 서보모터를 움직여라
      motorDegree++;
    }
    delay(1000);
    for(int i = 0; i < 20; i++){
      motorDegree--;
    }
  }
}
