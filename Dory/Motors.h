#include "_config.h"

#ifndef MOTORS_H
#define MOTORS_H


class Motors{
  public:
    static void init(); // Initialize pins 
    static void driveTank(float m1, float m2); // Set power of both motors
    static void stop(); // Set state as Iddle (Turn off motors)
};

#endif
