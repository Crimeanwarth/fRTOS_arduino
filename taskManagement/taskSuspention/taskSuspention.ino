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

int redTaskPrio, yellowTaskPrio, blueTaskPrio;

uint32_t suspend_monitor;

void setup() {
  Serial.begin(9600);
  
  xTaskCreate(redLEDTaskController,"RED LED TASK",100,(void *) redLED,1,&red_Handle);
  xTaskCreate(yellowLEDTaskController,"YELLOW LED TASK",100,(void *) yellowLED,1,&yellow_Handle);
  xTaskCreate(blueLEDTaskController,"BLUE LED TASK",100,(void *) blueLED,1,&blue_Handle);
}

void redLEDTaskController(void *pvParameters){
  pinMode(RED,OUTPUT);
  while(1){
    digitalWrite(RED,digitalRead(RED)^1);
    delay(300);
  }
}

void yellowLEDTaskController(void *pvParameters){
  pinMode(YELLOW,OUTPUT);
  while(1){
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
    suspend_monitor++;
    delay(300);
  }
}

void blueLEDTaskController(void *pvParameters){
  pinMode(BLUE, OUTPUT);
  while(1){
    digitalWrite(BLUE, digitalRead(BLUE)^1);
    if (suspend_monitor > 99){
      vTaskSuspend(yellow_Handle);
    }
    delay(300);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}
