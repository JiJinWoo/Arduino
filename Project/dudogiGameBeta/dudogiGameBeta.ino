#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);

int led[] = {A0, A1, A2};
int sw[] = {9, 10, 11};

int rand_num; //무작위로 켜지는 Led와 Sw 번호
int count = 0;  //두더지 잡은 수
int total_game = 10; //총 게임 횟수

int ending = 0;

void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(led[i], OUTPUT);
    pinMode(sw[i], INPUT_PULLUP);
  }
  lcd.begin(16,2);
  lcd.clear();
}

void loop(){
  if(ending == 0){
    if(digitalRead(sw[0]) == LOW){
      ending = 1;
      gameStart();
      startLcd();
    }
  }
  else if(total_game == 0){
    endLcd();
    ending = 0;
  }
  else{
    rand_num = random(0, 3);
    switch(rand_num){
      case 0:
      dudogi();
      total_game--;
      break;

      case 1:
      dudogi();
      total_game--;
      break;

      case 2:
      dudogi();
      total_game--;
      break;
    }
  }
  delay(1000);
}


void dudogi(){
  for(int i = 0; i < 20; i++){
    if(total_game == 0){
      break;
    }
    else if(digitalRead(sw[rand_num]) == LOW){
      analogWrite(led[rand_num], 0);
      count++;
      lcd.setCursor(10, 1);
      lcd.print(count);
      break;
    }
    else{
      analogWrite(led[rand_num], 255);
      delay(100);
      analogWrite(led[rand_num], 0);
    }
  }
}

void gameStart(){
  lcd.setCursor(0,0);
  lcd.print("3");
  delay(1000);
  lcd.print("2");
  delay(1000);
  lcd.print("1");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("GameStart");
  delay(1000);
}

void startLcd(){
  lcd.setCursor(0,0);
  lcd.print("Total : ");
  lcd.print(total_game);
  lcd.setCursor(0,1);
  lcd.print("Success : ");
}

void endLcd(){
  lcd.setCursor(0,0);
  lcd.print("----THE END----");
  lcd.setCursor(0,1);
  lcd.print("Result : ");
  lcd.print(count);
  lcd.print("!!!");
}
