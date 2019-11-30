#pragma once
class RGB_LED
{
public:
	virtual void setRGB(bool red, bool green, bool blue) const = 0;
};
class commonCathodeRGBLED : public RGB_LED
{
private:
	const unsigned char R_pin;
	const unsigned char G_pin;
	const unsigned char B_pin;
public:
	constexpr commonCathodeRGBLED(unsigned char redPin, unsigned char greenPin, unsigned char bluePin) : R_pin(redPin), G_pin(greenPin), B_pin(bluePin) {}
	void setRGB(bool red, bool green, bool blue) const override;
};
class commonAnnodeRGBLED : public RGB_LED
{

private:
	const unsigned char R_pin;
	const unsigned char G_pin;
	const unsigned char B_pin;
public:
	constexpr commonAnnodeRGBLED(unsigned char redPin, unsigned char greenPin, unsigned char bluePin) : R_pin(redPin), G_pin(greenPin), B_pin(bluePin) {}
	void setRGB(bool red, bool green, bool blue) const override;
};
class Adafruit_NeoPixel;
class addressableLED : public RGB_LED
{
private:
	static Adafruit_NeoPixel* pixelWriter;
	const unsigned char n;
public:
	static void initializeLEDs(unsigned short numLeds, unsigned short dataPin);
	constexpr addressableLED(const unsigned char ledID) : n(ledID) {}
	void setRGB(bool red, bool green, bool blue) const override;
};
