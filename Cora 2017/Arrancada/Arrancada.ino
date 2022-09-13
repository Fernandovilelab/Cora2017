#define IN1 12
#define IN2 13
#define IN3 A2
#define IN4 A3

#define velPinE 10
#define velPinD 11


int sensores[] = {2, 3, 4, 5, 6, 7, 8, 9, A0}; //pinos
int ses[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};      //valor

///////////////////////////////////////////////velocidade/////////
int velE = 255;
int velD = 255;
int novaVelE = velE;
int novaVelD = velD;

#define velMax 255
#define velMin 200

/////////////////////////////////////////////////////PID////////
float Kp = 53.42;
float Ki = 0.3;
float Kd = 45.2;

//contrlolePID
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

void loop() {
  leitura_sensores();
  controlePID();
}

