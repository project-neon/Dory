#include <Arduino.h>

// Definição dos pinos

// Motores
#define MOTOR_RIGHT_IN1_PIN 26
#define MOTOR_RIGHT_IN2_PIN 27
#define MOTOR_LEFT_IN1_PIN 32
#define MOTOR_LEFT_IN2_PIN 33

#define STANDBY_PIN 25  // Quando HIGH, liga a ponte H. Quando LOW, desliga a ponte H

// Sensor IR
#define JUDGE_CONTROLLER_PIN 36

// Sensores de distância
#define DIST_SENSOR_SHARP_LEFT_PIN 34
#define DIST_SENSOR_SHARP_RIGHT_PIN 39

// SCL, SDA para a comunicação I2C
// Como usamos os pinos padrões da I2C, a biblioteca Wire.h cuida
// disso automaticamente para nós. Então no fundo, essas variáveis não seriam necessárias.
#define SCL_PIN 22
#define SDA_PIN 21

// Define o pino XSHUT do sensor de distância VL53L0X
// Quando LOW, esse pino desliga o sensor e permite o endereçamento dos outros
int VL53LOX_XSHUT_LIST_PINS[2] = {18, 23};