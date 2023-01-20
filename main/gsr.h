#include "config.h"
#include <Arduino.h>

static int sensorValue = 0;
static int gsr_average = 0;

void gsr_setup();
int gsr_measure();