//Includes
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//Tasks
void Task1( void *pvParameters );
void Task2( void *pvParameters );
void Task3( void *pvParameters );

//Setup for logic
void setup() {

//pin num and in/outputs
  pinMode(8, OUTPUT); //LED Output
  pinMode(7, INPUT);  //Button Input
  Serial.begin(9600);  
  xTaskCreate(Task3,"task3",128,NULL,1,NULL); //Creation of Task3

//taskScheduler
vTaskStartScheduler();
}

void loop()
{
  //empty
}

void Task2(void *pvParameters)  {
    Serial.println("Task2");
    digitalWrite(8, HIGH);   
    vTaskDelay( 500 / portTICK_PERIOD_MS ); 
    digitalWrite(8, LOW);    
    vTaskDelay( 500 / portTICK_PERIOD_MS ); 
}

void Task1(void *pvParameters)  
{
      Serial.println("Task1");
       digitalWrite(8, HIGH);
        vTaskDelay( 333 / portTICK_PERIOD_MS ); 
        digitalWrite(8, LOW);
        vTaskDelay( 777 / portTICK_PERIOD_MS ); 
}

void Task3(void *pvParameters)  {
  for(;;)
  {
    if (digitalRead(7) == HIGH)
    {
      xTaskCreate(Task1,"task1",128,NULL,1,NULL);
    }else
    {
      xTaskCreate(Task2,"task2",128,NULL,1,NULL);
    }; 
  }
}