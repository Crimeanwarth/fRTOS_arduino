#include <Arduino_FreeRTOS.h>

// Digital pin configuration 

#define RED 6
#define YELLOW 7
#define BLUE 8

// Profiling for Debug

typedef int TaskProfiler;

TaskProfiler redLEDTaskProfiler;
TaskProfiler yellowLEDTaskProfiler;
TaskProfiler blueLEDTaskProfiler;

// Parameter declaration

const uint16_t redLED = (uint16_t *) RED;
const uint16_t yellowLED = (uint16_t *) YELLOW;
const uint16_t blueLED = (uint16_t *) BLUE;

// Task Handler declarations

TaskHandle_t blue_Handle, red_Handle, yellow_Handle;

void setup() {
  xTaskCreate(ledControllerTask,"Red LED Task",100,(void *) redLED,1,&red_Handle);
  xTaskCreate(ledControllerTask,"Yellow LED Task",100,(void *) yellowLED,1,&yellow_Handle);
  xTaskCreate(ledControllerTask,"Blue LED Task",100,(void *) blueLED,1,&blue_Handle);
}

void ledControllerTask(void *pvParameters){
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(BLUE,OUTPUT);

  while(1){
    digitalWrite(pvParameters,digitalRead(pvParameters)^1);
    delay(300);
    if (pvParameters == YELLOW) {
      vTaskPrioritySet(red_Handle, 2);
    }
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
