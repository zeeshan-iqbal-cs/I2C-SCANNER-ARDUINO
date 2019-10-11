#include <Wire.h>

void setup(){
  Wire.begin();
 
  Serial.begin(9600);
  while (!Serial);
  Serial.println();
  Serial.println("I2C Scanner");
}

void loop(){

  byte error, address;
  int n = 0;  // Number of deives
 
  Serial.println("Scanning...");
  for(address = 1; address < 127; address++ ){
    /*    
      The i2c_scanner uses the return value of
      the Write.endTransmisstion to see if
      a device did acknowledge to the address.
    */
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      n++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address,HEX);
    }    
  }

  Serial.println((n == 0)? "No device Found !!": "Done!");
  Serial.println();
 
  delay(5000);
}
