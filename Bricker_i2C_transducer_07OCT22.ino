#include <Wire.h>
#define DEBUG false
int numSensors = 6;

unsigned int rawTemp, rawPressure;
double pMin = -1, pMax =1;; //in PSID
double outMax = 14746, outMin = 1638;
double pressSlope;
byte byte1, byte2, byte3, byte4;

double calcPress(double val)
{
  return ((val-outMin)*(pMax-pMin))/(outMax-outMin)+pMin;
}

void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
  //Serial.print(bus);
}
double calcTemp (unsigned int val)
{
  return (double(val)/2047.0)*200.0-50.0;
}
void setup() {
  Wire.begin();
  
  Serial.begin(9600);
  while (!Serial); 

 
}

void loop() {
  int nDevices = 0;
  byte address;
  
  for (int i = 0; i < numSensors;i++)
  {
    TCA9548A(i);
    Wire.requestFrom(0x28,4);
     while (Wire.available()) { 
    byte1 = Wire.read(); 
    
    
    byte2 =Wire.read();
    
    byte3 =Wire.read();
    
    byte4 =Wire.read();
    
   if (DEBUG)
    {
      Serial.print("one: ");
    Serial.print(byte1, HEX);
    Serial.print(" two: ");
    Serial.print(byte2, HEX);
    Serial.print(" three: ");
    Serial.print(byte3, HEX);
     Serial.print(" four: ");
    Serial.print(byte4, HEX);  
    }
    Serial.print("T");
    Serial.print(i);
    Serial.print(":");
    rawTemp = (byte3 << 3)|(byte4 >> 5);
    Serial.print(calcTemp(rawTemp));
    Serial.print("P");
      Serial.print(i);
    Serial.print(":");
    rawPressure = ((0x3F&byte1) << 8)|byte2;
    double pressure = calcPress(rawPressure);
    Serial.print(pressure,3);//
   
    
     } 
     Serial.print("@"); 
  } 
   Serial.println();
  }
 
