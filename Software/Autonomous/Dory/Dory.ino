// ---- External Libs ---- //
#include <stdlib.h> 
#include <IRremote.h>

// ---- Dory Libs ---- //
#include "_config.h"
#include "Motors.h"
#include "Sensors.h"
#include "Tests.h"

int flag = 0; //0 Esquerda, 1 Direita
int error = 0; //Dist. esquerda - Dist. direita 
int stage = 1; //Variável de controle de cada estágio de acordo com o botão apertado no controle
int distMax = 30; //Limite de distância de captação em milimetros //TODO: Mudar para 700/720, piores dos casos
int distMed = 15;
int strategy = 0; // 4 -> Estratégia simples, 5 -> Estratégia de error, 6 -> Estratégia de desempate, Default: Estratégia simples
int sensorE = 0; //Inicia com um valor inicial para a esquerda
int sensorD = 0; //Inicia com um valor inicial para a direita
int sensorEAnterior = 0; //Última distância medida na esquerda
int sensorDAnterior = 0; //Última distância medida na direita
int margem = 5;   //margem de segurança para a estratégia de erro
int velD = 0; //Velocidade da direita
int velE = 0; //Velocidade da esquerda


IRrecv irrecv(RECV_PIN);  
decode_results results;   

void setup() {
  //Inicia as coisinhas da dory
  Serial.begin(9600);
  Serial.println("Setup Start...  ");

  pinMode(PIN_REDLED,OUTPUT);
  Serial.println("Leds ON  ");

  Motors::init();
  Serial.println("Motors ON  ");

  Sensors::init();
  Serial.println("Sensores ON  ");

  irrecv.enableIRIn();
  Serial.println("Remote Control ON  ");

  Serial.println("Setup Finished!!!  ");
  delay(500);
}

void printDebug() { // Exemplo de saída --> sensorE: 123   sensorD: 321   flag: 1   error: 50
  Serial.print("sensorE: ");
  Serial.print(sensorE);
  Serial.print("   sensorD: ");
  Serial.print(sensorD);
  Serial.print("   flag: ");
  Serial.print(flag);
  Serial.print("   error: ");
  Serial.println(error);
}

void soVaiFrentex(float vel_max){

  velE = vel_max*0.45;
  velD = vel_max;

  Serial.println("amigo, estou aqui!!");
//  return velE, velD; 
}

void estrategiaSimples(float vel_max) {
  printDebug();
  if (sensorE <= distMed && sensorD <= distMed){ //Inimigo à frente 👊👊👊
    velE = vel_max;
    velD = vel_max;
    flag = 2;
    
    return;
  } 
  else if (sensorE <= distMed || sensorD <= distMed) { //Inimigo à esquerda ou à direita 🤛🌀🤜
    velE = (sensorE <= distMed) ? vel_max*0.6 : vel_max*0.8;
    velD = (sensorD <= distMed) ? vel_max*0.6 : vel_max*0.8;
    flag = (sensorE <= distMed) ? 0 : 1;
    return;  

  }
  else if (sensorE <= distMax || sensorD <= distMax) { //Inimigo à esquerda ou à direita 🤛🌀🤜
    velE = (sensorE <= distMax) ? vel_max*0.5 : vel_max*0.9;
    velD = (sensorD <= distMax) ? vel_max*0.5 : vel_max*0.9;
    flag = (sensorE <= distMax) ? 0 : 1;
  }
  else {//👁️👄👁️ Socorro, pra onde que aquele bixo foi? --- Beyblade! 🌀🌀🌀
    velE = (flag == 0) ? -vel_max*0.341 : vel_max*0.341;
    velD = (flag == 0) ? vel_max*0.341 : -vel_max*0.341;
  }
}

