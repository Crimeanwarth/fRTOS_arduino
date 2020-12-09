// Digital Pin configuration 

#define RED    6
#define YELLOW 7
#define BLUE   8

void setup() {
  // Pin mode definition 

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
}

void loop() {
  // Digital Write of the pins
  
  digitalWrite(RED, digitalRead(RED)^1);
  digitalWrite(YELLOW, digitalRead(YELLOW)^1);
  digitalWrite(BLUE, digitalRead(BLUE)^1);
  delay(50);
  
}
