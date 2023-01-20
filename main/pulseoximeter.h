#include "MAX30105.h"
#include "heartRate.h"
#include <Arduino.h>

// Global variables
static const byte RATE_SIZE = 4; // Increase this for more averaging. 4 is good.
static byte rates[RATE_SIZE];    // Array of heart rates
static byte rateSpot = 0;
static long lastBeat = 0; // Time at which the last beat occurred

static float beatsPerMinute;

void pox_setup();

float pox_measure_temp();
int pox_measure_BMP();