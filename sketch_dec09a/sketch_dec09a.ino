#include <Arduino_FreeRTOS.h>

// Digital Pin configuration 

#define RED    6
#define YELLOW 7
#define BLUE   8

void setup() {

  xTaskCreate(redLedControllerTask,"RED LED TASK",128,NULL,1,NULL);
  xTaskCreate(yellowLedControllerTask,"YELLOW LED TASK",128,NULL,1,NULL);
  xTaskCreate(blueLedControllerTask,"BLUE LED TASK",128,NULL,1,NULL);

}

void redLedControllerTask(void *pvParameters) {
  pinMode(RED, OUTPUT);
    
  while(1){
    digitalWrite(RED, digitalRead(RED)^1);
  }
}
  
void yellowLedControllerTask(void *pvParameters) {
  pinMode(YELLOW, OUTPUT);
      
  while(1){
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
  }
}
  
void blueLedControllerTask(void *pvParameters) {
  pinMode(BLUE, OUTPUT);
   
  while(1){
    digitalWrite(BLUE, digitalRead(BLUE)^1);
  }
}
  

void loop() {
  // Digital Write of the pins
  
//  digitalWrite(RED, digitalRead(RED)^1);
//  digitalWrite(YELLOW, digitalRead(YELLOW)^1);
//  digitalWrite(BLUE, digitalRead(BLUE)^1);
//  delay(50);
  
}
