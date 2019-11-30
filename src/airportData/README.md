# This is an example data handler.

## Overview

The main loop in the `.ino` sketch will pass the HTTP body content string from the API into `extractActionsFromXML` which returns actions, which the loop then executes by lighting the LEDs corresponding to the airports returned by the API data.
It pulls the METAR data for each airport, then assigns a corresponding color to it and displays it.

## Notes

* Notice how in `Airport.h`, the Airports are defined in an Array that references the LED definitions in your `hardwareConfig.h`
* There's no code in these classes that handle the intricacies of port expanders (MCP23017), addressable LEDs, etc, that's all handled by the framework