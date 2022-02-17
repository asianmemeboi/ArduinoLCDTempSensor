#include <EEPROM.h>

int address = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < EEPROM.length(); i++) {
    Serial.print(address);
    Serial.print(", ");
    Serial.println(EEPROM.read(i));
    address++;
  }
}

void loop(){
  
  
}
