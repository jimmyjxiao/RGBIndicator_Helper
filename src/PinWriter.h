#pragma once
#include "lib/Adafruit_MCP23017/Adafruit_MCP23017.h"
namespace pinWriters
{
	class PinHandler
	{
	public:
		virtual void writeLiteralPin(bool val, unsigned char pin) = 0;
	};
	class MCPHandler : public PinHandler
	{
	private:
		Adafruit_MCP23017 mcp;
	public:
		MCPHandler(unsigned char i2cAddress);
		void writeLiteralPin(bool val, unsigned char pin) override;
	};
	class NativeHandler : public PinHandler
	{
	private:
		static void initializePin(unsigned char pin);
	public:
		template <size_t N>
		NativeHandler(unsigned char(&usedPins)[N])
		{
			for (unsigned char p : usedPins)
			{
				initializePin(p);
			}
		}
		void writeLiteralPin(bool val, unsigned char pin) override;
	};
}


void writePin(unsigned char pin, bool value);
