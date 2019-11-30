# RGBIndicator_Helper

This is a framework that helps you create solutions that use a lot of RGB LEDs that are used to indicate statuses of various things pulled from web APIs. It's written for ESP8266, but I don't imagine it would be especially hard to adapt to other microcontroller platforms, especially if they're arduino based. It's got some nice abstraction logic to help handle multiple port expanders (MCP23017) and addressable LEDs (WS2812).

## Usage
### Understanding virtual pin numbers
#### Reasoning
This is mostly if you're using non-addressable LEDs, because those will need 3 output pins per LED. This means that if we wanted 20 LEDs, for example, there are 60 outputs that need to be controlled. This almost certainly neccessitates use of port expanders. This library supports the MCP23017, which has a nice i2c interface, that's even nicer when we've used the Adafruit library to abstract it down to a very simple few function calls. For solutions with 20 LEDs, for example, since we have 3 port expanders and we're also using the native GPIO pins, it will quickly get confusing which pin connects where, both in software and physically. Plus, since the 16 ports on the port expanders don't divide with the three outputs per LED evenly, some LEDs will split between output ports on different chips.
#### How virtual pin numbers work
Basically, if we have chips capable of outputting, referred to as `handlers` from now on, virtual pin numbers 0-19 in software will translate to calls on physical pins 0-19 on `handlers[0]` (the first chip). However, pins 20-39 refer to pins 0-19 on `handlers[1]` (the second chip), and so on. So for example, pin 46 refers to physical pin 6 on the third chip. This is very easy to work with if you wire the virtual pin numbers to the corresponding row numbers on a breadboard. Once you've done that, you can forget about the fact that you are even using port expanders and just think about which breadboard row number you need to connect LEDs to and their corresponding LED definitions in `hardwareConfig.h` will just be the breadboard row number.
### Writing hardwareConfig.h/cpp
1. First, how many ways are we using GPIO pins? For example, if we have 3 different MCP23017 port expanders, plus also using the pins directly on the microcontroller, we need our `handlers` array size to be of size `4`
2. Initialize each of these handlers in `hardwareConfig.cpp`. Also the extern array definition needs to match the size in the header file.
3. Define LEDs. There are two classes, `commonAnnodeRGBLED` and `commonCathodeRGBLED` that are pretty self explanatory, and just take virtual pin numbers as constructors. The `addressableLED` class takes the index of the LED (for example, for the fifth LED in the series, the `n` will be 4). Then put them in the `LEDs` array as shown in the example.

### Writing data handlers
Base it off the example data handler `airportData`. The idea of it is the data handler takes the HTTP body content from the REST API and boils it down into which LEDs need to which color.
### The main loop
Base it off the example sketch in the main folder. `setup()` needs to call `initializeHardware();`. Also connect to your wifi network so we can make HTTP requests to the API. The rest of the stuff in the loop is pretty self explanatory from the example.

## Tips
* Get the NodeMCU version of the ESP8266 instead of the smaller ESP-01 unless space is really an issue. So much easier to deal with, plus you get a few pins for GPIO directly off the microcontroller. Plus none of that getting an arduino to work as a USB to serial adapter and all that nonsense. 