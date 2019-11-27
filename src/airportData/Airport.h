#pragma once
#include "../LEDWriter.h"
#include <memory>
#include "../hardwareConfig.h"
namespace airportDataTypes
{
	enum class Metar_Status
	{
		VFR, MVFR, IFR, LIFR, off
	};
}


class Airport
{
	private:
		const RGB_LED * LEDhandler;
	public:
		const char* const id;
		constexpr Airport(const RGB_LED* const LED, const char* const airportCode) : LEDhandler(LED), id(airportCode) {}
		void SetStatus(airportDataTypes::Metar_Status s) const;
};
const Airport Airports[] = {
	Airport(LEDs[0], "KSLC"),
	Airport(LEDs[1], "KRDU")
};
