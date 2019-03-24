/*
*************************************************************************************************************************************************************************************************************

Name                  : WiFi Scan
Hardware Platform     : ESP 12E NodeMcu V3
Toolchain             : Arduino IDE V1.8.3, ESP8266 core for Arduino V2.3.0.
Version               : 1.0
Date created          : 08/08/2017
Author                : Mugilan M 
Contact               : mugilan_july@yahoo.co.in
Description           : Scans available WiFi Networks nearby and lists them over serial port along with their parameters.

*************************************************************************************************************************************************************************************************************

Copyright 2017 Mugilan M

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************************************************************************************************************************************************
*/

#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

}

void loop() {
  Serial.println("WiFi Network Scan Started");
//returns the number of wifi networks available
  int n = WiFi.scanNetworks();

  Serial.println("WiFi Network Scan Done");

  if (n == 0)
    Serial.println("No WiFi Networks Found");
  else
  {
    Serial.print(n);
    Serial.println(" WiFi Networks Found");
    for (int i = 0; i < n; ++i)
    {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }

  Serial.println("");

  delay(3000);

}
