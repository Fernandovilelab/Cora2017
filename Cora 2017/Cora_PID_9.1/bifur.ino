void bifur() {
  if (controleBif == true) {
    //para esqurda
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

    int e = 0;
    while (e == 0) {
      digitalWrite (IN1, HIGH);
      digitalWrite (IN2, LOW);
      analogWrite(velPinE, vcurva);
      digitalWrite (IN3, LOW);
      digitalWrite (IN4, HIGH);
      analogWrite(velPinD, vcurva);
      delay(5);
      leitura_sensores();
      if (ses[3] == 0) {
        e = 1;
      }
    }
  }

  else if (controleBif == false) {
    //para direita
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

    int f = 0;
    while (f == 0) {
      digitalWrite (IN1, LOW);
      digitalWrite (IN2, HIGH);
      analogWrite(velPinE, vcurva);
      digitalWrite (IN3, HIGH);
      digitalWrite (IN4, LOW);
      analogWrite(velPinD, vcurva);
      delay(5);
      leitura_sensores();
      if (ses[5] = 0) {
        f = 1;
      }
    }
  }
  marcadorB = 0;
}
