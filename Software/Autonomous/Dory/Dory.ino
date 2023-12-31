#include "Pinout.h"
#include "Motors.h"
#include "DistanceSensors.h"

void setup() {
  Serial.begin(115200);

  motorsInit();
  Serial.println("Motores ON  ");

  distanceSensorsInit();
  Serial.println("Sensores Distancia ON  ");

  Serial.println("Remote Control OFF  ");

  Serial.println("Setup Finished!!!");
  delay(500);
}

void loop() {

  readDistanceSensorsValues();  //Atualiza os valores da distância
  if (distanceLeft > mininumDistance && distanceRight > mininumDistance) velMotorR = velMotorL = -50;
  else velMotorR = velMotorL = 0;
  motorsOutput();  //Manda para a ponte H as velocidades

  distanceSensorsPrint();
  motorsPrintVel();
}
