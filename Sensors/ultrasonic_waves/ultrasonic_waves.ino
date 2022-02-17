int trig = 8;
int echo = 9;

int blueLed = 5;
int yellowLed = 6;
int redLed = 7;
 
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  unsigned long duration = pulseIn(echo, HIGH);
 

  float distance = duration / 29.0 / 2.0;
 
  Serial.print(distance);
  Serial.println("cm");

  if (10 < distance&&distance < 15) {
    digitalWrite(blueLed, HIGH);
  }
  else if(5 < distance&&distance < 9){
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, HIGH);
  }
  else if(distance < 4) {
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
  }
  else{
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  }
  delay(200);
}
