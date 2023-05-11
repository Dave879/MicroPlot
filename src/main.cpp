#include <Arduino.h>
#include <ArduinoJson.h>

#include "data_formatter.h"

#define SERVO_PIN 0
#define POT_PIN 15

DataFormatter fmt;
uint32_t data[64] = {0};

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("Initializing... With no special packet structure");
  PRINTLN("Initializing... With special packet structure");
  // pinMode(SERVO_PIN, OUTPUT);
  // pinMode(POT_PIN, INPUT);
}

int i = 0;
int cycle = 0;
StaticJsonDocument<5000> doc;
void loop()
{
  
/*
  doc[fmt.AddLineGraph("Random graph", 0, 1000)] = rand() % 500 + 250;

  doc[fmt.AddLineGraph("Sensor SX", 0, 2000)] = rand() % 2000;
  doc[fmt.AddLineGraph("millis")] = millis();
  JsonArray arr = doc.createNestedArray(fmt.AddHeatmap("Test Heatmap", 8, 8, 0, 1000));

  for (size_t i = 0; i < 64; i++)
  {
    data[i] = rand() % 1000;
    arr.add(data[i]);
  }

  doc[fmt.AddRepeatedMessage()] = "Serial8 bits available: ";
  doc[fmt.AddRepeatedMessage()] = "Repeated message test: ";
  doc[fmt.AddPacketIndex()] = fmt.GetAndIncrementPacketIdx();


  fmt.ResetIdx();
  serializeJson(doc, Serial);
  doc.clear();
*/
  Serial.print("{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}");
  /*
    // uint16_t reading = analogRead(POT_PIN);
    while (Serial.available() == 0)
    {
    }                                     // wait for data available
    delay(10);
    String teststr = Serial.readString(); // read until timeout
    teststr.trim();                       // remove any \r \n whitespace at the end of the String
    i = teststr.toInt();
    analogWrite(SERVO_PIN, i);
    Serial.println(i);

   analogWrite(SERVO_PIN, 0);
   delay(400);
   analogWrite(SERVO_PIN, 1);
   delay(400);
   analogWrite(SERVO_PIN, 240);
   delay(400);
  */
  // Serial.print(millis());
  // Serial.println(" millisecondi");
  //cycle++;
}