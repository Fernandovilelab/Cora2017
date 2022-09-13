void pararFaixa() {
  delay(100);
  leitura_sensores();
  if (acao == preto) {
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, LOW);
    analogWrite(velPinE, 0);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
    analogWrite(velPinD, 0);
    delay(2000);

    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite(velPinE, 70);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);
    analogWrite(velPinD, 70);
    delay(1400);

    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, HIGH);
    analogWrite(velPinE, 0);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, HIGH);
    analogWrite(velPinD, 0);
    delay(200);

    I = 0;
    erro_anterior = 0;
  }
  controleMarca = false;
}
