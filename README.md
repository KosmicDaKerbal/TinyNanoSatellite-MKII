# TinyNanoSatellite-MKII

Second Prototype of the TinyNanoSatellite, a cheap nanosatellite based on the Atmel ATTiny13 Microcontroller.

Parts Used:
* Atmel ATTiny13A Microcontroller Clocked at 600KHz
* DHT11 Temperature and Humidity Sensor
* HT12E Radio Encoder
* Generic 433 / 434 MHz Radio Transmitter
* Any Kind of Battery with capacity > 30MAh

ATtiny13 Pins:

* Digital Pin 0 - Connected to DHT11 Sensor
* Digital Pin 1 - Connected to Bit 1 of Transmission
* I/O Pin 2 - Connected to Bit 2 of Transmission
* I/O Pin 3 - Connected to Shift Transmission
* I/O Pin 4 - Connected to Load of Transmission

Receiver:

Use any Microcontroller with Chip ATmega328p and Above.
* Receiver uses all three communication modes i.e. UART, SPI and I2C, so make sure you use the proper pins for that.
* Use an I2C LCD instead of regular LCD.
* Make sure Microcontroller has support for EEPROM.
* Requires SPI SD Card for Data Logging.

Arduino Pins:
* Digital Pins 1-8 - Input Bits
* Digital Pin 9 - Load Input
* Digital Pin 10 - Chip Select for SD Card
* I2C - Pins A4 (SDA) and A5 (SCL) for Atmega328p and Pins 20 (SDA) and 21 (SCL) for Atmega 1280 / 2560.
