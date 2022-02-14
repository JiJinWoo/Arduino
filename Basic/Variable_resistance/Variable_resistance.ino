int LED = 9;
int Variable = A0;

void setup(){
  
}


void loop(){
  int var = analogRead(Variable);
  analogWrite(LED, map(var, 0, 1023, 0, 255));
}
