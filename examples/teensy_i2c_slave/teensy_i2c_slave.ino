#include <i2c_driver.h>
#include <i2c_driver_wire.h>
#include <String.h>

#define SLAVE_ADDRESS 0x08
byte data_to_echo = 0;
std::string str = "I am Teensy\n";
int response_index = 0;

void setup() 
{
  Serial.begin(115200);
  I2C_Wire1.begin(SLAVE_ADDRESS);
  I2C_Wire1.onReceive(receiveData);
  I2C_Wire1.onRequest(sendData);
}

void loop() { }

void receiveData(int bytecount)
{
  for (int i = 0; i < bytecount; i++) {
    data_to_echo = I2C_Wire1.read();
    Serial.print((char)data_to_echo);
  }
}

void sendData()
{
  I2C_Wire1.write(str[response_index]);
  response_index++;
  if(response_index == str.size())
    response_index = 0;
}
