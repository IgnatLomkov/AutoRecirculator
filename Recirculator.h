#ifndef RecirculatorModule
#define RecirculatorModule

#include "Arduino.h"

//NOTE: it is actually led right now
class Recirculator {
  private:
    //NOTE: config
    const char peopleCountToTurnOn = 3;
    //---
    int pin;
    void turnOn();
    void turnOff();

  public:
    Recirculator(int pin);
    short int currentPeopleCount;
    void update();
};

#endif