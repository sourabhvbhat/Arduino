#define LED 5 

void setup() {
  pinMode(LED, OUTPUT);     
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED, LOW);   
  Serial.println("ON");
  delay(500);                      
  digitalWrite(LED, HIGH); 
  Serial.println("OFF");
  delay(500);                      
}
