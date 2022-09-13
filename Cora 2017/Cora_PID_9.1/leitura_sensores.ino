void leitura_sensores() {
  ses[0] = digitalRead(sensores[0]);
  ses[1] = digitalRead(sensores[1]);
  ses[2] = digitalRead(sensores[2]);
  ses[3] = digitalRead(sensores[3]);
  ses[4] = digitalRead(sensores[4]);
  ses[5] = digitalRead(sensores[5]);
  ses[6] = digitalRead(sensores[6]);
  ses[7] = digitalRead(sensores[7]);
  ses[8] = digitalRead(sensores[8]);

  if      (ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -8;}
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -7;}
  else if (ses[0] == 1 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -6;}
  else if (ses[0] == 1 && ses[1] == 0 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -5;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -4;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -3;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -2;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = -1;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 0;} // posição ideal
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 1;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 2;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 3;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 1 && ses[8] == 1) {acao = frente; erro = 4;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 0 && ses[8] == 1) {acao = frente; erro = 5;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 1) {acao = frente; erro = 6;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 0) {acao = frente; erro = 7;}
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 0) {acao = frente; erro = 8;}

 /* if        (ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = -6;}
  else if (ses[1] == 0 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = -5;}
  else if (ses[1] == 1 && ses[2] == 0 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = -4;}
  else if (ses[1] == 1 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = -3;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = -2;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = -1;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = 0;} // posição ideal
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = 1;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1) {acao = frente; erro = 2;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 1) {acao = frente; erro = 3;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 1) {acao = frente; erro = 4;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 0 && ses[7] == 0) {acao = frente; erro = 5;}
  else if (ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0) {acao = frente; erro = 6;}*/
  
  else if ((ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)||
             (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)||
             (ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)||
             (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 0 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)){acao = E90; erro = 0;} //curva 90 esquerda
   
  else if ((ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 0)||
             (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 0)||
             (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 0)||
             (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 0 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 0 && ses[8] == 0)){acao = D90; erro = 0;} //curva 90 direita
           
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0) {acao = marcador;} //marcador

  else if ((ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1  && ses[6] == 1 && ses[7] == 0 && ses[8] == 0)||
             (ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1  && ses[6] == 1 && ses[7] == 1 && ses[8] == 0)||
             (ses[0] == 0 && ses[1] == 0 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1  && ses[6] == 1 && ses[7] == 1 && ses[8] == 0)||
             (ses[0] == 0 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 1  && ses[6] == 1 && ses[7] == 0 && ses[8] == 0)){acao = bifT;}//bifurcação em T
           
  else if ((ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 0 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0)||
              (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0)) {acao = saidaD;}//rotatoria
  else if ((ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 0 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1)||
              (ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1))  {acao = saidaE;}//rotatoria
  
  else if (ses[0] == 1 && ses[1] == 1 && ses[2] == 1 && ses[3] == 1 && ses[4] == 1 && ses[5] == 1 && ses[6] == 1 && ses[7] == 1 && ses[8] == 1) {acao = preto; }//tudo preto
  else if (ses[0] == 0 && ses[1] == 0 && ses[2] == 0 && ses[3] == 0 && ses[4] == 0 && ses[5] == 0 && ses[6] == 0 && ses[7] == 0 && ses[8] == 0) {acao = branco;}//tudo branco    
}
