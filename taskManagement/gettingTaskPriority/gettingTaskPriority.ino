#include <Arduino_FreeRTOS.h>

// Digital Pin Configuration 

#define RED 6
#define YELLOW 7
#define BLUE 8

typedef int TaskProfiler;

TaskProfiler redLEDTaskProfiler;
TaskProfiler yellowLEDTaskProfiler;
TaskProfiler blueLEDTaskProfiler;

TaskHandle_t red_Handle, yellow_Handle, blue_Handle;

int yellowTaskPrio;

void setup() {
  Serial.begin(9600);
  
  xTaskCreate(redLEDTaskController,"RED LED TASK",100,NULL,1,&red_Handle);
  xTaskCreate(yellowLEDTaskController,"YELLOW LED TASK",100,NULL,1,&yellow_Handle);
  xTaskCreate(blueLEDTaskController,"BLUE LED TASK",100,NULL,1,&blue_Handle);

}

void redLEDTaskController(void *pvParameters){
  pinMode(RED,OUTPUT);

  while(1){
    redLEDTaskProfiler++;
    Serial.print("RED Run Time:");
    Serial.println(redLEDTaskProfiler);
    delay(300);
  }
}

void yellowLEDTaskController(void *pvParameters){
  pinMode(RED,OUTPUT);

  while(1){
    yellowLEDTaskProfiler++;
    yellowTaskPrio = uxTaskPriorityGet(yellow_Handle);
    Serial.print("YELLOW Run Time:");
    Serial.println(yellowLEDTaskProfiler);
    Serial.print("YELLOW Task Priority:");
    Serial.println(yellowTaskPrio);
    delay(300);
  }
}

void blueLEDTaskController(void *pvParameters){
  pinMode(BLUE,OUTPUT);

  while(1){
    blueLEDTaskProfiler++;
    Serial.print("BLUE Run Time:");
    Serial.println(blueLEDTaskProfiler);
    delay(300);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}
