#include <Arduino_FreeRTOS.h>

// Digital pin configuration

#define RED 6
#define YELLOW 7
#define BLUE 8

typedef int TaskProfiler;

TaskProfiler RedLEDProfiler;
TaskProfiler YellowLEDProfiler;
TaskProfiler BlueLEDProfiler;

void setup() {
  Serial.begin(9600);

  xTaskCreate(redLEDControllerTask,
              "Red LED Task",
              100,
              NULL,
              1,
              NULL);

  xTaskCreate(blueLEDControllerTask,
              "Blue LED Task",
              100,
              NULL,
              1,
              NULL);

  xTaskCreate(yellowLEDControllerTask,
              "yellow LED Task",
              100,
              NULL,
              1,
              NULL);
              
  
}

void redLEDControllerTask(void *pvParameters){
  pinMode(BLUE,OUTPUT);
  while(1){
    Serial.println("This is RED");
  }
}

void blueLEDControllerTask(void *pvParameters){
  pinMode(BLUE,OUTPUT);
  while(1){
    Serial.println("This is BLUE");
  }
}

void yellowLEDControllerTask(void *pvParameters){
  pinMode(BLUE,OUTPUT);
  while(1){
    Serial.println("This is YELLOW");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
