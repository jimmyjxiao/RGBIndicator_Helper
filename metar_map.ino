#include <Arduino.h>
#include <ESP8266WiFiMulti.h>
#include "src/airportData/ExtractXML.h"
#include "src/PinWriter.h"
#include "src/getStringFromUrl.h"
ESP8266WiFiMulti WiFiMulti;



void setup()
{
  Serial.begin(115200);
  initializeHardware();
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("DukeOpen");
}
void processUrl(const char* const url)
{
  String xml = getStringFromUrl(url, WiFiMulti);
  if(xml != "")
  {
    auto actions = extractActionsFromXML(xml.c_str());
    for(auto &a : actions)
    {
        a.airport->SetStatus(a.currentStatus);  
    }
  }
}
void loop()
{
  // giant xml files aren't fun for the tiny RAM of the esp8266 so we make individual requests.
  processUrl("https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=xml&stationString=KBOS,KJFK,KDCA,KPHL&mostRecentForEachStation=constraint&hoursBeforeNow=2");
  processUrl("https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=xml&stationString=KRDU,KATL,KMSY,KMCI&mostRecentForEachStation=constraint&hoursBeforeNow=2");
  processUrl("https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=xml&stationString=KDFW,KORD,KOSH,KDEN&mostRecentForEachStation=constraint&hoursBeforeNow=2");
  processUrl("https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=xml&stationString=KSLC,KBZN,KSEA,KSFO&mostRecentForEachStation=constraint&hoursBeforeNow=2");
  processUrl("https://www.aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=xml&stationString=KLAX,KCLT&mostRecentForEachStation=constraint&hoursBeforeNow=2");
  delay(1200);
}