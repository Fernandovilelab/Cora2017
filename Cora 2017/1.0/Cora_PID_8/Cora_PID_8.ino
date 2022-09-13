/*Controle de  vel esquerda-pino 10
  Controle de vel direita- pino 11
  IN1 pino 12
  IN2 pino 13
  IN3 pino 0
  IN4 pino 1
  branco -> 0
  preto  -> 1
  sensores -> sensor físico
  ses -> leitura do sensor
  kp=53.42
  ki=0.3
  kd=45.2

  VEL 65*/

#define R A4
#define G A5
#define B A1

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

#define velMax 85
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

float P2 = 0 , I2 = 0, D2 = 0;
float valorPID2 = 0;

int erro2 = 0;
int erro_anterior2 = 0;

bool controlePreto = true;
bool controleMarca = false;
int marcadorE = 0;     //quadrado indicador curva 90 esquerda
int marcadorD = 0;     //quadrado indicador curva 90 direita
int marcadorB = 0;     //quadrados indicadores bifurcaçao
int marcadorSaida = 0;
int marcadorSaidaDesejada = 0;
int marcadorR = 0;
int temp = 0;


int acao = 0;
#define frente 0
#define E90 1
#define D90 2
#define branco 3
#define preto 4
#define marcador 5
#define bifT 6
#define saidaD 7
#define saidaE 8

#define tcurva 450


int controleBif = 0;//bifurcaçao T  1 -> esquerda   0 -> direita

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

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

void loop() {
  leitura_sensores();
  switch (acao) {
    case frente:
      
      controlePID();
      controlePreto = true;
      break;

    case marcador:
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      controlePID2();
      break;

    case E90:
      if (controlePreto == true) {
        marcadorE ++;
        temp = millis();
      }
      controlePreto = false;
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      break;

    case D90:
      if (controlePreto == true) {
        marcadorD ++;
        temp = millis();
      }
      controlePreto = false;      
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      break;

    case bifT:
      marcadorB = 1;
      temp = millis();
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      break;

    case saidaD:
      sairD();
      digitalWrite(R, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      break;

    case saidaE:
      sairE();
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      break;

    case branco:
      if (marcadorE == 1 && millis() - temp < 2000) {
        curvaE90();
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      else if (marcadorE == 2 && millis() - temp < 2000) {
        rotatoriaE();
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      else if (marcadorE == 3 && millis() - temp < 2000) {
        rotatoriaE();
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      else if (marcadorE == 4 && millis() - temp < 2000) {
        rotatoriaE();
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, HIGH);
      }
      else if (marcadorD == 1 && millis() - temp < 2000) {
        curvaD90();
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      else if (marcadorD == 2 && millis() - temp < 2000) {
        rotatoriaD();
        digitalWrite(R, HIGH);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      else if (marcadorD == 3 && millis() - temp < 2000) {
        rotatoriaD();
        digitalWrite(R, LOW);
        digitalWrite(G, HIGH);
        digitalWrite(B, LOW);
      }
      else if (marcadorD == 4 && millis() - temp < 2000) {
        rotatoriaD();
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, HIGH);
      }  
      else if (marcadorB == 1 && millis() - temp < 2000) {
        bifur();
        digitalWrite(R, HIGH);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      break;

    case preto:
      if (controleMarca == true) {
        pararFaixa();
      }
      else {
        pararFinal();
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
      }
      break;
  }
}


