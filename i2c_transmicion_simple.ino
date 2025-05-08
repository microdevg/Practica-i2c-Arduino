

// PINES POR DEFECTO SDA 21, SCL 22
#include <string.h>
#include <LiquidCrystal_I2C.h>
#include  <Wire.h>
LiquidCrystal_I2C lcd(0x27,  16, 2);

char buffer[40]={0};
int contador = 0;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  sprintf(buffer,"Contador:%d",contador++);
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print(buffer);
  Serial.print(buffer);

}
