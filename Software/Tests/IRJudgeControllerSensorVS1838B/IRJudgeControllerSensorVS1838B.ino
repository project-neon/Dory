#include <IRremote.hpp>  // Version 4.2.0

#define JUDGE_CONTROLLER_PIN 15

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(JUDGE_CONTROLLER_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    switch (IrReceiver.decodedIRData.command) {
      case 0x1:
      case 0x11:
        Serial.println("Apertou o botão 1");
        break;
      case 0x2:
      case 0x12:
        Serial.println("Apertou o botão 2");
        break;
      case 0x3:
      case 0x13:
        Serial.println("Apertou o botão 3");
        break;
      case 0x4:
      case 0x14:
        Serial.println("Apertou o botão 4");
        break;
      case 0x5:
      case 0x15:
        Serial.println("Apertou o botão 5");
        break;
      case 0x6:
      case 0x16:
        Serial.println("Apertou o botão 6");
        break;
    }

    IrReceiver.resume();
  }
}