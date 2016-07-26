#ifndef RIOCOM_H
#define RIOCOM_H

#include <Arduino.h>
#include <Wire.h>

struct RIOComCallbackResult
{
  short length;
  byte data[];
};

namespace RIOcom
{
  void setup(byte maxRegisterNumber, byte address = 84);
  bool setEventForRegister(void* event, byte reg);
  void loop();
}

#endif
