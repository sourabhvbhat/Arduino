#include<SimpleDHT.h>
float temperature=0;
float humidity=0;
int pinDHT22=5;

SimpleDHT22 dht22(pinDHT22);

void setup()
{
  Serial.begin(115200);
}

void loop() {
  int err=SimpleDHTErrSuccess;
  if((err=dht22.read2(&temperature,&humidity,NULL))!=SimpleDHTErrSuccess){
    Serial.print("Read DHT22 failed, err=");
    Serial.println(err);
    delay(2000);
    return;
  }
  Serial.print((float)temperature); Serial.print("*C,");
  Serial.print((float)humidity); Serial.println("RH%");
  //FHT22 sampling rate is 0.5Hz.
  delay(2500);
}
