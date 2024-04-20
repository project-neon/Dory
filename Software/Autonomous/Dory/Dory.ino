// Outros arquivos da dory
#include "Pinout.h"
#include "Motors.h"
#include "DistanceSensors.h"
#include "IRJudgeControllerSensor.h"

// Declara as variáveis do robô
int flag = 0;  //flag 0: esquerda; flag 1: direita
int velMaxR = 92;
int velMaxL = 90.5;


// Criação da estratégia simples da Dory
void simpleStrategy() {

  if (distanceLeft >= minimumDistance && distanceRight >= minimumDistance) {  // Quando o inimigo é percebido à frente
    velMotorL = velMaxL;
    velMotorR = velMaxR;
    Serial.print("ATACANDO \t\t");
  } else if (distanceLeft >= minimumDistance || distanceRight >= minimumDistance) {  // Procurando o inimigo
    velMotorL = (distanceLeft >= minimumDistance) ? velMaxR * 0.7 : velMaxL;           // Achei na esquerda
    velMotorR = (distanceLeft >= minimumDistance) ? velMaxR : velMaxL * 0.7;           // Achei na direita
    flag = (distanceLeft >= minimumDistance) ? 0 : 1;
    (distanceLeft >= minimumDistance) ? Serial.print("ESQ \t\t") : Serial.print("DIR \t\t");
  } else {                                                   // Quando perco o inimigo, duas opções dado a última leitura do sensor:
    velMotorL = (flag == 0) ? -velMaxR * 0.4 : velMaxL * 0.4;  // Gira pra esquerda ou
    velMotorR = (flag == 0) ? velMaxR * 0.4 : -velMaxL * 0.4;  // Gira pra direita
    (flag == 0) ? Serial.print("PROCURANDO ESQ \t\t") : Serial.print("PROCURANDO DIR \t\t");
  }

} 

void setup() {
  // Inicia a Dory
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
  // Checa o sensor
  checkSensorIR();  // De acordo com o botão clicado, muda o mode
  readDistanceSensorsValues();  // Atualiza os valores da distância

  // Roda a programação de acordo com os casos do sensor de IR
  if (isRunning) {
    simpleStrategy();
  } else {
    velMotorL = 0;
    velMotorR = 0;
  }

  motorsOutput();  // Manda as velocidades para a ponte H

  distanceSensorsPrint();
  motorsPrintVel();
}
