#include <DFRobot_DHT11.h>
#include "Transmission.h"
DFRobot_DHT11 DHT;
void setup() {
  pinMode (tx1, OUTPUT); pinMode(tx2, OUTPUT); pinMode(shift, OUTPUT); pinMode(load, OUTPUT);
  preamble ();
}
void loop() {
  DHT.read(Sensor);
  byte T = DHT.temperature;
  byte H = DHT.humidity;
  transmit (count);
  transmit (T);
  transmit (H);
  count++;
}
