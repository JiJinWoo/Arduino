int Led[] = {8, 9, 10, 11, 12};
int Led_num = 5;
int sw = 7;

void setup(){
  for(int i=0; i<Led_num; i++){
    pinMode(Led[i], OUTPUT);
  }
  pinMode(sw, INPUT);
}

void loop(){
  if(digitalRead(sw) == LOW){
    for(int i=0; i<Led_num; i++){
      digitalWrite(Led[i], HIGH);
      delay(200);
      digitalWrite(Led[i], LOW);
    }
  }
  else if(digitalRead(sw) == HIGH){
    for(int i=Led_num; i>=0; i--){
      digitalWrite(Led[i], HIGH);
      delay(200);
      digitalWrite(Led[i], LOW);
    }
  }
}
