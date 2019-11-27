#include "hardwareConfig.h"
using namespace pinWriters;
PinHandler* Handlers[4];
void initPins()
{
	Handlers[0] = new MCPHandler(0);
	Handlers[1] = new MCPHandler(4);
	Handlers[2] = new MCPHandler(2);
	Handlers[3] = new NativeHandler();
}