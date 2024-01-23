#include <IRremote.hpp>  // Version 4.2.0

bool isRunning = false;

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
        break;
      case 0x2:
      case 0x12:
        Serial.println("Apertou o botão 2");
        isRunning = true;
        break;
      case 0x3:
      case 0x13:
        Serial.println("Apertou o botão 3");
        isRunning = false;
        break;
    }

    IrReceiver.resume();
  }
}