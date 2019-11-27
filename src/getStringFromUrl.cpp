#include "getStringFromUrl.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <WiFiClientSecureBearSSL.h>
const uint8_t fingerprint[] = { 0x29, 0xf0, 0x37, 0xba, 0xce, 0x86, 0x3c, 0x94, 0x3c, 0x3b, 0xdf, 0x2c, 0xe5, 0x30, 0x3a, 0x24, 0x3e, 0xae, 0xf4, 0x91 };
String getStringFromUrl(const char* const url, ESP8266WiFiMulti& WiFiMulti)
{
	if ((WiFiMulti.run() == WL_CONNECTED))
	{
		BearSSL::WiFiClientSecure client = BearSSL::WiFiClientSecure();
		client.setFingerprint(fingerprint);
		HTTPClient http;
		http.begin(client, url);
		int httpCode = http.GET();
		if (httpCode > 0)
		{
			if (httpCode == HTTP_CODE_OK)
			{
				return http.getString();
			}
		}
		else {
			Serial.printf("[HTTPS] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
			return "";
		}
		http.end();
	}
	else
	{
		return "";
	}
}