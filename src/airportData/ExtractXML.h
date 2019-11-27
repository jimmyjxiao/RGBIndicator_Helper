#pragma once
#include <vector>
#include "Airport.h"

struct Action
{
	airportDataTypes::Metar_Status currentStatus = airportDataTypes::Metar_Status::off;
	const Airport* airport = nullptr;
};
std::vector<Action> extractActionsFromXML(const char* xml);
