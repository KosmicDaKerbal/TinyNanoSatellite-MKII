const byte Sensor = 0;
const byte tx1 = 1;
const byte tx2 = 2;
const byte shift = 3;
const byte load = 4;
boolean b1;
boolean b2;
boolean b3;
boolean b4;
boolean b5;
boolean b6;
boolean b7;
boolean b8;
byte count;
void preamble () {
  digitalWrite (tx1, HIGH);
  digitalWrite (tx2, HIGH);
  digitalWrite (shift, HIGH);
  digitalWrite (load, HIGH);
  delay (500);
  digitalWrite (tx1, LOW);
  digitalWrite (tx2, LOW);
  digitalWrite (shift, LOW);
  digitalWrite (load, LOW);
}
void transmit (byte value) {
  byte bytePointer = 0;
  for (byte bin = 128; bin >= 1; bin = bin / 2) {
    if ((value - bin) >= 0) {
      value -= bin;
      if (bytePointer == 0) {
        b1 = 1;
      } else if (bytePointer == 1) {
        b2 = 1;
      } else if (bytePointer == 2) {
        b3 = 1;
      } else if (bytePointer == 3) {
        b4 = 1;
      } else if (bytePointer == 4) {
        b5 = 1;
      } else if (bytePointer == 5) {
        b6 = 1;
      } else if (bytePointer == 6) {
        b7 = 1;
      } else if (bytePointer == 7) {
        b8 = 1;
      }

    }
    else {
      if (bytePointer == 0) {
        b1 = 0;
      } else if (bytePointer == 1) {
        b2 = 0;
      } else if (bytePointer == 2) {
        b3 = 0;
      } else if (bytePointer == 3) {
        b4 = 0;
      } else if (bytePointer == 4) {
        b5 = 0;
      } else if (bytePointer == 5) {
        b6 = 0;
      } else if (bytePointer == 6) {
        b7 = 0;
      } else if (bytePointer == 7) {
        b8 = 0;
      }
    }
    bytePointer++;
  }
  digitalWrite (load, HIGH);
  if (b1 == true) {
    digitalWrite (tx1, HIGH);
  } else {
    digitalWrite (tx1, LOW);
  }
  if (b2 == true) {
    digitalWrite (tx2, HIGH);
  } else {
    digitalWrite (tx2, LOW);
  }
  digitalWrite (shift, HIGH);
  delay (85);
  digitalWrite (shift, LOW);
  delay (85);
  if (b3 == true) {
    digitalWrite (tx1, HIGH);
  } else {
    digitalWrite (tx1, LOW);
  }
  if (b4 == true) {
    digitalWrite (tx2, HIGH);
  } else {
    digitalWrite (tx2, LOW);
  }
  digitalWrite (shift, HIGH);
  delay (85);
  digitalWrite (shift, LOW);
  delay (85);
  if (b5 == true) {
    digitalWrite (tx1, HIGH);
  } else {
    digitalWrite (tx1, LOW);
  }
  if (b6 == true) {
    digitalWrite (tx2, HIGH);
  } else {
    digitalWrite (tx2, LOW);
  }
  digitalWrite (shift, HIGH);
  delay (85);
  digitalWrite (shift, LOW);
  delay (85);
  if (b7 == true) {
    digitalWrite (tx1, HIGH);
  } else {
    digitalWrite (tx1, LOW);
  }
  if (b8 == true) {
    digitalWrite (tx2, HIGH);
  } else {
    digitalWrite (tx2, LOW);
  }
  digitalWrite (shift, HIGH);
  delay (90);
  digitalWrite (tx1, LOW);
  digitalWrite (tx2, LOW);
  digitalWrite (shift, LOW);
  digitalWrite (load, LOW);
  delay (100);
}
