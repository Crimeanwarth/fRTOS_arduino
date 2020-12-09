#include <Arduino_FreeRTOS.h>

// Digital Pin Configuration 

#define RED 6
#define YELLOW 7
#define BLUE 8

typedef int TaskProfiler;

TaskProfiler redLEDTaskProfiler;
TaskProfiler yellowLEDTaskProfiler;
TaskProfiler blueLEDTaskProfiler;

const uint16_t *redLED = (uint16_t *) RED;
const uint16_t *yellowLED = (uint16_t *) YELLOW;
const uint16_t *blueLED = (uint16_t *) BLUE;

void setup() {
  
  xTaskCreate(ledTaskController, "Red LED Task", 100, (void *) redLED, 3, NULL);
  xTaskCreate(ledTaskController, "Yellow LED Task", 100, (void *) yellowLED, 3, NULL);
  xTaskCreate(ledTaskController, "Blue LED Task", 100, (void *) blueLED, 3, NULL);
  
}

void ledTaskController(void *pvParameters){
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);  
  pinMode(BLUE,OUTPUT);  

  while(1){
    digitalWrite(pvParameters,digitalRead(pvParameters)^1);
    delay(300);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
