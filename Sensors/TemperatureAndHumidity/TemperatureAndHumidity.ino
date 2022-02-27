int row[] = {A0, 12, A2, 13, 5, A3, 7, 2};
int col[] = {9, 8, 4, A1, 3, 10, 11, 6};

void clear(){
  for(int i=0; i<8; i++){
    digitalWrite(row[i], LOW);
    digitalWrite(col[i], HIGH);
  }
}

void point(int x, int y, int delayTime){
  clear();
  digitalWrite(row[x], HIGH);
  digitalWrite(col[y], LOW);
  delay(delayTime);
}

void setup(){
  for(int i=0; i<8; i++){
    pinMode(row[i], OUTPUT);
    pinMode(col[i], OUTPUT);
  }
}

void loop(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      point(i, j, 100);
    }
  }
}
