const int motorsInputPins[4] = { MOTOR_RIGHT_IN1_PIN, MOTOR_RIGHT_IN2_PIN, MOTOR_LEFT_IN1_PIN, MOTOR_LEFT_IN2_PIN };  // Lista com os pinos de entrada dos motors

// Estabelecendo os canais PWM que serão utilizados
const int chRightIN1 = 0;  // Canal PWM 0 que irá ser vinculado ao pino 21 da ponte H
const int chRightIN2 = 1;  // Canal PWM 1 que irá ser vinculado ao pino 19 da ponte H
const int chLeftIN1 = 2;   // Canal PWM 2 que irá ser vinculado ao pino 23 da ponte H
const int chLeftIN2 = 3;   // Canal PWM 3 que irá ser vinculado ao pino 22 da ponte H

// Configurando o PWM
const int freq = 50;                           // Frequência do PWM, definida em 50Hz
const int resolution = 12;                     // Resolução do PWM, 12 bits, de 0 a 4095.
const int totalBits = pow(2, resolution) - 1;  // Magnitude máxima que o motor recebe e interpreta como 100% da velocidade

// Variáveis responsáveis pela velocidade
int velMotorR = 0;        // Vel direita, vai de [-100, 100]
int velMotorL = 0;        // Vel esquerda, vai de [-100, 100]
int velMotorRMapped = 0;  // Vel direita, vai de [-totalBits, totalBits]
int velMotorLMapped = 0;  // Vel esquerda, vai de [-totalBits, totalBits]
int somaVel = 25;         // De quanto em quanto a vel aumenta ou diminui no loop

void motorsInit() {
  pinMode(STANDBY_PIN, OUTPUT);
  digitalWrite(STANDBY_PIN, HIGH);

  for (int i = 0; i < 4; i++) {
    pinMode(motorsInputPins[i], OUTPUT);   // Fazemos os pinos MOTOR_RIGHT_IN1_PIN, MOTOR_RIGHT_IN2_PIN, MOTOR_LEFT_IN1_PIN e MOTOR_LEFT_IN2_PIN serem OUTPUTs
    ledcSetup(i, freq, resolution);        // Atribui a todos os canais i (= 0, 1, 2, 3) a frequencia de 50Hz com resolucao de 12bits.
    ledcAttachPin(motorsInputPins[i], i);  // Associamos os pinos MOTOR_RIGHT_IN1_PIN, MOTOR_RIGHT_IN2_PIN, MOTOR_LEFT_IN1_PIN e MOTOR_LEFT_IN2_PIN aos canais i (= 0, 1, 2, 3) respectivamente.
  }
}

void motorsOutput() {
  // IN1 --> Horário, Positivo -------- IN2 --> Anti-horário, Negativo
  // A velocidade zero é um caso especial. Então em casos gerais:
  // Quando estamos indo do Horário pro Anti-Horário (IN1 --> IN2), o 0 deve ser do canal IN1
  // Quando estamos indo do Anti-Horário pro Horário (IN2 --> IN1), o 0 deve ser do canal IN2

  // Precisa passar pelo 0 sempre que muda de direção. O valor Mapped ainda tem guardado a velocidade do último loop nele.
  if (velMotorR > 0 != velMotorRMapped > 0) ledcWrite((velMotorRMapped > 0) ? chRightIN2 : chRightIN1, 0);
  if (velMotorL > 0 != velMotorLMapped >= 0) ledcWrite((velMotorLMapped > 0) ? chLeftIN2 : chLeftIN1, 0);

  //Mapeia o valor da escala [-100, 100] para a escala do PWM
  velMotorRMapped = map(velMotorR, -100, 100, -totalBits, totalBits);
  velMotorLMapped = map(velMotorL, -100, 100, -totalBits, totalBits);

  //Envia para o motor o sinal PWM
  ledcWrite((velMotorR > 0) ? chRightIN2 : chRightIN1, abs(velMotorRMapped));
  ledcWrite((velMotorL > 0) ? chLeftIN2 : chLeftIN1, abs(velMotorLMapped));
}

void motorsPrintVel() {
  Serial.println("\t\tMotor_E: " + (String)velMotorLMapped + "\tMotor_D: " + (String)velMotorRMapped);
}
