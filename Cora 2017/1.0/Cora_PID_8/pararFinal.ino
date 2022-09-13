void pararFinal() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 80);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 80);
  delay(300);

  P = 0 , I = 0, D = 0;
  valorPID = 0;

  erro = 0;
  erro_anterior = 0;

  P2 = 0 , I2 = 0, D2 = 0;
  valorPID2 = 0;

  erro2 = 0;
  erro_anterior2 = 0;

  leitura_sensores();
  while (acao == preto) {
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, LOW);
    analogWrite(velPinE, 0);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
    analogWrite(velPinD, 0);
    leitura_sensores();
  }
}

