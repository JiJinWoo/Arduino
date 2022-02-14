#include <Adafruit_LiquidCrystal.h>



int Led[] = {2, 3, 4};
int Led_num = 3;

int Sw[] = {5, 6, 7};
int Sw_num = 3;

int x;
int count_up = 0;

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < Led_num; i++){
    pinMode(Led[i], OUTPUT);
  }
  for(int i = 0; i < Sw_num; i++){
    pinMode(Sw[i], INPUT_PULLUP);
  }
}

void loop(){
  dudogi();
}

void dudogi(){
  for(int i = 0; i < 20; i++){
  if(count_up == 3){
    break;
  }
  else{
      x = random(0, 3);
      if(digitalRead(Sw[x]) == LOW){
        digitalWrite(Led[x], LOW);
        delay(500);
        count_up++;
        Serial.println(count_up);
      }
      else{
        digitalWrite(Led[x], HIGH);
        delay(1000);
        digitalWrite(Led[x], LOW);
      }
    }
  }
}
