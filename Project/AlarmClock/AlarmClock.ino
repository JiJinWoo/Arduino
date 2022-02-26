#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);

int piezo = 9;
int sw = 10;

int tones[8] = {261, 294, 330, 349, 392, 440, 494, 523};

int now;

void setup(){
  pinMode(piezo, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear;
}

void loop(){
  int tone[] = {};
  if(digitalRead(sw) == LOW){
    noTone(piezo);
  }
}

void set_time(){
  
}
