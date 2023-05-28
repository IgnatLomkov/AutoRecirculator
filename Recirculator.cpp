#include "Recirculator.h"

void Recirculator::turnOn() {
  digitalWrite(this->pin, HIGH);
}

void Recirculator::turnOff() {
  digitalWrite(this->pin, LOW);
}

Recirculator::Recirculator(int pin) {
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

void Recirculator::update() {
  if (this->currentPeopleCount < 0) {
     this->currentPeopleCount = 0;
  }

  if(this->currentPeopleCount < this->peopleCountToTurnOn) {
    this->turnOff();
  } else {
    this->turnOn();
  }
}