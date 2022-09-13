void curvaD90() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 90);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, 90);
  delay(tcurva);

  marcadorD = 0;
}
