#include "RIOcom.h"

typedef void(*callback_t)(void);

namespace RIOcom
{
  namespace
  {
    class registerMap
    {
      public:
        registerMap() {}
        void addRegCallback(byte reg, callback_t callback)
        {
          if(maxIndex >= 15)
            Serial.println("Too many callbacks! Skipping!");
          else
          {
            reg[maxIndex] = reg;
            callback[maxIndex] = callback;
            maxIndex++;
          }
        }
      private:
        byte reg[16];
        callback_t callback[16];
        int maxIndex = 0;
    };
    
    registerMap regMap = registerMap();
    byte curI2CRegister;
    
    byte packedData[5] = {'$', 0x02, 0, 0, '#'};
    byte blankData[1] = {0};
    int packedDataLength = 5;
    
    void receiveEvent(int amt)
    {
      if (Wire.available() > 0)
        curI2CRegister = Wire.read();
    }
    
    void requestEvent()
    {
      if (curI2CRegister == 0x01)
      {
        Wire.write(packedData, packedDataLength);
        digitalWrite(10, HIGH);
      }
      else
      {
        Wire.write(blankData, 1);
        digitalWrite(10, LOW);
      }
    }
  }

  void setup(byte maxRegisterNumber, byte address)
  {
    Wire.begin(address);
    Wire.onRequest(requestEvent);
    Wire.onReceive(receiveEvent);
    if(!Serial)
      Serial.begin(9600);
  }
  
  void loop()
  {
    Serial.print("I2C Register: ");
    Serial.println(curI2CRegister);
  }
  
}
