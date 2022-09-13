void rotatoriaD() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, vcurva);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite(velPinD,vcurva);
  delay(tcurva);

  marcadorSaidaDesejada = 2;
  marcadorD = 0;
  marcadorRD = 1;
}

