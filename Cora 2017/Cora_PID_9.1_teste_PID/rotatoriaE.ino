void rotatoriaE() {
  digitalWrite(B, HIGH);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 200);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 200);
  delay (1);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, vcurva);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, vcurva);
  delay (60);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 200);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 200);
  delay (1);

  int z = 0;
  while (z == 0) {
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite(velPinE, vcurva);
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);
    analogWrite(velPinD, vcurva);
    delay(5);
    leitura_sensores();
    if (ses[2] == 0) {
      z = 1;
    }
  }

  marcadorD = 0;
  marcadorE = 0;
  marcadorRD = 1;
  marcadorRE = 0;
}
