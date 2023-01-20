#include "gsr.h"

void gsr_setup() { pinMode(PIN_GSR, INPUT); };

int gsr_measure() { return analogRead(PIN_GSR); }
