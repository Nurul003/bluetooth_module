#include "SoftwareSerial.h"
SoftwareSerial serial_connection(10,11);
#define BUFFER_SIZE 64
char inData[BUFFER_SIZE];
char inChar=-1;
int count=0;
int i=0;
int sensorPin = A0;    
int sensorValue = 0; 


void setup() {
  Serial.begin(9600);
  serial_connection.begin(9600);
}

void loop() {
  byte byte_count=serial_connection.available();
  sensorValue = analogRead(sensorPin);
  if (byte_count){
    serial_connection.println("Hello from Blue "+String(sensorValue));//Then send an incrmented string back to the python script
    count++;//Increment the line counter
  }
  delay(100);//Pause for a moment 
}
