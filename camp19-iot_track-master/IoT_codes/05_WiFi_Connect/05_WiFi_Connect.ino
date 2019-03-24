/*
*************************************************************************************************************************************************************************************************************

Name                  : WiFi Connect Display IP MAC
Hardware Platform     : ESP 12E NodeMcu V3
Toolchain             : Arduino IDE V1.8.3, ESP8266 core for Arduino V2.3.0.
Version               : 1.0
Date created          : 08/08/2017
Author                : Mugilan M 
Contact               : mugilan_july@yahoo.co.in
Description           : Connects to a WiFi Access Point and prints assigned IP address and built-in MAC address on serial port.

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

const char* ssid = "hacker's";        // WiFi AP Name
const char* password = "sourabh123";  // WiFi AP Password	

void setup(void)
{ 
  Serial.begin(115200);
  delay(10);

  Serial.println("");
  Serial.println("");
  Serial.println("Connecting to WiFi");

  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.println("Trying to Connect WiFi Network");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

}

void loop() 
{}
