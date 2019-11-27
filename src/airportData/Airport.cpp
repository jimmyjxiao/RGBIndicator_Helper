#include "Airport.h"
using namespace airportDataTypes;
void Airport::SetStatus(Metar_Status s) const
{
	switch (s)
	{
	case Metar_Status::VFR:
		LEDhandler->setRGB(false, true, false);
		break;
	case Metar_Status::MVFR:
		LEDhandler->setRGB(false, false, true);
		break;
	case Metar_Status::IFR:
		LEDhandler->setRGB(true, false, false);
		break;
	case Metar_Status::LIFR:
		LEDhandler->setRGB(true, false, true);
		break;
	case Metar_Status::off:
		LEDhandler->setRGB(false, false, false);
		break;
	}
}
