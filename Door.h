#ifndef DoorModule
#define DoorModule

#include "Arduino.h"

class Door {
  private:
    //NOTE: HC-SR04 ultrasonic distance sensor's properties
    const char lowHighTriggerPinTimeoutInMicroseconds = 2;
    const char highLowTriggerPinTimeoutInMicroseconds = 10;
    //NOTE: environment's properties
    const float echoSignalDurationMaxError = 95.54;
    //---
    byte triggerPin, echoPin;
    void (*onGoing)();
    float baseEchoSignalDuration;
    bool isGoing;
    float measureEchoSignalDuration();

  public:
    Door(byte triggerPin, byte echoPin, void (*onGoing)());
    void init();
    void update();
};

#endif