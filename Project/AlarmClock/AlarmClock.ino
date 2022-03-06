#include <LiquidCrystal.h>
#include <core_build_options.h>
#include <swRTC.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);

swRTC rtc;

int piezo = 9;    //알람 사운드
int sw = 11;      //알람 종료 버튼

int alarmHour = 2;    //알람이 울리는 시
int alarmMinute = 8;  //알람이 울리는 분

void setup(){
  rtc.stopRTC();  //정지
  rtc.setTime(2, 7, 35); //시간, 분, 초 초기화
  rtc.setDate(5, 3, 2022); //일, 월, 년 초기화 
  rtc.startRTC(); //시작

  lcd.begin(16, 2);
  lcd.clear();

  pinMode(piezo, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop(){
  //오늘 날짜와 현재 시간 LCD 화면 상에 출력
  lcd.setCursor(0,0);
  lcd.print("[");
  numberPrint(rtc.getMonth());
  lcd.print("/");
  numberPrint(rtc.getDay());
  lcd.print("]");
  setAMPM(rtc.getHours());
  numberPrint(rtc.getHours());
  lcd.print(":");
  numberPrint(rtc.getMinutes());

  //설정된 알람 시간을 LCD 화면 상에 출력
  lcd.setCursor(0,1);
  lcd.print("Alarm");
  lcd.setCursor(7,1);
  setAMPM(alarmHour);
  numberPrint(alarmHour);
  lcd.print(":");
  numberPrint(alarmMinute);

  //지정된 시간에 알람이 울리고 스위치를 누르면 지정된 알람 시간 초기화
  alarmClock(alarmHour, alarmMinute);
  if(digitalRead(sw) == 0){
    analogWrite(piezo, 0);
    alarmHour = 0;
    alarmMinute = 0;
  }
}


void alarmClock(int checkHour, int checkMinute){      //알람이 울리는 시간이라면 알람 울리게 한다
  if(checkHour == rtc.getHours() && checkMinute == rtc.getMinutes()){
  analogWrite(piezo, 128);
  }
}

void setAMPM(int hour){         //AM, PM을 설정해주는 함수
  if(hour >= 12) lcd.print("PM");
  else lcd.print("AM");
}

void numberPrint(int number){   //10보다 작은 수가 출력 될 때 앞에 0을 출력하고 아니면 원래의 숫자 출력
  if(number < 10){
    lcd.print("0");
    lcd.print(number);
  }
  else lcd.print(number);
}
