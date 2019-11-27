#include "LEDWriter.h"
#include "PinWriter.h"
#include "lib/Adafruit_Neopixel/Adafruit_NeoPixel.h"
void commonCathodeRGBLED::setRGB(bool red, bool green, bool blue) const
{
	writePin(B_pin, blue);
	writePin(G_pin, green);
	writePin(R_pin, red);
}
unsigned char boolToColorComponent(bool input)
{
	if (input)
	{
		return 255;
	}
	else
	{
		return 0;
	}
}
void addressableLED::initializeLEDs(unsigned short numLeds, unsigned short dataPin)
{
	pixelWriter = new Adafruit_NeoPixel(numLeds, dataPin);
}
void addressableLED::setRGB(bool red, bool green, bool blue) const
{
	pixelWriter->setPixelColor((uint16_t)n, Adafruit_NeoPixel::Color(boolToColorComponent(red), boolToColorComponent(green), boolToColorComponent(blue)));
}
Adafruit_NeoPixel * addressableLED::pixelWriter = nullptr;
