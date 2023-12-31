#include <Arduino.h>

// Pinos Motores
#define MOTOR_RIGHT_IN1_PIN 27
#define MOTOR_RIGHT_IN2_PIN 26

#define MOTOR_LEFT_IN1_PIN 25
#define MOTOR_LEFT_IN2_PIN 33

#define STANDBY_PIN 32  // Quando HIGH, liga a ponte H, quando LOW, desliga a ponte H

// Pino sensor IR
#define JUDGE_CONTROLLER_PIN 15

// Pinos sensores de distância
#define DIST_SENSOR_SHARP_LEFT_PIN 4
#define DIST_SENSOR_SHARP_RIGHT_PIN 2
#define DISTANCE_ARRAY_LENGHT 20  // Tamanho da lista utilizada para armazenar as medidas do Sharp