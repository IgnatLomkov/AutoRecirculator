#include "Recirculator.h"
#include "Door.h"

Recirculator MainRecirculator(6);
Door EntranceDoor(2, 3, []() -> void {
  MainRecirculator.currentPeopleCount++;
  MainRecirculator.update();
  Serial.print("+");
});
Door ExitDoor(4, 5, []() -> void {
  MainRecirculator.currentPeopleCount--;
  MainRecirculator.update();
  Serial.print("-");
});

void setup() {
  EntranceDoor.init();
  ExitDoor.init();

  Serial.begin(9600);
}

void loop() {
  EntranceDoor.update();
  ExitDoor.update();
  //NOTE: delay for HC-SR04 ultrasonic distance sensorto code everything sync
  delay(150);
}