//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 2;  //motor E
int IN2 = 4;  //motor E
int IN3 = 6;  //motor D
int IN4 = 7;  //motor D

//pinos pwm para controlar a velocidade dos motores
int velocidade_E = 3;  
int velocidade_D = 5;

int veloc_dir = 100;   //velocidades iniciais dos motores
int veloc_esq = 100;
int nova_veloc_dir = 0; //velocidades calculadas a partir do controldor pid
int nova_veloc_esq = 0;

//Sensores opticos reflexivos
int sensor0;  //mais a esquerda
int sensor1;
int sensor2;  //central
int sensor3;
int sensor4;  //mais a direita
int sensores[5] = {0, 0, 0, 0, 0}; //vetor de posicoes dos sensores

int acao = 0; //acao a ser feita pelos motores
//Açoes feitas pelo motor
# define PARAR 0
# define SEGUIR_FRENTE 1
# define SEM_LINHA 2

// constantes do controlador PID
float Kp = 2; //segue a linha com zigue-zague //1-2
float Ki = 0; //melhora estabilidade ainda mais //0
float Kd = 10; //"prende" o carrinho da linha - melhor estabilidade //8-10
float P = 0, I = 0, D = 0, PID_valor = 0;

int erro = 0; //erro da posicao em relacao a linha
int erro_anterior = 0;

//Funçao que controla a leitura dos sensores
void leitura_sensores(){
  //Leitura dos sinais dos sensores - valores entre 0 e 1023
  int s0 = analogRead(0);  //mais a esquerda
  int s1 = analogRead(1);  
  int s2 = analogRead(2);  //sensor central
  int s3 = analogRead(3);    
  int s4 = analogRead(4);  //mais a direita
  
  /*Serial.print("0: ");
  Serial.println(s0);
  Serial.print("1: ");
  Serial.println(s1);
  Serial.print("2: ");
  Serial.println(s2);
  Serial.print("3: ");
  Serial.println(s3);
  Serial.print("4: ");
  Serial.println(s4);
  Serial.println("");
  delay(1000);*/
  
  //delay(1000);
  
  //Mudança de escalas - linha preta(<=450) = 1, linha branca(>450) = 0
  if(s0 > 450){ sensor0 = 0; } else{ sensor0 = 1; }
  if(s1 > 450){ sensor1 = 0; } else{ sensor1 = 1; }
  if(s2 > 450){ sensor2 = 0; } else{ sensor2 = 1; }
  if(s3 > 450){ sensor3 = 0; } else{ sensor3 = 1; }
  if(s4 > 450){ sensor4 = 0; } else{ sensor4 = 1; }

  //Vetor de posicao dos sensores
  sensores[0] = sensor0;
  sensores[1] = sensor1;
  sensores[2] = sensor2;
  sensores[3] = sensor3;
  sensores[4] = sensor4;

  if     (sensores[0] == 0 && sensores[1] == 0 && sensores[2] == 0 && sensores[3] == 0 && sensores[4] == 1) { acao = SEGUIR_FRENTE; erro = 4; } //tem que mover robo para a direita muito
  else if(sensores[0] == 0 && sensores[1] == 0 && sensores[2] == 0 && sensores[3] == 1 && sensores[4] == 1) { acao = SEGUIR_FRENTE; erro = 3; } //tem que mover robo para a direita
  else if(sensores[0] == 0 && sensores[1] == 0 && sensores[2] == 0 && sensores[3] == 1 && sensores[4] == 0) { acao = SEGUIR_FRENTE; erro = 2; } //tem que mover robo para a direita
  else if(sensores[0] == 0 && sensores[1] == 0 && sensores[2] == 1 && sensores[3] == 1 && sensores[4] == 0) { acao = SEGUIR_FRENTE; erro = 1; } //tem que mover robo para a direita pouco
  else if(sensores[0] == 0 && sensores[1] == 0 && sensores[2] == 1 && sensores[3] == 0 && sensores[4] == 0) { acao = SEGUIR_FRENTE; erro = 0; } //seguir linha normal
  else if(sensores[0] == 0 && sensores[1] == 1 && sensores[2] == 1 && sensores[3] == 0 && sensores[4] == 0) { acao = SEGUIR_FRENTE; erro = -1; } //tem que mover robo para a esquerda pouco
  else if(sensores[0] == 0 && sensores[1] == 1 && sensores[2] == 0 && sensores[3] == 0 && sensores[4] == 0) { acao = SEGUIR_FRENTE; erro = -2; } //tem que mover robo para a esquerda
  else if(sensores[0] == 1 && sensores[1] == 1 && sensores[2] == 0 && sensores[3] == 0 && sensores[4] == 0) { acao = SEGUIR_FRENTE; erro = -3; } //tem que mover robo para a esquerda
  else if(sensores[0] == 1 && sensores[1] == 0 && sensores[2] == 0 && sensores[3] == 0 && sensores[4] == 0) { acao = SEGUIR_FRENTE; erro = -4; } //tem que mover robo para a esquerda muito
  else if(sensores[0] == 1 && sensores[1] == 1 && sensores[2] == 1 && sensores[3] == 1 && sensores[4] == 1) { acao = PARAR; erro = 0; }      //linha preta continua - para
  else if(sensores[0] == 0 && sensores[1] == 0 && sensores[2] == 0 && sensores[3] == 0 && sensores[4] == 0) { acao = SEM_LINHA; erro = 0; }  //sem linha preta - para tambem

 /* Serial.print(sensores[0]);
  Serial.print(sensores[1]);
  Serial.print(sensores[2]);
  Serial.print(sensores[3]);
  Serial.print(sensores[4]);
  
  Serial.println("");
  Serial.print("Acao: ");
  Serial.println(acao);
  Serial.print("Erro: ");
  Serial.println(erro);*/
}

