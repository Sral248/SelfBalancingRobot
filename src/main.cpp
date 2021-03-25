#include <Arduino.h>
#include <Wire.h>
#include "BasicStepperDriver.h"
#include "MultiDriver.h"
#include "SyncDriver.h"

#define MOTOR_STEPS 200
#define RPM 60
#define MICROSTEPS 1

BasicStepperDriver stepper1(MOTOR_STEPS, 3, 2);
BasicStepperDriver stepper2(MOTOR_STEPS, 5, 4);
SyncDriver controller(stepper1, stepper2);

void setup() {
  Serial.begin(9600);
  stepper1.begin(250, MICROSTEPS);
  stepper2.begin(250, MICROSTEPS);
}

void loop() {
  controller.rotate(90*5, -90*5);
  delay(1000);
  controller.rotate(-90*5, 90*5);
  delay(5000);
}