#include <Arduino.h>
#include <WiFiClient.h>
#include <Wire.h>

#include "config.h"
#include "emg.h"
#include "gsr.h"
#include "pulseoximeter.h"

void setup()
{
  Serial.begin(115200);
  pox_setup();
  gsr_setup();
  emg_setup();
}

void loop()
{
 Serial.printf("Pox (HR): %d (T): %f, gsr: %d, emg %d\n", pox_measure_BMP(),
                pox_measure_temp(), gsr_measure(), emg_measure());
  delay(10);
}
