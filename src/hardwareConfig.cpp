#include "hardwareConfig.h"
using namespace pinWriters;
PinHandler* Handlers[4]; // Make sure the size on this array matches the header file
void initPins()
{
	Handlers[0] = new NativeHandler({ 14,0,2 }); // takes an array of all **physical** pin numbers that will be used. Note this needs to be the physical pin numbers, not virtual
	Handlers[1] = new MCPHandler(0); // Constructor for MCPhandler takes the i2c address of the MCP23017
	Handlers[2] = new MCPHandler(4);
	Handlers[3] = new MCPHandler(2);
}
void initializeHardware()
{
	initPins();
	addressableLED::initializeLEDs(17, 5); // Delete if you're not using addressable LEDs. If you are, this function takes (# of LEDs, Pin).
}
