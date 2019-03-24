// Pin Number: Sensor Module -> A0

int sensor_value = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensor_value = analogRead(A0);
  Serial.println(sensor_value);
  delay(500);
}
