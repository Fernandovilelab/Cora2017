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
#define velMin 10

int sensores[] = {2, 3, 4, 5, 6, 7, 8, 9, A0}; //pinos
int ses[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};      //valor

float Kp = 53.42;
float Ki = 0.3;
float Kd = 45.2;

float P = 0 , I = 0, D = 0;
float valorPID = 0;

int erro = 0;
int erro_anterior = 0;

int acao;
#define frente 0
#define branco 3
#define preto 4
#define linha 5

#define tcurva 410

#include <Ultrasonic.h>

#define trig A5
#define echo A4

Ultrasonic ultrasonic(trig, echo);
float dist = 0;
long microsec = 0;

int controle;
int controleL = 0;
int controleO = 0;
int controleV = 1;
int controleVV = 1;

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
  if (controleO == 0) {
    long microsec = ultrasonic.timing();
    dist = ultrasonic.convert(microsec, Ultrasonic::CM);
  }
  for (controle = 0; controle < 3; controle++ && acao != preto) {
    leitura_sensores();
    controlePID();
  }
   if (dist < 13 && millis() >200  || controleO == 1) {
    controleO = 1;
    if (controleL == 0) {
      if (controleV == 1) {
        curvaE90();
        controleV = 0;
      }
      else if (acao == preto) {
        digitalWrite (IN1, LOW);
        digitalWrite (IN2, HIGH);
        analogWrite(velPinE, velE);
        digitalWrite (IN3, LOW);
        digitalWrite (IN4, HIGH);
        analogWrite(velPinD, velD);
        delay(25);
      }
      else if (acao == linha || acao == frente) {
        curvaD90();
        controleO = 0;
        controleL = 1;
      }
    }
    else if (controleL == 1) {
      if (controleVV == 1) {
        curvaD90();
        controleVV = 0;
      }
      else if (acao == preto) {
        digitalWrite (IN1, LOW);
        digitalWrite (IN2, HIGH);
        analogWrite(velPinE, velE);
        digitalWrite (IN3, LOW);
        digitalWrite (IN4, HIGH);
        analogWrite(velPinD, velD);
        delay(25);
      }
      else if (acao == linha || acao == frente) {
        curvaE90();
        controleO = 0;
        controleL = 0;
      }
    }
  }
}



