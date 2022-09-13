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
  kd=50*/

#define IN1 12
#define IN2 13
#define IN3 0
#define IN4 1

#define velPinE 10
#define velPinD 11

int velE = 70;
int novaVelE = 0;
int velD = 70;
int novaVelD = 0;

int sensores[] = {2, 3, 4, 5, 6, 7, 8, 9, A0}; //pinos
int ses[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};      //valor

float Kp = 40;
float Ki = 0.15;
float Kd = 50;
float P = 0 , I = 0, D = 0;
float valorPID = 0;

int erro = 0;
int erro_anterior = 0;

bool isTurning;

int acao = 0;
#define frente 0
#define E90 1
#define D90 2
#define marcador 3

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
  
  else if (ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = E90;} //curva 90 esquerda
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 0) {acao = D90;} //curva 90 direita
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0) {acao = marcador;} //marcador

//  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {}//tudo preto
//  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 0 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0) {}//tudo branco
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
      novaVelE = 70;
      novaVelD = 70;
    }
    if (novaVelE < 0){
      novaVelE = 0;
    }
    if (novaVelE > 110){
      novaVelE = 110;
    }
    if (novaVelD < 0){
      novaVelD = 0;
    }
    if (novaVelD > 110){
      novaVelD = 110;
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
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, velD);
  delay(20);
    
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, velE + 30);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, velD + 30);
  delay(350);

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, velD);
  delay(20);      
}

void curva90D(){
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, velD);
  delay(20);
    
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, velE + 30);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, velD + 30);
  delay(350);

  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, velD);
  delay(20);
}

void marca(){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, velD);
  delay(20);
}
void loop(){
 leitura_sensores();
 switch(acao){
  case frente:
  isTurning = false;
  controlePID();
  break;

  case E90:
  curva90E();
  isTurning = true;
  break;

  case D90:
  curva90D();
  isTurning = true;
  break;

  case marcador:
  marca();
  break;
 }
 if(isTurning == true){
  isTurning = false;
  acao = frente;
  }
}


