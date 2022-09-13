void sairE() {
  marcadorSaida++;
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, vcurva);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, vcurva);
  delay(50);

  if (marcadorSaida == marcadorSaidaDesejada) {
   /* digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite(velPinE, vcurva);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);
    analogWrite(velPinD, vcurva);
    delay (30);*/

    int d = 0;
    while (d == 0) {
      digitalWrite (IN1, HIGH);
      digitalWrite (IN2, LOW);
      analogWrite(velPinE, vcurva);
      digitalWrite (IN3, LOW);
      digitalWrite (IN4, HIGH);
      analogWrite(velPinD, vcurva);
      delay(5);
      leitura_sensores();
      if (ses[2] == 0) {
        d = 1;
      }
    }
    marcadorSaida = 0;
    marcadorSaidaDesejada = 0;
    marcadorRE = 0;
  }
}

