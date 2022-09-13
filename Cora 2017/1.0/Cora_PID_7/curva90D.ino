void curva90D() {
  if (controleMarca == true) {
    leitura_sensores();
    while (acao != branco) {
      digitalWrite (IN1, LOW);
      digitalWrite (IN2, HIGH);  //frente
      analogWrite(velPinE, 70);
      digitalWrite (IN3, LOW);
      digitalWrite (IN4, HIGH);
      analogWrite(velPinD, 70);
      leitura_sensores();
    }

    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite(velPinE, 90);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    analogWrite(velPinD, 90);
    delay(530);
    controleMarca = false;
  }
}
