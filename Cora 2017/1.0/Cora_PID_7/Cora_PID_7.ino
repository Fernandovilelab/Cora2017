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
  kp=53.42
  ki=0.3
  kd=45.2

  VEL 65*/

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

bool faixa = false;
bool controleMarca = false;
unsigned long t1 = 0;

int acao = 0;
#define frente 0
#define E90 1
#define D90 2
#define marcador 3
#define branco 4
#define preto 5
#define bifT 6

int controle = 1;//bifurcaçao T  1 -> esquerda   0 -> direita

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

void loop() {
  leitura_sensores();
  switch (acao) {
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
      if (faixa == false) {
        pararFaixa();
        faixa = true;
      }
      else if (faixa == true) {
        pararFinal();
      }
      break;
    case marcador:
      marca();
      controleMarca = true;
      t1 = millis();
      break;
    case bifT:
      bifur();
      break;
  }

  if (controleMarca == true && (millis() - t1) > 5000) {
    controleMarca = false;
  }
}


