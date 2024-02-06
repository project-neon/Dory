//outros arquivos da dory
#include "Pinout.h"
#include "Motors.h"
#include "DistanceSensors.h"
#include "IRJudgeControllerSensor.h"

// declarando variáveis do robô
int flag = 0;  //flag 0: esquerda; flag 1: direita
int velMax = 100;


// Estratégia simples da Dory
void simpleStrategy() {

  if (distanceLeft >= minimumDistance && distanceRight >= minimumDistance) {  // Percebe o inimigo à frente
    velMotorL = velMax;
    velMotorR = velMax;
    Serial.print("ATACANDO \t\t");
  } else if (distanceLeft >= minimumDistance || distanceRight >= minimumDistance) {  // Procurando inimigo
    velMotorL = (distanceLeft >= minimumDistance) ? velMax * 0.9 : velMax;           // Achei na esquerda
    velMotorR = (distanceLeft >= minimumDistance) ? velMax : velMax * 0.9;           // Achei na direita
    flag = (distanceLeft >= minimumDistance) ? 0 : 1;
    (distanceLeft >= minimumDistance) ? Serial.print("ESQ \t\t") : Serial.print("DIR \t\t");
  } else {                                                   // Perdi o inimigo
    velMotorL = (flag == 0) ? -velMax * 0.7 : velMax * 0.7;  // Gira pra esquerda ou
    velMotorR = (flag == 0) ? velMax * 0.7 : -velMax * 0.7;  // Gira pra direita
    (flag == 0) ? Serial.print("PROCURANDO ESQ \t\t") : Serial.print("PROCURANDO DIR \t\t");
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
  if (isRunning) {
    simpleStrategy();
  } else {
    velMotorL = 0;
    velMotorR = 0;
  }

  motorsOutput();  // Manda para a ponte H as velocidades

  distanceSensorsPrint();
  motorsPrintVel();
}
