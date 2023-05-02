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
  Serial.println("Initializing...");
  // pinMode(SERVO_PIN, OUTPUT);
  // pinMode(POT_PIN, INPUT);
}

int i = 0;
int cycle = 0;
void loop()
{
  StaticJsonDocument<5000> doc;


  
  doc[fmt.AddLineGraph("Random graph", 0, 100)] = rand() % 100;

  doc[fmt.AddLineGraph("Sensor SX", 0, 2000)] = rand() % 2000;


  doc[fmt.AddLineGraph("millis")] = millis();
  if (cycle % 100 == 0)
    doc[fmt.AddStringLog()] = "Ciao" + std::to_string(millis()) + "\n";
  JsonArray arr = doc.createNestedArray(fmt.AddHeatmap("SX", 8, 8, -560, 14200));

  for (size_t i = 0; i < 64; i++)
  {
    data[i] = i;
    arr.add(data[i]);
  }

  doc[fmt.AddPacketIndex()] = fmt.GetPacketIdx();

  fmt.ResetIdx();
  serializeJson(doc, Serial);
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
  */
  /*
   analogWrite(SERVO_PIN, 0);
   delay(400);
   analogWrite(SERVO_PIN, 1);
   delay(400);
   analogWrite(SERVO_PIN, 240);
   delay(400);
  */
  // Serial.print(millis());
  // Serial.println(" millisecondi");
  cycle++;
}