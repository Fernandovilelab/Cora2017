/*Controle de  vel esquerda-pino10
  Controle de vel direita- pino 11
  IN1 pino 12
  IN2 pino 13
  IN3 pino 0
  IN4 pino1
  branco -> 0
  preto    -> 1
  sensores -> sensor físico
  ses -> leitura do sensor*/

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

  if      (ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -8;} 
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -7;}
  else if (ses[0] == 1 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -6;}
  else if (ses[0] == 1 && ses[1] == 0 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -5;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -4;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -3;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -2;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = -1;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = 0;} // posição ideal
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = 1;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {erro = 2;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 1 && ses[8] == 1) {erro = 3;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 1 && ses[8] == 1) {erro = 4;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 0 && ses[8] == 1) {erro = 5;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 1) {erro = 6;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 0) {erro = 7;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 0) {erro = 8;} 
  
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
    if (novaVelE > 125){
      novaVelE = 125;
    }
    if (novaVelD < 0){
      novaVelD = 0;
    }
    if (novaVelD > 125){
      novaVelD = 125;
    }
    
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, novaVelE);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, novaVelD);
  delay (5);
}



void loop(){
  leitura_sensores();
  controlePID();
}
   

