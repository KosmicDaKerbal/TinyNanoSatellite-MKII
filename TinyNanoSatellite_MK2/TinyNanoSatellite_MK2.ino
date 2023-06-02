#include "Transmission.h"
void setup() {
  initialize ();
}
void loop() {
  readDHT();
  transmit (cycle);
  if (T != 255) {
    transmit (EEPROM.read (1));
    EEPROM.update (1, T);
  }
  else {
    transmit (201);
  }
  if (H != 255) {
    transmit (EEPROM.read (2));
    EEPROM.update (2, H);
  }
  else {
    transmit (202);
  }
  cycle++;
  if (cycle >= 200) {
    cycle = 0;
    EEPROM.write (0, 0);
  }
  EEPROM.update (0, cycle);
}
