void pararFinal() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 80);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 80);
  delay(200);

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