//Funcao que para os motores
void parar_motor(){
  digitalWrite(IN1, HIGH);  //Para motor esquerda
  digitalWrite(IN2, HIGH); 
  analogWrite(velocidade_E, 0);
  digitalWrite(IN3, HIGH);  //Para motor direita
  digitalWrite(IN4, HIGH);
  analogWrite(velocidade_D, 0);
  delay(100); 
}

//Funcao que controla os motores de acordo com o erro calculado no PID
void motor_controladoPID(){
    P = erro;
    I = I + erro;
    D = erro - erro_anterior;
    PID_valor = (Kp*P) + (Kd*D) + (Ki*I);
    erro_anterior = erro;
     
    if(PID_valor > 0){  //mover robo para a direita
      nova_veloc_dir = veloc_dir - PID_valor;
      nova_veloc_esq = veloc_esq + PID_valor;
    }
    if(PID_valor < 0){  //mover robo para a esquerda
       nova_veloc_dir = veloc_dir - PID_valor;
       nova_veloc_esq = veloc_esq + PID_valor;
    }
    if(PID_valor == 0){ //se nao tiver erro, mantem a velocidade dos motores iguais
       nova_veloc_dir = 50;
       nova_veloc_esq = 50;
    }

    //garante que as velocidades nao vao estourar os valores minimo e maximo (0 e 255)
    if(nova_veloc_dir < 0){
      nova_veloc_dir = 0;
    }
    if(nova_veloc_dir > 255){
      nova_veloc_dir = 255;
    }
    if(nova_veloc_esq < 0){
      nova_veloc_esq = 0;
    }
    if(nova_veloc_esq > 255){
      nova_veloc_esq = 255;
    }
  
    digitalWrite(IN1, LOW); //motor esquerda sentido horario
    digitalWrite(IN2, HIGH);
    analogWrite(velocidade_E, nova_veloc_esq);
    digitalWrite(IN3, LOW);  //motor direita sentido horario
    digitalWrite(IN4, HIGH);
    analogWrite(velocidade_D, nova_veloc_dir);
    delay(300);
    
    digitalWrite(IN1, HIGH); //motor esquerda sentido horario
    digitalWrite(IN2, HIGH);
    analogWrite(velocidade_E, 0);
    digitalWrite(IN3, HIGH);  //motor direita sentido horario
    digitalWrite(IN4, HIGH);
    analogWrite(velocidade_D, 0);
    delay(50);
    /*  Serial.print("Veloc D1: ");
      Serial.println(nova_veloc_dir);
      Serial.print("Veloc E1: ");
      Serial.println(nova_veloc_esq);
   // delay(10); */
}

void setup() {
  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //pinMode(velocidade_D, OUTPUT);
  //pinMode(velocidade_E, OUTPUT);
  Serial.begin(9600);

  delay(3000);
}

void loop() {
  leitura_sensores();
  
  switch(acao){
    case SEGUIR_FRENTE:
      //Serial.println("OK");
      motor_controladoPID();
      break;
      
    case PARAR:
      parar_motor();
      break;
      
    case SEM_LINHA:
      parar_motor();
      /*digitalWrite(IN1, HIGH); //sentido anti horario
      digitalWrite(IN2, LOW);
      analogWrite(velocidade_D, 250); //vira pra direita
      analogWrite(velocidade_E, 0);
      //delay(500);*/
      break;
  } 
}
