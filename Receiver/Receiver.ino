#include "Process.h"
void setup() {
  boot();
}
void loop() {
  load = digitalRead (ld);
  if (load == true) {
    vrlog = SD.open("TinyNanoSatellite Log.txt", FILE_WRITE);
    loadval();
    compile ();
    verboselog();
    if (vrlog) {
      vrlog.println();
      Serial.println("Cycle Completed.");
    }
  }
}
