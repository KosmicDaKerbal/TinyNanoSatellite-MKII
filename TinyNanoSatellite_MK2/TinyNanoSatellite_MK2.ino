#include "Transmission.h"
#include <EEPROM.h>
void setup() {
  pinMode (tx1, OUTPUT); pinMode(tx2, OUTPUT); pinMode(shift, OUTPUT); pinMode(load, OUTPUT);
}
void loop() {
  EEPROM.update (0, count);
  DHT.read(Sensor);
  byte T = DHT.temperature;
  byte H = DHT.humidity;
  transmit (201);  // Sync Code
  transmit (EEPROM.read (0)); //Power Down Redundancy
  if (T != 255) {
    transmit (T);
  } else {
    transmit (202); // Error Code 202
  }
  if (H != 255) {
    transmit (H);
  } else {
    transmit (203);// Error Code 203
  }
  count++;
  if (count > 200) {
    count = 0;
  }
}
