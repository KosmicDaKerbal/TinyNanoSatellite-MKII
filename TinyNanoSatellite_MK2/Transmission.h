#define TXA 1
#define TXB 2
#define SFT 3
#define LOD 4
byte cycle;
byte T;
byte H;
#include <EEPROM.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define Sensor 0
boolean binary [8] = {0, 0, 0, 0, 0, 0, 0, 0};
void initialize () {
  pinMode (TXA, OUTPUT);
  pinMode (TXB, OUTPUT);
  pinMode (SFT, OUTPUT);
  pinMode (LOD, OUTPUT);
  cycle = EEPROM.read (0);
}
void readDHT () {
  DHT.read(Sensor);
  T = DHT.temperature;
  H = DHT.humidity;
}
void transmit (byte num) {
  byte AP = 1;
  for (byte a = 128; a >= 1; a = a / 2) {
    if ((num - a) >= 0) { //1
      binary [AP] = true;
      num -= a;
    }
    else { //0
      binary [AP] = false;
    }
    AP++;
  }
  for (byte b = 1; b <= 8; b = b + 2) {
    digitalWrite (TXA, binary [b]);
    digitalWrite (TXB, binary [b + 1]);
    digitalWrite (SFT, HIGH);
    delay (85);
    digitalWrite (SFT, LOW);
    delay (85);
  }
  digitalWrite (TXA, 0);
  digitalWrite (TXB, 0);
  digitalWrite (LOD, LOW);
  delay (85);
  digitalWrite (LOD, HIGH);
  delay (85);
}
