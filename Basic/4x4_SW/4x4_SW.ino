#include <Keypad.h>

const byte ROWS = 1;    // 행(rows) 개수
const byte COLS = 4;    // 열(columns) 개수
char keys[ROWS][COLS] = {
  {'1','2','3','A'}
};

byte rowPins[ROWS] = {2};   // R1, R2, R3, R4 단자가 연결된 아두이노 핀 번호
byte colPins[COLS] = {3, 4, 5, 6};   // C1, C2, C3, C4 단자가 연결된 아두이노 핀 번호
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int Led[] = {A0, A1, A2, A3};
int Led_num = 4;

int x;
int count = 0;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < Led_num; i++){
    pinMode(Led[i], OUTPUT);
  }
}
   
void loop() {
  dudogi();
}

void dudogi(){
  char key = keypad.getKey();
  for(int i = 0; i < 20; i++){
    if(count == 5){
      break;
    }
    else{
      x = random(0, 5);
      if(key){
        analogWrite(Led[x], 0);
        delay(300);
        count++;
        Serial.println(count);
      }
      else{
        analogWrite(Led[x], 255);
        delay(500);
        analogWrite(Led[x], 0);
      }
    }
  }
}
