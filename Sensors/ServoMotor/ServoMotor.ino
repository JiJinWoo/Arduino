#include<Servo.h>   //서브모터 헤더파일

//단 아두이노에서 서보모터를 사용하는 동안에는 
//디지털 9, 10번핀에서는 PWM사용(analogWrite())를 사용할 수 없음에 유의하세요!

Servo motor;

int degree = 0;  //서브모터의 위치 저장 변수

int sw = 8;

void setup(){
    pinMode(sw, INPUT_PULLUP);
    motor.attach(9);    // 9번 핀에 연결된 서보모터에 전원 공급
    motor.write(90);    //서보모터가 순간적으로 움직이는것이 아닌 1초 미만의 약간의 텀을두면서 움직이기 
                        //때문에 write() 실행 후 바로 또 다른 write()로 각도를 제어하면 원하는 
                        //동작으로 실행되지 않습니다. 이때는 delay()를 사용하여 충분히 움직일 시간을 
                        //준 다음 write()를 사용하는 것이 좋습니다.
}

void loop(){
    if(digitalRead(sw) == LOW){
        degree += 10;
        if(degree >= 180){
            degree = 0;
        }
        motor.write(degree);
        delay(500);
    }
}
