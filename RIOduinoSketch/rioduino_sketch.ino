#include <Wire.h>

// ====================================
// ROBOT COMMUNICATION
byte i2c_register = 0x00;
byte packedData[5] = {'$', 0x02, 0, 0, '#'};
byte blankData[1] = {0};
int packedDataLength = 5;

void robotRequestEvent() 
{
  if(i2c_register == 0x01)
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
void robotReceiveEvent(int amt) 
{
  if(Wire.available() > 0)
    i2c_register = Wire.read();
}

// ===================================================
// ARDUINO REQUIRED

void setup() {
  Wire.begin(84);
  Wire.onRequest(robotRequestEvent);
  Wire.onReceive(robotReceiveEvent);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
   Serial.print("I2C Register: ");
   Serial.println(i2c_register); 
}

