#include "_config.h"
#include "Motors.h"
// Initialize pins
void Motors::init(){
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY,HIGH);
}

// saída AIN1-2 : left (esquerda) // saída BIN1-2 : right (direita)

void Motors::driveTank(float m1, float m2){

  // Limit Powers
  m1 = min(max(m1, -100), 100);
  m2 = min(max(m2, -100), 100);
  
  // Map powers
  int powerOutA = abs(m1 * (MOTOR_ABS_MAX / 100.0));
  int powerOutB = abs(m2 * (MOTOR_ABS_MAX / 100.0));
  
  // Set power
  analogWrite(PWMA,powerOutA);
  analogWrite(PWMB,powerOutB);
  
  // Set Directions
  digitalWrite(AIN1, m1 < 0 ? LOW : HIGH);
  digitalWrite(AIN2, m1 < 0 ? HIGH : LOW);

  digitalWrite(BIN1, m2 > 0 ? LOW : HIGH);
  digitalWrite(BIN2, m2 > 0 ? HIGH : LOW);

}

void Motors::stop(){
  // Set power (0)
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);

  // Set both DIRS to 0
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
}
