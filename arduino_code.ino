#include "SoftwareSerial.h"
SoftwareSerial serial_connection(10,11);
#define BUFFER_SIZE 64
char inData[BUFFER_SIZE];
char inChar=-1;
int count=0;
int i=0;

void setup() {
  Serial.begin(9600);
  serial_connection.begin(9600);
  serial_connection.println("Ready!!!");
  Serial.println("Started");
}

void loop() {
  byte byte_count=serial_connection.available();
  if (byte_count){
    Serial.println("Incoming Data from Nurul");
    int first_bytes=byte_count;
    int remaining_bytes=0;
    if(first_bytes>=BUFFER_SIZE-1){
      remaining_bytes=byte_count-(BUFFER_SIZE-1);
    }
    for(i=0;i<first_bytes;i++){
      inChar=serial_connection.read();
      inData[i]=inChar;
    }
    inData[i]='\0';//This ends the character array with a null character. This signals the end of a string
    if(String(inData)=="BOOP 2")//This could be any motor start string we choose from the python script
    {
      Serial.println("********* Start Motor *********");
    }
    else if(String(inData)=="BOOP 4")//Again this is an arbitrary choice. It would probably be something like: MOTOR_STOP
    {
      Serial.println("********* STOP Motor *********");
    }
    for(i=0;i<remaining_bytes;i++)//This burns off any remaining bytes that the buffer can't handle.
    {
      inChar=serial_connection.read();
    }
    Serial.println(inData);//Print to the monitor what was detected
    serial_connection.println("Hello from Blue "+String(count));//Then send an incrmented string back to the python script
    count++;//Increment the line counter
  }
  delay(100);//Pause for a moment 
}
