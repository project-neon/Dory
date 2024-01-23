//outros arquivos da dory
#include "Pinout.h"
#include "Motors.h"
#include "DistanceSensors.h"
#include "IRJudgeControllerSensor.h"

// declarando variáveis do robô
int flag = 0;  //flag 0: esquerda; flag 1: direita 
int velMax = 100;


// Estratégia da Dory
void simpleStrategy() {
  if (distanceLeft >= minimumDistance && distanceRight >= minimumDistance) {  // Percebe o inimigo à frente
    velMotorL = velMax;
    velMotorR = velMax;
  } else if (distanceLeft >= minimumDistance || distanceRight >= minimumDistance) {  // Procurando inimigo
    velMotorL = (distanceLeft >= minimumDistance) ? velMax * 0.5 : velMax * 0.9;     // Achei na esquerda
    velMotorR = (distanceRight >= minimumDistance) ? velMax * 0.5 : velMax * 0.9;    // Achei na direita
    flag = (distanceLeft >= minimumDistance) ? 0 : 1;
  } else {                                                       // Perdi o inimigo
    velMotorL = (flag == 0) ? -velMax * 0.341 : velMax * 0.341;  // Gira pra esquerda
    velMotorR = (flag == 1) ? velMax * 0.341 : -velMax * 0.341;  // Gira pra direita
  }
}

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

  // Tá fazendo o check do sensor aqui
  checkSensorIR();  // Checa o botão e muda o mode para qual botão foi clicado

  readDistanceSensorsValues();  // Atualiza os valores da distância

  // O controle muda o mode
  // O mode define oq o robo vai fazer -> 3: o 0 - nada; 1 - roda a estrategia e 2- para tudo.

  // Ve qual mode eu estou e como agir em cada
  switch (mode) {
    case 1:
      // Mode 1
      break;
    case 2:
      // Mode 2
      /* Posso criar mais switch cases aqui para escolha
      das estratégias, como na linha 199 pra baixo*/
      simpleStrategy();
      // Estratégia da dory
      break;
    case 3:
      // Mode 3
      // Para o robô (colocar que a velocidade é 0)
      break;
    default:  // Tipo o else (esse é qqr mode q não seja o 1, 2 e 3.)
      // Pare
      break;
  }

  motorsOutput();  // Manda para a ponte H as velocidades

  distanceSensorsPrint();
  motorsPrintVel();
}
