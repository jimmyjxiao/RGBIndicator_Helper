#include "ExtractXML.h"
#include "../lib/tinyxml2/tinyxml2.h"
#include <vector>
using namespace airportDataTypes;
std::vector<Action> extractActionsFromXML(const char* xml)
{
	using namespace tinyxml2;
	std::vector<Action> ret;
	XMLDocument doc;
	doc.Parse(xml);
	for (tinyxml2::XMLElement* a = doc.FirstChildElement("response")->FirstChildElement("data")->FirstChildElement(); a != NULL; a = a->NextSiblingElement())
	{
		const auto vfrStr = a->FirstChildElement("flight_category")->GetText();
		Action action;
		if (strcmp("VFR", vfrStr) == 0)
		{
			action.currentStatus = Metar_Status::VFR;
		}
		else if (strcmp("MVFR", vfrStr) == 0)
		{
			action.currentStatus = Metar_Status::MVFR;
		}
		else if (strcmp("IFR", vfrStr) == 0)
		{
			action.currentStatus = Metar_Status::IFR;
		}
		else if (strcmp("LIFR", vfrStr) == 0)
		{
			action.currentStatus = Metar_Status::LIFR;
		}
		else
		{
			action.currentStatus = Metar_Status::off;
		}
		const auto stationStr = a->FirstChildElement("station_id")->GetText();
		for (const auto& a : Airports)
		{
			if (strcmp(a.id, stationStr) == 0)
			{
				action.airport = &a;
				break;
			}
		}
		if (action.airport != nullptr)
		{
			ret.push_back(action);
		}
	}
	return ret;
}