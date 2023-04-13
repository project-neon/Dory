#include "_config.h"
#include "Motors.h"
#include "Sensors.h"
#include "Tests.h"

void testeMotores(int Power){ 
  Serial.print("Testando motores...");
  Motors::stop();
  Motors::driveTank(Power,Power);   //vai para frente
  delay(3000);
  Motors::driveTank(-Power,Power);  //gira para esquerda  
  delay(3000);
  Motors::driveTank(Power,-Power);  //gira para direita
  delay(3000);
  Motors::driveTank(-Power,-Power); //vai para trás
  delay(3000);
  Motors::stop();
  delay(20);
  return;
}

void testeSensores() {
  //TODO: Testar os testes de acordo com o sensor novo!
  int sensorE = Sensors::get_valor(sharp_E);
  int sensorD = Sensors::get_valor(sharp_D);
  Serial.print("sensorE: ");
  Serial.print(sensorE);
  Serial.print("    sensorD: ");
  Serial.print(sensorD);
  Serial.println("");
}

void testeSensoresEMotores(int Power) {
  //TODO: Testar os testes de acordo com o sensor novo!
  testeSensores();
  testeMotores(Power);
}

void piscaLed(int frequencia,int piscagens) {
  while(millis()%(piscagens*frequencia*2)!=0) {
      if((millis()/frequencia)%2 == 0) digitalWrite(PIN_REDLED,1);
      else digitalWrite(PIN_REDLED,0);
  }
  digitalWrite(PIN_REDLED,0);
}
