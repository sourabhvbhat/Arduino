// Serial Command: 'y' -> turns LED ON; 'n' -> turns LED OFF

#define LED 5

char ser_recv;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);   // Active Low Logic : 0 -> LED ON; 1 -> LED OFF.
  digitalWrite(LED, HIGH);    
}

void loop() {
//
  if(Serial.available() > 0)
  {
  ser_recv = Serial.read();
  
  if(ser_recv == 'y')
  {
  digitalWrite(LED, LOW);   
  }

  else if(ser_recv == 'n')
    {
      digitalWrite(LED, HIGH);  
    }

  }
  

}
