/*Controle de  vel esquerda-pino 10
  Controle de vel direita- pino 11
  IN1 pino 12
  IN2 pino 13
  IN3 pino 0
  IN4 pino1
  branco -> 0
  preto    -> 1
  sensores -> sensor físico
  ses -> leitura do sensor
  kp=40
  ki=0.15
  kd=50
  41
  0.30
  42,5
  VEL 70*/

#define IN1 12
#define IN2 13
#define IN3 A2
#define IN4 A3

#define velPinE 10
#define velPinD 11

int velE = 65;
int velD = 65;
int novaVelE = velE;
int novaVelD = velD;

#define velMax 90
#define velMin 5

int sensores[] = {2, 3, 4, 5, 6, 7, 8, 9, A0}; //pinos
int ses[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};      //valor

float Kp = 53.42;
float Ki = 0.3;
float Kd = 45.2;
float P = 0 , I = 0, D = 0;
float valorPID = 0;

int erro = 0;
int erro_anterior = 0;

bool faixa = false;

int acao = 0;
#define frente 0
#define E90 1
#define D90 2
#define marcador 3
#define branco 4
#define preto 5
#define bifT 6

int controle = 1;//bifurcaçao   1 -> esquerda   0 -> direita

void setup() {
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(velE, OUTPUT);
  pinMode(velD, OUTPUT);

  for (int s = 0; s < 9; s++) {
    pinMode(sensores[s], INPUT);
  }

  Serial.begin(9600);
}


void leitura_sensores() {
  ses[0] = digitalRead(sensores[0]);
  ses[1] = digitalRead(sensores[1]);
  ses[2] = digitalRead(sensores[2]);
  ses[3] = digitalRead(sensores[3]);
  ses[4] = digitalRead(sensores[4]);
  ses[5] = digitalRead(sensores[5]);
  ses[6] = digitalRead(sensores[6]);
  ses[7] = digitalRead(sensores[7]);
  ses[8] = digitalRead(sensores[8]);

  if      (ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -8;}
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -7;}
  else if (ses[0] == 1 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -6;}
  else if (ses[0] == 1 && ses[1] == 0 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -5;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -4;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -3;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -2;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -1;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 0;} // posição ideal
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 1;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 2;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 3;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 4;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 0 && ses[8] == 1) {acao = frente; erro = 5;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 1) {acao = frente; erro = 6;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 0) {acao = frente; erro = 7;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 0) {acao = frente; erro = 8;}
  
  else if ((ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)||
           (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)||
           (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)){acao = E90;} //curva 90 esquerda
  else if ((ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 0)||
           (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 0)||
           (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0)){acao = D90;} //curva 90 direita
           
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0) {acao = marcador;} //marcador

  else if (ses[0] == 0 && ses[2] == 1 && ses[6] == 1 && ses[8] == 0){acao = bifT;}//bifurcação em T

  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = preto; }//tudo preto
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 0 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0) {acao = branco;}//tudo branco
}

void controlePID(){
    P = erro;                                  //se valorPID positivo virar para direita
    I = I + erro;                              //se valorPID negativo virar para esquerda
    D = erro - erro_anterior;
    valorPID = (Kp*P) + (Kd*D) + (Ki*I);
    erro_anterior = erro;

    if(valorPID > 0){ //virar direita
      novaVelE = velE + valorPID;
      novaVelD = velD - valorPID;
    }    
    if(valorPID < 0){ //virar esquerda
      novaVelE = velE + valorPID;
      novaVelD = velD - valorPID;
    }
    if(valorPID == 0){
      novaVelE = velE;
      novaVelD = velD;
    }
    if (novaVelE < velMin){
      novaVelE = velMin;
    }
    if (novaVelE > velMax){
      novaVelE = velMax;
    }
    if (novaVelD < velMin){
      novaVelD = velMin;
    }
    if (novaVelD > velMax){
      novaVelD = velMax;
    }
    
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, novaVelE);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, novaVelD);
  delay (10);
}

void curva90E(){
 leitura_sensores();
 while(acao != branco){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);  //frente
  analogWrite(velPinE, 70);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 70);
  leitura_sensores();
  }

  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, 90);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 90);
  delay(530);
}

void curva90D(){
 leitura_sensores();
 while(acao != branco){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);  //frente
  analogWrite(velPinE, 70);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 70);
  leitura_sensores();
  }

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 90);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, 90);
  delay(530);
}

void marca(){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 70);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 70);
  delay(380);
}

void pararFaixa(){
  delay(100);
  leitura_sensores();
  if(acao == preto){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, 0);
  delay(2000);

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 70);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 70);
  delay(1400);   
  
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 0);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 0);
  delay(200);

  I = 0;
  erro_anterior = 0;
 }
}

void pararFinal(){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 80);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 80);
  delay(200);
  
  leitura_sensores();
  while(acao == preto){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, 0);
  leitura_sensores();
  }
}

void bifur(){ 
 if(controle == 1){ 
 //para esqurda
 leitura_sensores();
 while(acao != branco){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);  //frente
  analogWrite(velPinE, 70);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 70);
  leitura_sensores();
 }

  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, 90);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 90);
  delay(500);
  }

else if(controle == 0){
 //para direita
  leitura_sensores();
 while(acao != branco){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);  //frente
  analogWrite(velPinE, 70);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 70);
  leitura_sensores();
  }

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 90);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, 90);
  delay(300);
  }
}

void loop(){
 leitura_sensores();
 switch(acao){
  case frente:
  controlePID();
  break;

  case E90:
  curva90E();
  break;

  case D90:
  curva90D();
  break;

  case preto:
  if(faixa == false){
    pararFaixa();
    faixa = true;
  }
  else if(faixa == true){
    pararFinal();
  }
  break;

  case marcador:
  marca();
  break;

  /*case bifT:
  bifur();
  break;*/
  }
}


