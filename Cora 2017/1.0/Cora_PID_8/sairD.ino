void sairD() {
  marcadorSaida++;
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 90);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 90);
  delay(70);
  
  if (marcadorSaida == marcadorSaidaDesejada) {
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite(velPinE, 90);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    analogWrite(velPinD, 90);
    delay(tcurva);
    marcadorSaida = 0;
    marcadorSaidaDesejada = 0;

  }
}

