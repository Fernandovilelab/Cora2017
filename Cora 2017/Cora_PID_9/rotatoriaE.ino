void rotatoriaE() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite(velPinE, vcurva);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, vcurva);
  delay(tcurva);

  marcadorSaidaDesejada = marcadorE - 1;
  marcadorD = 0;
  marcadorRE = 1;
}
