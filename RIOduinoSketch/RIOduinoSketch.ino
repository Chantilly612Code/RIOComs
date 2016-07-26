#include <Wire.h>
#include "RIOcom.h"

// ====================================
// ROBOT COMMUNICATION


void setup() {
  RIOcom::setup(84);

  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  RIOcom::loop();
}

