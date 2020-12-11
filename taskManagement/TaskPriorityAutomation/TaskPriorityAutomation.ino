#include <Arduino_FreeRTOS.h>

// Digital Pin Configuration 

#define RED 6
#define YELLOW 7
#define BLUE 8

typedef int TaskProfiler;

TaskProfiler redLEDTaskProfiler;
TaskProfiler yellowLEDTaskProfiler;
TaskProfiler blueLEDTaskProfiler;

const uint16_t redLED = (uint16_t *) RED;
const uint16_t yellowLED = (uint16_t *) YELLOW;
const uint16_t blueLED = (uint16_t *) BLUE;

TaskHandle_t red_Handle, yellow_Handle, blue_Handle;

void setup() {
  xTaskCreate(LEDControllerTask, "YELLOW LED TASK", 100, (void *) yellowLED, 1, &yellow_Handle);
  xTaskCreate(LEDControllerTask, "RED LED TASK", 100, (void *) redLED, 1, &red_Handle);
  xTaskCreate(LEDControllerTask, "BLUE LED TASK", 100, (void *) blueLED, 1, &blue_Handle);
}

void LEDControllerTask (void *pvParameters) {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  while(1){
    digitalWrite(pvParameters,digitalRead(pvParameters)^1);
    vTaskPrioritySet(NULL,2); // either set task handle inside task or change it to NULL.
    delay(300);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
