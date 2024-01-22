#include <IRremote.hpp>  // Version 4.2.0
int mode = 0;

void IRJudgeControllerSensorInit() {
  IrReceiver.begin(JUDGE_CONTROLLER_PIN, ENABLE_LED_FEEDBACK);
}

void checkSensorIR() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    switch (IrReceiver.decodedIRData.command) {
      // caso 1: liga o led p sabermos que o IR tá funcionando
      case 0x1:
      case 0x11:
        Serial.println("Apertou o botão 1");
        mode =1;
        break;
        // caso 2: inicia a programação do robô (como? não faço ideia, mas vamos descobrir)
      case 0x2:
      case 0x12:
        Serial.println("Apertou o botão 2");
        mode = 2;

        break;
        // caso 3: finaliza a estratégia (como? tb não sei)
      case 0x3:
      case 0x13:
        Serial.println("Apertou o botão 3");
        mode = 3;
        break;
    }

    IrReceiver.resume();
  }
}