#include<Servo.h>   //서브모터 헤더파일
Servo LeftRightMotor;  //서브모터 좌우 클래스 선언
Servo UpDownMotor;     //서브모터 상하 클래스 선언

int LeftRightWidth = 90;      //좌우 서브모터 각도 초기값
int UpDownWidth = 140;         //상하 서브모터 각도 초기값

int xDegree;   //조이스틱 x축(좌우) 값 저장하는 변수
int yDegree;   //조이스틱 y축(상하) 값 저장하는 변수


void setup(){
    LeftRightMotor.attach(9);
    UpDownMotor.attach(10);   
    LeftRightMotor.write(90); //좌우 서브모터 최초각도 설정
    UpDownMotor.write(140);    //상하 서브모터 최초각도 설정
}

void loop(){
  int xSum = 0;  //조이스틱 x축(좌우) 각도 조정 변수
  int ySum = 0;  //조이스틱 y축(상하) 각도 조정 변수

  for(int i = 0; i < 20; i++){    //아날로그 값을 추출하여 오차
    xDegree = analogRead(A0);
    yDegree = analogRead(A1);
    xSum += xDegree;
    ySum += yDegree;
  }
   xDegree = xSum / 20;
   yDegree = ySum / 20;

  if(xDegree >= 0 && xDegree < 350){
    if(LeftRightWidth >= 0){LeftRightWidth--;}
    else if(LeftRightWidth == 0){}
  }
  else if(xDegree > 650 && xDegree < 1023){
    if(LeftRightWidth <= 180){LeftRightWidth++;}
    else if(LeftRightWidth == 180){}
  }
  LeftRightMotor.write(LeftRightWidth);   //계산된 각도 입력
  
  if(yDegree >= 0 && yDegree < 350){
    if(UpDownWidth <= 180){UpDownWidth++;}
    else if(UpDownWidth == 180){}
  }
  else if(yDegree > 650 && yDegree < 1023){
    if(UpDownWidth >= 130){UpDownWidth--;}
    else if(UpDownWidth == 130){}
  }
  UpDownMotor.write(UpDownWidth);
}
