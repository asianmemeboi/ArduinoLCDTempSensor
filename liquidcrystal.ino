// Imported Libraries
#include <LiquidCrystal.h>
#include <EEPROM.h>

// Buttons mapped
const int up = 101;
const int down = 259;
const int left = 411;
const int right = 0;
const int sel = 639;

// maps Arduino to LCD pins
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Timer and EEMPROM variables
unsigned long previousTime = 0;
const long interval = 600000; // The amount of time before an input is logged (IN MILLISECONDS)
bool recording = false;
int address = 0;

// Sexy Symbols
byte degreesymbol[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte amogus[8] = {
  0b01110,
  0b11111,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b10001,
  0b10001
};

// Setup function sets up the program
void setup() {
  // Sets up the Serial and LCD
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  // Creates the Symbols
  lcd.createChar(0, degreesymbol);
  lcd.createChar(1, amogus);

  //Sets the pins as input
  pinMode(A0, INPUT);
  pinMode(A5, INPUT_PULLUP);
}

void loop() {
  // Sets buttons to pin A0
  int button = analogRead(A0);

  // Changes the values from temp sensor into Celsius
  float temp = 80.6 - 0.294 * analogRead(A5) + 0.000265 * analogRead(A5) * analogRead(A5);
  float tempf = ((9/5) * temp) + 32;

  // Constantly prints the Celsius out on the first line of the LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp (C");
  lcd.write(byte(0));
  lcd.print("): ");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Select for help ");
  
  // Makes the select button displays instructions
  if (button >= sel - 10 && button <= sel + 10) {
    lcd.setCursor(0, 0);
    lcd.print("Left-erase mem                      ");
    delay(2000);
    lcd.setCursor(0, 0);
    lcd.print("Up-Start Rcrd                       ");
    delay(2000);                     
    lcd.setCursor(0, 0);                                                                                                              
    lcd.print("Down-End Rcrd                       ");
    delay(2000);
    lcd.setCursor(0, 0);
    lcd.print("Right-UNLEASH ");
    lcd.write(byte(1));
    lcd.print("                        ");
    delay(2000);                      
    lcd.setCursor(0, 0);                                                                            
    lcd.print("RST - DONT PRESS                    ");
    delay(2000);
  }

  // Makes the up button start recording info to the EEPROM
  if (button >= up - 10 && button <= up + 10) {
    recording = true;
    lcd.setCursor(0, 1);
    lcd.print("Rcrd Start Zaddy ");
    lcd.write(byte(1));
    delay(1000);
  }

  // Makes the down button stop recording info to the EEPROM (Does not clear mem)
  if (button >= down - 10 && button <= down + 10) {
    recording = false;
    lcd.setCursor(0, 1);
    lcd.print("Rcrd End Zaddy ");
    lcd.write(byte(1));
    delay(1000);
  }

  // Clears the mem from EEPROM
  if (button >= left - 10 && button <= left + 10) {
    lcd.setCursor(0, 1);
    lcd.print("MEM CLEARED Zaddy ");
    lcd.write(byte(1));
    for(int i = 0; i < EEPROM.length(); i++) {
      EEPROM.write(i, 0);
    }
    delay(250);
  }



  
  // Times the Arduino to log info to EEPROM every 10 minutes
  if (millis() - previousTime >= interval && recording) {
    EEPROM.write(address, temp);
    previousTime = millis();
    address++;
    
  }
  
}

//Copyright AW Corp ©
