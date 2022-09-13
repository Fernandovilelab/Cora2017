/*Controle de vel esquerda-pino 10
  Controle de vel direita-pino 11
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

int acao;
#define frente 0
#define E90 1
#define D90 2
#define branco 3
#define preto 4
#define marcador 5
#define bifT 6
#define saidaD 7
#define saidaE 8
#define transversal 9

int sensores[] = {2, 3, 4, 5, 6, 7, 8, 9, A0}; //pinos
int ses[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};      //valor

///////////////////////////////////////////////velocidade//////////////////////////////////////////////////
int velE = 65;
int velD = 65;
int novaVelE = velE;
int novaVelD = velD;

#define velMax 75
#define velMin 5

/////////////////////////////////////////////////////PID//////////////////////////////////////////////////////////
float Kp = 53.42;
float Ki = 0.3;
float Kd = 45.2;

//contrlolePID
float P = 0 , I = 0, D = 0;
float valorPID = 0;
int erro = 0;
int erro_anterior = 0;

//controlePID2
float P2 = 0 , I2 = 0, D2 = 0;
float valorPID2 = 0;
int erro2 = 0;
int erro_anterior2 = 0;

////////////////////////////////////////////////marcadores///////////////////////////////////////////////
bool controlePreto = true;
bool controleMarca = false;
bool  controleBif = true; //bifurcaçao T  true -> esquerda   false-> direita

int marcadorE = 0;     //quadrado indicador curva 90 esquerda
int marcadorD = 0;     //quadrado indicador curva 90 direita
int marcadorB = 0;     //quadrados indicadores bifurcaçao
int marcadorSaida = 0;
int marcadorSaidaDesejada = 0;
int marcadorRD = 0;
int marcadorRE = 0;
int temp = 0;

////////////////////////////////////////////////////////////////////////////////////
#define tcurva 480
#define vcurva 65
/////////////////////////////////////////////////////////////////////////////////////

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
    ////////////////////////////////////////////////////////////controle
    case frente:
      controlePID();
      controlePreto = true;
      break;

    case marcador:
      controlePID2();
      break;
    ////////////////////////////////////////////////////////////marcadores
    case E90:
      if (controlePreto == true) {
        marcadorE ++;
        temp = millis();
      }
      controlePreto = false;
      controlePID();
      break;

    case D90:
      if (controlePreto == true) {
        marcadorD ++;
        temp = millis();
      }
      controlePreto = false;
      controlePID();
      break;

    case bifT:
      marcadorB = 1;
      temp = millis();
      break;
    /////////////////////////////////////////////////////////////saidas
    case saidaD:
      if (marcadorRD == 1) {
        sairD();
      }
      else if (marcadorD == 1) {
        curvaD90();
      }
      break;

    case saidaE:
      if (marcadorRE == 1) {
        sairE();
      }
      else if (marcadorE == 1) {
        curvaE90();
      }
      break;

    case branco:
      if (marcadorE == 0 && marcadorD == 0 && marcadorRD == 0 && marcadorRE == 0) {
        digitalWrite(R, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(B, HIGH);
        
        digitalWrite (IN1, LOW);
        digitalWrite (IN2, HIGH);
        analogWrite(velPinE, vcurva);
        digitalWrite (IN3, LOW);
        digitalWrite (IN4, HIGH);
        analogWrite(velPinD, vcurva);
        delay (60);
      }
      /////////////////////////////////////////////////////////esquerda
      else if (marcadorE == 1 ) {
        digitalWrite(R, HIGH);
        curvaE90();
      }
      else if (marcadorE == 2 ) {
        digitalWrite(G, HIGH);
        marcadorSaidaDesejada = 1;
        rotatoriaE();
      }
      else if (marcadorE == 3 ) {
        digitalWrite(B, HIGH);
        marcadorSaidaDesejada = 2;
        rotatoriaE();
      }
      else if (marcadorE == 4 ) {
        digitalWrite(R, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(B, HIGH);
        marcadorSaidaDesejada = 3;
        rotatoriaE();
      }
      else if (marcadorRE == 1 ) {
        sairE();
      }
      ///////////////////////////////////////////////////////////direita
      else if (marcadorD == 1 ) {
        digitalWrite(R, HIGH);
        curvaD90();
      }
      else if (marcadorD == 2 ) {
        digitalWrite(G, HIGH);
        marcadorSaidaDesejada = 1;
        rotatoriaD();
      }
      else if (marcadorD == 3 ) {
        digitalWrite(B, HIGH);
        marcadorSaidaDesejada = 2;
        rotatoriaD();
      }
      else if (marcadorD == 4 ) {
        digitalWrite(R, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(B, HIGH);
        marcadorSaidaDesejada = 3;
        rotatoriaD();
      }
      else if (marcadorRD == 1 ) {
        sairD();
      }
      ///////////////////////////////////////////////////////////bifurcação
      else if (marcadorB == 1 ) {
        bifur();
      }
      break;
    //////////////////////////////////////////////////////////parar
    case preto:
      if (controleMarca == true) {
        pararFaixa();
      }
      else {
        pararFinal();
      }
      break;

      if (millis() - temp > 3000) {
        marcadorE = 0;
        marcadorD = 0;
      }
  }
}


