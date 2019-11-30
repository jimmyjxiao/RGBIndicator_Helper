#pragma once
#include "LEDWriter.h"
#include "PinWriter.h"

// How many different ways are we using to write physical pins? In this example hardwareConfig, we are using 3 MCP23017s and some pins off the main microcontroller itself.
// With non-addressable LEDs, the number of pins you need adds up very quickly with 3 per LED!
extern pinWriters::PinHandler* Handlers[4];

void initializeHardware();

namespace led_definitions {
	// example LED configuration: We have two LEDs that are Common Cathode, one that is common annode, and two that are WS2812 addressable
	constexpr commonCathodeRGBLED LED1 = commonCathodeRGBLED(2, 25, 38);
	constexpr commonCathodeRGBLED LED2 = commonCathodeRGBLED(3, 28, 33);
	constexpr commonAnnodeRGBLED LED3 = commonAnnodeRGBLED(4, 19, 23);
	constexpr addressableLED LED4 = addressableLED(0);
	constexpr addressableLED LED5 = addressableLED(1);
}


constexpr RGB_LED* LEDs[] = { &led_definitions::LED1, &led_definitions::LED2, &led_definitions::LED3, &led_definitions::LED4, &led_definitions::LED5};