void curva90E() {
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

    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite(velPinE, 90);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);
    analogWrite(velPinD, 90);
    delay(530);
    controleMarca = false;
  }
}
