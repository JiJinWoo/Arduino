int Led[] = {8, 9, 10};
int Led_num = 3;

void setup(){
  for(int i = 0; i < Led_num; i++){
    pinMode(Led[i], OUTPUT);
  }
}

void loop(){
  for(int i = 0; i < 10; i++){
    int x = random(0, 3);
    digitalWrite(Led[x], HIGH);
    delay(500);
    digitalWrite(Led[x], LOW);
  }
}
