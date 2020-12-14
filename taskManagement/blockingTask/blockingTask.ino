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
uint32_t resume_monitor;
bool _suspended = false;

const TickType_t _500ms = pdMS_TO_TICKS(500);
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
    vTaskDelay(_500ms);
    Serial.println(_suspended);
    if (_suspended) {
      resume_monitor ++;
      if (resume_monitor > 4){
        vTaskResume(yellow_Handle);
        resume_monitor = 0;
        _suspended = false;
      }
    }
  }
}

void yellowLEDTaskController(void *pvParameters){
  pinMode(YELLOW,OUTPUT);
  while(1){
    digitalWrite(YELLOW, digitalRead(YELLOW)^1);
    suspend_monitor++;
    vTaskDelay(_500ms);
    }
  }


void blueLEDTaskController(void *pvParameters){
  pinMode(BLUE, OUTPUT);
  while(1){
    digitalWrite(BLUE, digitalRead(BLUE)^1);
    if (suspend_monitor > 9){
      _suspended = true;
      suspend_monitor = 0;
      vTaskSuspend(yellow_Handle);
    }
    vTaskDelay(_500ms);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}
