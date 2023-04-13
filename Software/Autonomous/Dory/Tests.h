#include "_config.h"

#ifndef TESTES_H
#define TESTES_H

class Tests{
  public:
    static void testeMotores(int Power);
    static void testeSensores();
    static void testeSensoresEMotores(int Pot2);
    static void trackingTest(int Pot1);
    static void piscaLed(int frequencia,int piscagens);
};

#endif
