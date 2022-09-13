void sairD() {
  marcadorSaida++;
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, vcurva);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, vcurva);
  delay(50);

  if (marcadorSaida == marcadorSaidaDesejada) {
    int b = 0;
    while (b == 0) {
      digitalWrite (IN1, LOW);
      digitalWrite (IN2, HIGH);
      analogWrite(velPinE, vcurva);
      digitalWrite (IN3, HIGH);
      digitalWrite (IN4, LOW);
      analogWrite(velPinD, vcurva);
      delay(5);
      leitura_sensores();
      if (ses[6] == 0) {
        b = 1;
      }
    }
    marcadorSaida = 0;
    marcadorSaidaDesejada = 0;
    marcadorRD = 0;
  }
}

