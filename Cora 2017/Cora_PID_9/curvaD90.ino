void curvaD90() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, vcurva);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD, vcurva);
  delay(tcurva);

  marcadorD = 0;
}
