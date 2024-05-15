#include <Arduino.h>

// Definição dos pinos

// Motores
#define MOTOR_RIGHT_IN1_PIN 27
#define MOTOR_RIGHT_IN2_PIN 26

#define MOTOR_LEFT_IN1_PIN 25
#define MOTOR_LEFT_IN2_PIN 33

#define STANDBY_PIN 32  // Quando HIGH, liga a ponte H. Quando LOW, desliga a ponte H

// Sensor IR
#define JUDGE_CONTROLLER_PIN 15

// Sensores de distância
#define DIST_SENSOR_SHARP_LEFT_PIN 4
#define DIST_SENSOR_SHARP_RIGHT_PIN 15
#define DISTANCE_ARRAY_LENGHT 20  // Tamanho da lista utilizada para armazenar as medidas do Sharp