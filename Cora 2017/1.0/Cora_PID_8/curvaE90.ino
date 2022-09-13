void curvaE90() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, 90);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 90);
  delay(tcurva);

  marcadorE = 0;
}

