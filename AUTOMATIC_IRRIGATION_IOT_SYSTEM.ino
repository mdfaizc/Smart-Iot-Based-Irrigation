#include "UbidotsESP8266.h"
#include <SoftwareSerial.h> 


#define SSID "Your_WiFi_SSID_here"
#define PASS "Your_WiFi_PASWORD_here"


#define TOKEN "Your_token_here"
#define ID "Your_id_here" // Replace it with your Ubidots' variable ID


Ubidots client(TOKEN);
 int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6; int pump = 7; int moistureSensor = A0; 
void setup() {
  Serial.begin(9600);
  client.wifiConnection(SSID,PASS);   pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);   pinMode(pump, OUTPUT);
}
void loop() {
  float sensorvalue = analogRead(moistureSensor);  if (sensorValue >= 820)
 {
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 digitalWrite(led4, HIGH);
 digitalWrite(led5, LOW); digitalWrite(pump, LOW);
}
else if (sensorValue >= 615  && sensorValue < 820)
 {
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW); digitalWrite(pump, LOW);
}  
else if (sensorValue >= 410 && sensorValue < 615)
 {
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW); digitalWrite(pump, HIGH);
}    
else if (sensorValue >= 250 && sensorValue < 410)
 {
 digitalWrite(led1, HIGH);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW); digitalWrite(pump, HIGH);
}
else if (sensorValue >= 0 && sensorValue < 250)
 {
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW); digitalWrite(pump, HIGH);
}
  delay(1000);        // delay 1 second between reads
}
 
  client.add(ID,sensorvalue);

  client.sendAll();
}

