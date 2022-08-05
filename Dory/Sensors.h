#include "_config.h"

#ifndef SENSORS_H
#define SENSORS_H

class Sensors{
  public:
  
    static void init();

    static int get_valor(int sensorPin);
};

#endif
