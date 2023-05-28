#include "Door.h"

float Door::measureEchoSignalDuration() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(this->lowHighTriggerPinTimeoutInMicroseconds);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(this->highLowTriggerPinTimeoutInMicroseconds);
  digitalWrite(triggerPin, LOW);

  return pulseIn(echoPin, HIGH);
}

Door::Door(byte triggerPin, byte echoPin, void (*onGoing)()) {
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
  this->onGoing = onGoing;

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void Door::init() {
  this->baseEchoSignalDuration = this->measureEchoSignalDuration();
}

void Door::update() {
  if(this->measureEchoSignalDuration() + this->echoSignalDurationMaxError >= this->baseEchoSignalDuration) {
    this->isGoing = false;
  } else {
    if (!this->isGoing) {
    this->isGoing = true;
    this->onGoing();
    }
  }
}