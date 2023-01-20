#include "emg.h"

void emg_setup() { pinMode(PIN_EMG, INPUT); };

int emg_measure() { return analogRead(PIN_EMG); }