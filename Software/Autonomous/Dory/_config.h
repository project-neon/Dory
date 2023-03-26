#include <Arduino.h>

//Motor A LADO ESQUERDO
#define PWMA 10 //Speed control
#define AIN1 5  //Direction
#define AIN2 4  //Direction

//Motor B LADO DIREITO
#define PWMB 9 //Speed control
#define BIN1 7 //Direction
#define BIN2 8 //Direction

#define STBY 6 //Stand-by

// Motors config (H-Bridge)
#define MOTOR_ABS_MAX 255

//Sensor IR
#define RECV_PIN 2 

//Sensores de distância
#define sharp_E A3 //Esquerda
#define sharp_D A2 //Direita

//LED
#define PIN_REDLED 13

//LED RGB
