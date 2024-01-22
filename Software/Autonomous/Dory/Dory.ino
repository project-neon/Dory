//outros arquivos da dory
#include "Pinout.h"
#include "Motors.h"
#include "DistanceSensors.h"
#include "IRJudgeControllerSensor.h"


// declarando variáveis do robô

int sensorL = 0; //Inicia com um valor inicial para a esquerda
int sensorR = 0; //Inicia com um valor inicial para a direita
int margem = 5;   //margem de segurança para a estratégia de erro
int velR = 0; //Velocidade da direita
int velL = 0; //Velocidade da esquerda
int flag = 0; //flag 0: esquerda; flag 1: direita 



void setup() {
  //inicia as coisas da dory
  Serial.begin(115200);

  motorsInit();
  Serial.println("Motores ON  ");

  distanceSensorsInit();
  Serial.println("Sensores Distancia ON  ");

  IRJudgeControllerSensorInit();
  Serial.println("Remote Control ON ");

  Serial.println("Setup Finished!!!");
  delay(500);
}

void loop() {

  checkSensorIR(); //tá fazendo o check do sensor aqui
//checa o botão e muda o mode para qual botão foi clicado


//criando a estratégia da Dory:

  void simplesStrategy(float vel_max){
    printDebug();
    if (sensorL <= distMed && sensorR <= distMed){ //percebe o inimigo à frente
    velL = vel_max;
    velR = vel_max;
    }
    return;
  }
  else if(sensorL <= distMed || sensorR <= distMed){ //procurando inimigo
    velL = (sensorL <= distMax) ? vel_max*0.5 : vel_max*0.9; //achei na esquerda
    velR = (sensorR <= distMax) ? vel_max*0.5 : vel_max*0.9; //achei na direita
    flag = (sensorL <= distMax) ? 0 : 1;
  }
  else {//perdi o inimigo
    velL = (flag == 0) ? -vel_max*0.341 : vel_max*0.341; //gira pra esquerda
    velR = (flag == 1) ? vel_max*0.341 : -vel_max*0.341; //gira pra direita
  }
}


//o controle muda o mode, 
// o mode define oq o robô vai fazer -> 3: o 0 - nada; 1 - roda a estratégia e 2- para tudo.

//vê qual mode eu estou e como agir em cada 
  switch (mode){
    case 1:
      //mode 1
      break;
    case 2:
      //mode 2
      /*posso criar mais switch cases aqui para escolha
      das estratégias, como na linha 199 pra baixo*/
      simpleStrategy(90); // =======>>>> vi esse noventa no código e copiei tb, mas não entendi oq significa kkkkkkkk
      //estratégia da dory
      break;
    case 3:
      //mode 3
      //para o robô (colocar que a velocidade é 0)
      break;
    default: //tipo o else (esse é qqr mode q não seja o 1, 2 e 3.)
      //pare
      break;
  }











  readDistanceSensorsValues();  //Atualiza os valores da distância
  if (distanceLeft > mininumDistance && distanceRight > mininumDistance) velMotorR = velMotorL = -50;
  else velMotorR = velMotorL = 0;
  motorsOutput();  //Manda para a ponte H as velocidades

  distanceSensorsPrint();
  motorsPrintVel();
}
