int led[] ={8, 9, 10, 11}; //상 = 0, 우 = 1, 하 = 2, 좌 = 3

int x_degree = A0;  //mid degree = 494 좌우 좌표(0 ~ 1023) - 좌표는 직접 찾고 변경
int y_degree = A1;  //mid degree = 494 상하 좌표(0 ~ 1023)

void setup(){
    for(int i = 0; i < 4; i++){
        pinMode(led[i], OUTPUT);
    }
}

void loop(){
    if(analogRead(x_degree) > 550){
        digitalWrite(led[0], HIGH);
    }
    else if(analogRead(x_degree) < 450){
        digitalWrite(led[2], HIGH);
    }
    else if(analogRead(y_degree) > 550){
        digitalWrite(led[3], HIGH);
    }
    else if(analogRead(y_degree) < 450){
        digitalWrite(led[1], HIGH);
    }
    else{
        digitalWrite(led[0], LOW);
        digitalWrite(led[1], LOW);
        digitalWrite(led[2], LOW);
        digitalWrite(led[3], LOW);
    }
}
