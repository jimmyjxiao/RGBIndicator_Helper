#include "LEDWriter.h"
#include "PinWriter.h"
#include "lib/Adafruit_Neopixel/Adafruit_NeoPixel.h"
void commonCathodeRGBLED::setRGB(bool red, bool green, bool blue) const
{
	writePin(B_pin, blue);
	writePin(G_pin, green);
	writePin(R_pin, red);
}
void commonAnnodeRGBLED::setRGB(bool red, bool green, bool blue) const
{
	writePin(B_pin, !blue);
	writePin(G_pin, !green);
	writePin(R_pin, !red);
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
	pixelWriter = new Adafruit_NeoPixel(numLeds, dataPin, NEO_RGB + NEO_KHZ800);
	pixelWriter->begin();
}
void addressableLED::setRGB(bool red, bool green, bool blue) const
{
	Serial.print("Setting pixel");
	Serial.print(" pin:");
	Serial.print(n);
	Serial.print(" R: ");
	Serial.print(red);
	Serial.print(" G: ");
	Serial.print(green);
	Serial.print(" B: ");
	Serial.print(blue);
	Serial.print("\n");
	pixelWriter->setPixelColor((uint16_t)n, Adafruit_NeoPixel::Color(boolToColorComponent(red), boolToColorComponent(green), boolToColorComponent(blue)));
	pixelWriter->show();
}
Adafruit_NeoPixel* addressableLED::pixelWriter = nullptr;
