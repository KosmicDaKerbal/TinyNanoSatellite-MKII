byte b1;
byte b2;
byte b3;
byte b4;
byte b5;
byte b6;
byte b7;
byte b8;
byte arrayPosition = 0;
const byte sda = 0;
const byte scl = 1;
const byte wrd = 2;
byte calc;
int minutes;
byte seconds;
void transmit (byte num) {
  calc = 0;
  for (byte a = 128; a >= 1; a = a / 2) {
    if ((num - a) >= 0) {
      num -= a;
      if (arrayPosition == 0) {
        b1 = 1;
      } else if (arrayPosition == 1) {
        b2 = 1;
      } else if (arrayPosition == 2) {
        b3 = 1;
      } else if (arrayPosition == 3) {
        b4 = 1;
      } else if (arrayPosition == 4) {
        b5 = 1;
      } else if (arrayPosition == 5) {
        b6 = 1;
      } else if (arrayPosition == 6) {
        b7 = 1;
      } else if (arrayPosition == 7) {
        b8 = 1;
      }
    }
    else {
      if (arrayPosition == 0) {
        b1 = 0;
      } else if (arrayPosition == 1) {
        b2 = 0;
      } else if (arrayPosition == 2) {
        b3 = 0;
      } else if (arrayPosition == 3) {
        b4 = 0;
      } else if (arrayPosition == 4) {
        b5 = 0;
      } else if (arrayPosition == 5) {
        b6 = 0;
      } else if (arrayPosition == 6) {
        b7 = 0;
      } else if (arrayPosition == 7) {
        b8 = 0;
      }
    }
    arrayPosition++;
  }
  digitalWrite (wrd, HIGH);
  delay (100);
  while (calc < 8) {
    digitalWrite (scl, HIGH);
    if (calc == 0) {
      if (b1 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b1 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    } else if (calc == 1) {
      if (b2 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b2 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    } else if (calc == 2) {
      if (b3 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b3 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    } else if (calc == 3) {
      if (b4 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b4 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    } else if (calc == 4) {
      if (b5 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b5 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    } else if (calc == 5) {
      if (b6 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b6 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    } else if (calc == 6) {
      if (b7 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b7 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    } else if (calc == 7) {
      if (b8 == 0) {
        digitalWrite (sda, LOW);
        delay (50);
      } else if (b8 == 1) {
        digitalWrite (sda, HIGH);
        delay (50);
      }
    }
    digitalWrite (sda, LOW);
    digitalWrite (scl, LOW);
    delay (50);
    calc++;
  }
  digitalWrite (wrd, LOW);
  delay (100);
}
