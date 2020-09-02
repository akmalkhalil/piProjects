#include <Arduino_FreeRTOS.h>

// https://circuitdigest.com/microcontroller-projects/arduino-freertos-tutorial1-creating-freertos-task-to-blink-led-in-arduino-uno
// Some notes on xTaskCreate's params
/*
 * 
 * - pvTaskCode: It is simply a pointer to the function that implements the task (in effect, just the name of the function).
 - pcName: A descriptive name for the task. This is not used by FreeRTOS. It is included purely for debugging purposes.
 - usStackDepth: Each task has its own unique stack that is allocated by the kernel to the task when the task is created. 
    The value specifies the number of words the stack can hold, not the number of bytes. 
    For example, if the stack is 32-bits wide and usStackDepth is passed in as 100, then 400 bytes of stack space will be 
    allocated (100 * 4 bytes) in RAM. Use this wisely because Arduino Uno has only 2Kbytes of RAM.
 - pvParameters: Task input parameter (can be NULL).
 - uxPriority: Priority of the task ( 0 is the lowest priority).
 - pxCreatedTask: It can be used to pass out a handle to the task being created. This handle can then be used to reference 
    the task in API calls that, for example, change the task priority or delete the task (can be NULL).
 * 
 */

void TaskBlink1(void *pvParamaters);
void TaskBlink2(void *pvParameters);
void TaskPrint(void *pvParameters);



void setup() {
  Serial.begin(9600); // Baud rate
  
  // xTaskCreate( TaskFunction_t pvTaskCode, 
  // const char * const pcName, 
  // uint16_t usStackDepth, void *pvParameters, 
  // UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask );
  xTaskCreate(TaskBlink1, "blink1", 128, NULL,1,NULL);
  xTaskCreate(TaskBlink2, "blink2", 128, NULL, 100, NULL);
  xTaskCreate(TaskPrint,"printer",128,NULL,1,NULL);
  // So we're using 128 word stacks, why use words, they're an inconcsistent unit??
  // TODO: figure out how to figure out how much is actually needed for a stack rather than using arbitrary width

  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:

}


void TaskBlink1(void *pvParamaters){
  pinMode(8, OUTPUT);
  while(1) { // TODO: why is an infinite loopused? isn't the task called when it's scheduled?
    digitalWrite(8,HIGH);
    Serial.println("blink1");
    vTaskDelay(200/portTICK_PERIOD_MS);
    // vTaskDelay(x) delays for x ticks, so we convert from ticks to real time
    digitalWrite(8, LOW);
    vTaskDelay(200/portTICK_PERIOD_MS);    
  }
}
void TaskBlink2(void *pvParamaters){
  pinMode(7, OUTPUT);
  while(1) { // TODO: why is an infinite loopused? isn't the task called when it's scheduled?
    digitalWrite(7,HIGH);
    Serial.println("blink2");
    vTaskDelay(210/portTICK_PERIOD_MS);
    // vTaskDelay(x) delays for x ticks, so we convert from ticks to real time
    digitalWrite(7, LOW);
    vTaskDelay(210/portTICK_PERIOD_MS);    
  }
}
void TaskPrint(void *pvParameters){
  int counter = 0; // Why isn't this initialised above?
  while (1) {
    counter++;
    Serial.println(counter);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}



/*
 * so I had a think about the while(1) bit, should confirm with some googlin
 * xTaskCreate may is creating a task that will be running
 * the scheduler has a list of tasks that "are running"
 * on each tick the scheduler is decidnig what order to run the tasks that "are running"
 * If that while loop ends, then there's no need to reschedule the task on the next tick
 * TODO: actually look in to this and edit notes/comments here 
 */