void estrategiaDeErro(float vel_max) {
  if(sensorE > distMax) sensorE = sensorEAnterior+100;
  if(sensorD > distMax) sensorD = sensorDAnterior+100;

  error = sensorE - sensorD;
  sensorEAnterior = sensorE;
  sensorDAnterior = sensorD;
  printDebug();

  if (error <= 4 && error >= -4) { //Inimigo à frente 👊👊👊
    velE = vel_max*0.75*0.4;
    velD = vel_max*0.75;
  } 
  else if (error > 4 || error < -4) { //Inimigo à Direita ou Esquerda 🤛🌀🤜
    velE = (error > 4) ? vel_max*0.4*0.8 : -vel_max*0.4*0.8;
    velD = (error > 4) ? -vel_max*0.8 : vel_max*0.8;
    flag = (error > 4) ? 1 : 0;
    return;
  } 
  //👁️👄👁️ Socorro, pra onde que aquele bixo foi? --- Beyblade! 🌀🌀🌀
  else {
    velE = (flag == 1 ) ? 0.8*vel_max : -0.8*0.4*vel_max;
    velD = (flag == 1 ) ? -0.8*vel_max : -0.8*vel_max;
    flag = (flag == 1 ) ? 1 : 0;
  }
}

void estrategiaDesempate(int vel_max) {
  //Se a flag começa com 0, o robô gira pra esquerda
  if (sensorE <= distMax || sensorD <= distMax) {
    strategy = 4; //Vai pra estratégia simples, por exemplo
  } else { // --- Beyblade! 🌀🌀🌀
    velE = -vel_max*0.41;
    velD = vel_max*0.41;
  }
}

void controladorDeEstrategia(float value) {
  if(value == 0x8C22657B){
    strategy = 4;
    Serial.println("Estratégia 1 ---> Simples");
    //desliga os outros leds
    //liga o led dessa estratégia
    }
  else if(value == 0x488F3CBB){
    strategy = 5;
    Serial.println("Estratégia 2 ---> Erro");
    //desliga os outros leds
    //liga o led dessa estratégia
    }
  else if(value == 0x449E79F){
    strategy = 6;
    Serial.println("Estratégia 3 ---> Frentex");
    //Tests::piscaLed(1000, 100); //TODO Adicionar uma cor de Led diferente de acordo com o RGB
    break;
  default:
    break;
  }
}

void controladorDeEstagio(float value) {
  //Caso seja string -> value = String(results.value, HEX);
  Serial.print("Valor lido : ");  
//  Serial.println(value, HEX); //Serial.println(value, DEC);  
  if (value == 544993039) { //  0x9716BE3F 207BEF0F Verifica se a tecla 1 foi acionada 
    stage=1;
    Serial.println("Estagio 1");
  }
  else if (value == 3896860046 && stage == 1) { // 0x3D9AE3F7 E8455D8E Verifica se a tecla 2 foi acionada  
    stage=2;
    Serial.println("Estagio 2");
  }
  else if (value ==  3417827657 && stage == 2) { // 3417827657 0x6182021B CBB7E949 Verifica se a tecla 3 foi acionada  
    stage=3;
    Serial.println("Estagio 3");
  }
  else if (stage==3 && (value == 544993039 || value == 3896860046 )){ //CBB7E949 0x9716BE3F 0x9716BE3F 0x3D9AE3F7
    stage = 0;
  }
  else if (strategy == 0) {
    controladorDeEstrategia (value);
  }
}

void loop() {

  sensorD = Sensors::get_valor(sharp_D);
  sensorE = Sensors::get_valor(sharp_E);
  
  if (irrecv.decode(&results)) {  //Chegou alguma coisa do controle?
    controladorDeEstagio(results.value);
    Serial.println(results.value, DEC); //Caso seja string -> value = String(results.value, HEX);
    irrecv.resume(); //Lê o proximo valor
  } 

  if (stage==1) {  
    digitalWrite(PIN_REDLED, HIGH);
    delay(50);
    digitalWrite(PIN_REDLED, LOW);
    delay(50);
  }  

  else if (stage==2) { 
    //TODO: descobrir qual é o Power máximo que a gente pode passar para as funções 
    switch (strategy) {
    case 4:
      estrategiaSimples(90);
    case 5:
      estrategiaDeErro(90);
    case 6:
      soVaiFrentex(90);
    default:
      // Tests::testeSensores();
      //estrategiaSimples(90);
      estrategiaDeErro(90);
      //soVaiFrentex(90);
    }
    Motors::driveTank(velE,velD);
    
  }
  else if (stage==3){ //Estágio 3 ou 0
    Serial.println("S T O P");
    digitalWrite(PIN_REDLED, HIGH);
    Motors::stop();
  }  

}
