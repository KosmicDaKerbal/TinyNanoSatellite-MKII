#include <EEPROM.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define Sensor 0
byte T, H, cycle, mod;
void initialize () {
  DDRB = B00011110;
  cycle = EEPROM.read (0);
}
void readDHT () {
  DHT.read(Sensor);
  T = DHT.temperature;
  H = DHT.humidity;
}
boolean bin (byte num, byte pv){
  if (num - pv > 0) return 0;
  mod = num - pv;
  return 1;
}
void transmit (byte num) {
   mod = num;
  for (byte a = 128; a >= 1; a = a / 4) {
    PORTB |= (bin(mod, a) * 2) + (bin(mod, a/2) * 4) + 8;
    delay (85);
    PORTB -= 8;
    delay (85);
  }
  PORTB |= 0;
  delay (85);
  PORTB |= 16;
  delay (85);
  PORTB |= 0;
}
