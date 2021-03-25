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

void setSpeed(int);

void setup() {
  Serial.begin(9600);
  stepper1.begin(250, MICROSTEPS);
  stepper2.begin(250, MICROSTEPS);
}

void loop() {
  setSpeed(240);
  controller.rotate(5, -5);
}

void setSpeed(int speed){
  stepper1.setRPM(speed);
  stepper2.setRPM(speed);
}