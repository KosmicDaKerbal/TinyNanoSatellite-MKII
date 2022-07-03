#include <DFRobot_DHT11.h>
#include "Transmission.h"
DFRobot_DHT11 DHT;
void setup() {
  pinMode (scl, OUTPUT); pinMode(sda, OUTPUT); pinMode(wrd, OUTPUT);
}
void loop() {
  if (seconds >= 60) {
    minutes++;
    seconds = 0;
  }
  DHT.read(3);
  transmit (DHT.temperature);
  transmit (DHT.humidity);
  transmit (seconds);
  transmit (minutes);
  seconds = seconds + 4;
}
