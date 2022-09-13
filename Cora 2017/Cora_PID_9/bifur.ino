void bifur() {
  if (controleBif == 1) {
    //para esqurda
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite(velPinE, 90);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);
    analogWrite(velPinD, 90);
    delay(tcurva);
  }

  else if (controleBif == 0) {
    //para direita
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite(velPinE, 90);
    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    analogWrite(velPinD, 90);
    delay(tcurva);
  }
  marcadorB = 0;
}
