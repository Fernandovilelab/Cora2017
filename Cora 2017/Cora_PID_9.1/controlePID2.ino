void controlePID2() {
  P2 = erro2;                                  //se valorPID positivo virar para direita
  I2 = I2 + erro2;                             //se valorPID negativo virar para esquerda
  D2 = erro2 - erro_anterior2;
  valorPID2 = (Kp * P2) + (Kd * D2) + (Ki * I2);
  erro_anterior2 = erro2;

  if (valorPID2 > 0) { //virar direita
    novaVelE = velE + valorPID2;
    novaVelD = velD - valorPID2;
  }
  if (valorPID2 < 0) { //virar esquerda
    novaVelE = velE + valorPID2;
    novaVelD = velD - valorPID2;
  }
  if (valorPID2 == 0) {
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

  controleMarca = true;
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  P = 0 , I = 0, D = 0;
  valorPID = 0;

  erro = 0;
  erro_anterior = 0;
}
