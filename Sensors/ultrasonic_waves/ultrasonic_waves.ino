int trig = 8;
int echo = 9;

int BlueLed = 5;
int YellowLed = 6;
int RedLed = 7;
 
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(BlueLed, OUTPUT);
  pinMode(YellowLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
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
    digitalWrite(BlueLed, HIGH);
  }
  else if(5 < distance&&distance < 9){
    digitalWrite(BlueLed, LOW);
    digitalWrite(YellowLed, HIGH);
  }
  else if(distance < 4) {
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, HIGH);
  }
  else{
    digitalWrite(BlueLed, LOW);
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, LOW);
  }
  delay(200);
}
