#pragma once
#include "LEDWriter.h"
#include "PinWriter.h"

extern pinWriters::PinHandler* Handlers[4];
void initPins();
constexpr commonCathodeRGBLED LED1 = commonCathodeRGBLED(2,25,38);
constexpr commonCathodeRGBLED LED2 = commonCathodeRGBLED(3,28,33);
constexpr RGB_LED* LEDs[] = {};