int IN1 = 12;
int IN2 = 13;
int IN3 = A2;
int IN4 = A3;

int velPinE =10;
int velPinD =11;
  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

 pinMode(velPinE, OUTPUT);
 pinMode(velPinD, OUTPUT);
}
  
void loop()
{
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite(velPinE, 60);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite(velPinD, 70);
  delay(10000);
 
}
