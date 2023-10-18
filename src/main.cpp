#include <Arduino.h>
#define ARDUPLOT_DEBUG true
#include "ArduPlot.h"

#define HEATMAP_SIZE 225
uint32_t data[HEATMAP_SIZE] = {0};

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("Initializing...");
}

uint32_t past_time = millis();

void loop()
{
  for (size_t i = 0; i < HEATMAP_SIZE; i++)
  {
    data[i] = rand() % 1000;
  }

  ARDUPLOT_SHARED_LINE_GRAPH("Random graph", rand() % 500 + 250, "2");
  ARDUPLOT_SHARED_LINE_GRAPH("Sensor DX", rand() % 20, "2");
  ARDUPLOT_SHARED_LINE_GRAPH("Random graph", rand() % 500 + 250, "2");
  ARDUPLOT_SHARED_LINE_GRAPH("Sensor DX", rand() % 20, "2");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 1", rand() % 2000 - 3000, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 2", rand() % 3000 + 50000, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 3", rand() % 300 + 5000, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 4", rand() % 6000 - 15000, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 5", rand() % 5000, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 6", rand() % 5300 - 9000, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 7", millis() % 7, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 8", rand() % 395 - 636, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 9", rand() % 30 - 3500, "1");
  ARDUPLOT_SHARED_LINE_GRAPH("Test 10", rand() % 2000 - 10000, "1");

  ArduPlot::LineGraph("Test 11", rand() % 100 + 600, 2);

  ARDUPLOT_LINE_GRAPH("millis", millis());
  
  ArduPlot::LineGraph("Standalone", rand() % 1000 - 500);

  ARDUPLOT_HEATMAP("Test Heatmap", "15", "15", data, HEATMAP_SIZE);
  ArduPlot::Heatmap("Rectangle heatmap", 10, 5, 0, 1000, data, 50);

  float arr[2] = {1.0f, 0.0f};
  ArduPlot::Heatmap("Testing", 1, 2, arr, 2);
  ARDUPLOT_HEATMAP("Testing fast", "1", "2", arr, 2);

  if (past_time + 1000 < millis())
  {
    past_time = millis();
    Serial.print("Console test... ");
    Serial.println(millis());
  }
}