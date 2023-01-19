#define in1 1
#define in2 2
#define in3 3
#define in4 4
#define in5 5
#define in6 6
#define in7 7
#define in8 8
#define ld  9
#define chipSelect 10

boolean load;
boolean raw [8] = {0, 0, 0, 0, 0, 0, 0, 0};
byte pointer;
byte output;

#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);
#include <SPI.h>
#include <SD.h>
File vrlog;

void boot (){
  Serial.begin (9600);
  Serial.println("TinyNanoSatellite MKII Receiver Initialization...");
  lcd.init();
  lcd.init();
  lcd.backlight();
  Serial.println ("LCD Initialized.");
  pinMode (in1, INPUT);
  pinMode (in2, INPUT);
  pinMode (in3, INPUT);
  pinMode (in4, INPUT);
  pinMode (in5, INPUT);
  pinMode (in6, INPUT);
  pinMode (in7, INPUT);
  pinMode (in8, INPUT);
  pinMode (ld, INPUT);
  Serial.println ("Inputs Initialized.");
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    while (1);
  }
  Serial.println("Card initialized.");
}
void loadval () {
  if (in1 == HIGH) {
    raw [0] = 1;
  } else {
    raw [0] = 0;
  }
  if (in2 == HIGH) {
    raw [1] = 1;
  } else {
    raw [1] = 0;
  }
  if (in3 == HIGH) {
    raw [2] = 1;
  } else {
    raw [2] = 0;
  }
  if (in4 == HIGH) {
    raw [3] = 1;
  } else {
    raw [3] = 0;
  }
  if (in5 == HIGH) {
    raw [4] = 1;
  } else {
    raw [4] = 0;
  }
  if (in6 == HIGH) {
    raw [5] = 1;
  } else {
    raw [5] = 0;
  }
  if (in7 == HIGH) {
    raw [6] = 1;
  } else {
    raw [6] = 0;
  }
  if (in8 == HIGH) {
    raw [7] = 1;
  } else {
    raw [7] = 0;
  }
  lcd.clear ();
  if (vrlog) {
    vrlog.println("Raw Values copied to RAM.");
    vrlog.print("Copied Binary: ");
    vrlog.print(raw [0]);
    vrlog.print(raw [1]);
    vrlog.print(raw [2]);
    vrlog.print(raw [3]);
    vrlog.print(raw [4]);
    vrlog.print(raw [5]);
    vrlog.print(raw [6]);
    vrlog.println(raw [7]);
    Serial.println("Raw Values copied to RAM.");
    Serial.print("Copied Binary: ");
    Serial.print(raw [0]);
    Serial.print(raw [1]);
    Serial.print(raw [2]);
    Serial.print(raw [3]);
    Serial.print(raw [4]);
    Serial.print(raw [5]);
    Serial.print(raw [6]);
    Serial.println(raw [7]);
  }
}
void compile () {
  output = (raw [0] * 128) + (raw [1] * 64) + (raw [2] * 32) + (raw [3] * 16) + (raw [4] * 8) + (raw [5] * 4) + (raw [6] * 2) + (raw [7] * 1);
  if (vrlog) {
    vrlog.println("Binary Converted to decimal.");
    vrlog.print ("Decimal Value: ");
    vrlog.println (output);
    Serial.println("Binary Converted to decimal.");
    Serial.print ("Decimal Value: ");
    Serial.println (output);
  }
  lcd.setCursor (0, 0);
  lcd.print ("Raw Value: ");
  lcd.print (output);
  lcd.setCursor (0, 1);
}
void verboselog () {
  vrlog.println ("-INCOMING SATELLITE DATA-");
  if (output == 201) {
    lcd.print ("Synchronized");
    pointer = 0;
    EEPROM.update (0, pointer);
    if (vrlog) {
      vrlog.println("Synchronized with Satellite.");
      Serial.println("Synchronized with Satellite.");
    }
  }
  if (output == 202) {
    lcd.print ("Error: Bad Temp.");
    if (vrlog) {
      vrlog.print("Error Reading Temperature; Code: ");
      vrlog.println (output);
      Serial.print("Error Reading Temperature; Code: ");
      Serial.println (output);
    }
  }
  if (output == 203) {
    lcd.print ("Err: Bad Humid..");
    if (vrlog) {
      vrlog.print("Error Reading Humidity; Code: ");
      vrlog.println (output);
      Serial.print("Error Reading Humidity; Code: ");
      Serial.println (output);
    }
  }
  if (output > 203) {
    lcd.print ("Error: Bad Read");
    if (vrlog) {
      vrlog.println("An Unexpected Read Error Occured.");
      Serial.println("An Unexpected Read Error Occured.");
    }
  }
  if (EEPROM.read (0) == 0 and output < 201) {
    lcd.print ("Count OK");
    if (vrlog) {
      vrlog.print("Count: ");
      vrlog.println (output);
      Serial.println("Count OK");
    }
  }
  if (EEPROM.read (0) == 1 and output < 201) {
    lcd.print ("Temperature OK");
    if (vrlog) {
      vrlog.print("Temperature: ");
      vrlog.println (output);
      Serial.print("Temperature OK");
    }
  }
  if (EEPROM.read (0) == 2 and output < 201) {
    lcd.print ("Humidity OK");
    if (vrlog) {
      vrlog.print("Humidity: ");
      vrlog.println (output);
      Serial.print("Humidity OK");
    }
  }
  pointer++;
  if (pointer > 2) {
    pointer = 0;
  }
  EEPROM.update (0, pointer);
  vrlog.println ("-END OF INCOMING SATELLITE DATA-");
}
