/*
*************************************************************************************************************************************************************************************************************

Name                  : WiFi Ping IP Host
Hardware Platform     : ESP 12E NodeMcu V3
Toolchain             : Arduino IDE V1.8.3, ESP8266 core for Arduino V2.3.0.
Version               : 1.0
Date created          : 08/08/2017
Author                : Mugilan M 
Contact               : mugilan_july@yahoo.co.in
Description           : Connects to a WiFi Access Point and pings specified IP Address and Host name
Reference             : https://github.com/dancol90/ESP8266Ping

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

#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>	//Install ESP8266Ping Library
int sensorValue=0;
int sensorpin=A0;
const char* ssid     = "monkey king chandan";
const char* password = "meghananp1";

const IPAddress remote_ip(192, 168, 43, 191);
const IPAddress remote_host(208, 67, 222, 222);

//remote up is the IP of the server
void setup() {
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
  
  Serial.println("Pinging Host ");
  Serial.println(remote_host);

  if(Ping.ping(remote_host)) {
    Serial.println("Success!!");
    Serial.print("Average Time: ");
    Serial.print(Ping.averageTime());
    Serial.println(" ms");
  } else {
    Serial.println("Error Pinging given Host Name");
  }


  Serial.println("Pinging IP ");
  Serial.println(remote_ip);

  if(Ping.ping(remote_ip)) {
    Serial.println("Success!!");
    Serial.print("Average Time: ");
    Serial.print(Ping.averageTime());
    Serial.println(" ms");
  } else {
    Serial.println("Error Pinging given IP Address ");
  }

  
}

void loop() 
{sensorValue=analogRead(sensorpin);
  Serial.println(sensorValue);
  delay(1000);
  }
