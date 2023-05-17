#include <Arduino.h>
#include <ArduinoJson.h>

#include "data_formatter.h"

#define SERVO_PIN 0
#define POT_PIN 15

#define HEATMAP_SIZE 400
DataFormatter fmt;
uint32_t data[HEATMAP_SIZE] = {0};

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
StaticJsonDocument<170000> doc;
JsonArray arr;
bool toggle = false;
void loop()
{

  doc[fmt.AddLineGraph("Random graph", 2)] = rand() % 500 + 250;

  doc[fmt.AddLineGraph("Sensor DX", 2)] = rand() % 20;
  doc[fmt.AddLineGraph("Test 1", 1)] = rand() % 2000-3000;
  doc[fmt.AddLineGraph("Test 2", 1)] = rand() % 3000+50000;
  doc[fmt.AddLineGraph("Test 3", 1)] = rand() % 300+5000;
  doc[fmt.AddLineGraph("Test 4", 1)] = rand() % 6000-15000;
  doc[fmt.AddLineGraph("Test 5", 1)] = rand() % 5000;
  doc[fmt.AddLineGraph("Test 6", 1)] = rand() % 5300 - 9000;
  doc[fmt.AddLineGraph("Test 7", 1)] = millis() % 7;
  doc[fmt.AddLineGraph("Test 8", 1)] = rand() % 395 - 636;
  doc[fmt.AddLineGraph("Test 9", 1)] = rand() % 30-3500;
  doc[fmt.AddLineGraph("Test 10", 1)] = rand() % 2000-10000;
  doc[fmt.AddLineGraph("millis")] = millis();

  arr = doc.createNestedArray(fmt.AddHeatmap("Test Heatmap", sqrt(HEATMAP_SIZE), sqrt(HEATMAP_SIZE), 0, 1000));
  /*
  if (toggle)
  {
    toggle = false;
    for (size_t i = 0; i < HEATMAP_SIZE; i++)
    {
      data[i] = i;
      arr.add(data[i]);
    }
  }
  else
  {
    toggle = true;
    for (int32_t i = 10000; i >= 0; i--)
    {
      data[i] = i;
      arr.add(data[i]);
    }
  }
  */
     for (size_t i = 0; i < HEATMAP_SIZE; i++)
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

  // Serial.print("{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}{\"0&i\":1}");
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
  // cycle++;
}