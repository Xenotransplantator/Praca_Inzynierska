#include "pulseoximeter.h"

MAX30105 particleSensor;

void pox_setup()
{
  // Initialize sensor
  if (particleSensor.begin(Wire, I2C_SPEED_FAST) == false)
  { // Use default I2C port, 400kHz speed
    Serial.println("MAX30102 was not found. Please check wiring/power. ");
    while (1)
      ;
  }

  // The LEDs are very low power and won't affect the temp reading much but
  // you may want to turn off the LEDs to avoid any local heating
  particleSensor.setup(0); // Configure sensor. Turn off LEDs

  particleSensor
      .enableDIETEMPRDY(); // Enable the temp ready interrupt. This is required.
  particleSensor.setPulseAmplitudeRed(
      0x0A); // Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); // Turn off Green LED
}

float pox_measure_temp() { return particleSensor.readTemperature(); }

int pox_measure_BMP()
{
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue) == true)
  {
    // We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] =
          (byte)beatsPerMinute; // Store this reading in the array
      rateSpot %= RATE_SIZE;    // Wrap
    }
  }

  return beatsPerMinute;
}