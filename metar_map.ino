#include <Arduino.h>
#include <ESP8266WiFiMulti.h>
#include "src/airportData/ExtractXML.h"
#include "src/PinWriter.h"
#include "src/getStringFromUrl.h"
ESP8266WiFiMulti WiFiMulti;



void setup()
{
  Serial.begin(115200);
  initPins();
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("DukeOpen");
}

void loop()
{
  String xml = getStringFromUrl("https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=xml&stationString=KMCI,KSLC&mostRecentForEachStation=constraint&hoursBeforeNow=2", WiFiMulti);
  if(xml != "")
  {
    auto actions = extractActionsFromXML(xml.c_str());
    for(auto &a : actions)
    {
        a.airport->SetStatus(a.currentStatus);  
        Serial.print("setting action"); 
    }
  }
}
