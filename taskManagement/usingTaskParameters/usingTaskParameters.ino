#include <Arduino_FreeRTOS.h>

// Digital Pin Configuration

#define RED 6
#define YELLOW 7
#define BLUE 8

typedef int TaskProfiler;

TaskProfiler RedLEDTaskProfiler;
TaskProfiler YellowLEDTaskProfiler;
TaskProfiler BlueLEDTaskProfiler;

const uint16_t *blueLED = (uint16_t *) BLUE;
const uint16_t *redLED = (uint16_t *) RED;
const uint16_t *yellowLED = (uint16_t *) YELLOW;

void setup() {
  xTaskCreate(ledControllerTask, "RED LED Task", 100,(void *) redLED,1,NULL);
  xTaskCreate(ledControllerTask, "YELLOW LED Task", 100,(void *) yellowLED,1,NULL);
  xTaskCreate(ledControllerTask, "BLUE LED Task", 100,(void *) blueLED,1,NULL);

}

void ledControllerTask(void *pvParameters){
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  while(1){
    digitalWrite(pvParameters, digitalRead(pvParameters)^1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
