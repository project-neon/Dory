#include "Sensors.h"
#include "_config.h"


// Sensor do tipo GP2Y0A41SK0F
// https://www.robocore.net/sensor-robo/sensor-de-distancia-infra-vermelho-sharp-4-30cm
// Se acharmos que as medidas não estão batendo, também podemos fazer assim: https://github.com/sharpsensoruser/sharp-sensor-demos/blob/324f3063d239b668d29f2045127f712240ef4391/sharp_gp2y0a41sk0f_demo/sharp_gp2y0a41sk0f_demo.ino

void Sensors::init() {
  pinMode(sharp_E, INPUT); //Esquerda
  pinMode(sharp_D, INPUT); //Direita
} 

int Sensors::get_valor(int sensorPin){
  int sensorValue= analogRead(sensorPin);
  return 13*pow(sensorValue * 0.0048828125 , -1);
}