/*Controle de  vel esquerda-pino10
  Controle de vel direita- pino 11
  IN1 pino 12
  IN2 pino 13
  IN3 pino 0
  IN4 pino1
  branco -> 0
  preto    -> 1*/

#define IN1 12
#define IN2 13
#define IN3 0
#define IN4 1

#define velPinE 10
#define velPinD 11

int velE = 80;
int velD = 80;


int sensores[] = {2, 3, 4, 5, 6, 7, 8, 9, A0};

void frente() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, velD);
  delay (20);
}

void reverso() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, velD);
  delay (20);
}

void direita() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, velD + 50);
  delay (10);
}

void direita90() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, velE);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, velD + 50);
  delay (180);
}

void esquerda() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, velE + 100);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, velD);
  delay (10);
}

void esquerda90() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, velE + 100);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, velD);
  delay (180);
}

void parado(){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, 0);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, 0);
}

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
  int ses1 = digitalRead(2);
  int ses2 = digitalRead(3);
  int ses3 = digitalRead(4);
  int ses4 = digitalRead(5);
  int ses5 = digitalRead(6);
  int ses6 = digitalRead(7);
  int ses7 = digitalRead(8);
  int ses8 = digitalRead(9);
  int ses9 = digitalRead(A0);

  int ctrlD = 0;
  int ctrlE = 0;

  if (ses3 == 1 && ses5 == 0 && ses7 == 1) {
    frente();
  }
  if ((ses3 == 0) || (ses4 == 0 && ses5 == 0) || (ses4 == 0)) {    //Esses parametros funcionam:(ses3 == 0) || (ses4 == 0 && ses5 == 0) || (ses4 == 0)
    esquerda();

  }
  if ((ses7 == 0) || (ses5 == 0 && ses6 == 0 ) || (ses6 == 0) ) {  //Esses parametros funcionam:(ses7 == 0) || (ses5 == 0 && ses6 == 0 ) || (ses6 == 0)
    direita();

  }
  if ( ses9 == 0) {
    ctrlD = 1;
  }
  if ( ctrlD == 1 && ses5 == 0 && ses7 == 0) { // 90 direita
    direita90();
    ctrlD = 0;
  }
  if (ses1 == 0 ) {
    ctrlE = 1;
  }
  if (ctrlE == 1 && ses5 == 0 && ses3 == 0) { //90 esquerda
    esquerda90();
    ctrlE = 0;
  }
  if ((ses1 == 1 && ses2 == 1 && ses3 == 1 && ses4 == 1 && ses5 == 1 && ses6 == 1 && ses7 == 1 && ses8 == 1 && ses9 == 1)
  || (ses1 == 0 &&  ses2 == 0 && ses3 == 0 && ses4 == 0 && ses5 == 0 && ses6 == 0 && ses7 == 0 && ses8 == 0 && ses9 == 0)) {
  parado();
  }
}



