/*
*************************************************************************************************************************************************************************************************************

Name                  : WiFi Server Send Receive
Hardware Platform     : ESP 12E NodeMcu V3
Toolchain             : Arduino IDE V1.8.3, ESP8266 core for Arduino V2.3.0.
Version               : 1.0
Date created          : 08/08/2017
Author                : Mugilan M 
Contact               : mugilan_july@yahoo.co.in
Description           : Connects to WiFi Access Point and sends a message to local server via TCP socket and receives message from server and prints over serial port.

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

// Use python script "Python_Server_Script.py" to run local TCP server. Python Script can be located in this project folder.

#include "ESP8266WiFi.h"
int val=0; //TO SEND THE SENSOR VALUE
String message="Sourabh :"; //TO SEND THE SENSOR VALUE
const char* ssid = "monkey king chandan";
const char* password = "meghananp1";

IPAddress server_ip(192,168,43,191);  //change to IP of the server

int server_port = 12345;

WiFiClient client;

bool flag = true;

void setup() {
   Serial.begin(115200);
   WiFi.begin(ssid, password);
  pinMode(A0,INPUT);
   Serial.println("");
   Serial.println("");
   Serial.println("Connecting to WiFi");
 
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Trying to Connect WiFi Network");
  }

    Serial.println("Starting connection...");

    if (client.connect(server_ip, server_port)) {
      Serial.println("Connected to Server");
      val=analogRead(A0);
      client.println(message+String(val));
      client.println();
    }
  
}

void loop() {

if(flag)
{
    while ( client.available() ) {
    char c = client.read();
    Serial.print(c);
  }

  if ( !client.connected() ) {
    Serial.println();
    
    client.stop();
    if ( WiFi.status() != WL_DISCONNECTED ) {
      WiFi.disconnect();
    }
    
    Serial.println("Connection Closed");
    flag=false;
  }
}

}
