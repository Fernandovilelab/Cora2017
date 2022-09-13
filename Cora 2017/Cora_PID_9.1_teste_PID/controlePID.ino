void controlePID() {
  P = erro;                                  //se valorPID positivo virar para direita
  I = I + erro;                              //se valorPID negativo virar para esquerda
  D = erro - erro_anterior;
  valorPID = (Kp * P) + (Kd * D) + (Ki * I);
  erro_anterior = erro;

  if (valorPID > 0) { //virar direita
    novaVelE = velE + valorPID;
    novaVelD = velD - valorPID;
  }
  if (valorPID < 0) { //virar esquerda
    novaVelE = velE + valorPID;
    novaVelD = velD - valorPID;
  }
  if (valorPID == 0) {
    novaVelE = velE;
    novaVelD = velD;
  }
  if (novaVelE < velMin) {
    novaVelE = velMin;
  }
  if (novaVelE > velMax) {
    novaVelE = velMax;
  }
  if (novaVelD < velMin) {
    novaVelD = velMin;
  }
  if (novaVelD > velMax) {
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
