// I2C scanner básico
#include <Wire.h>
void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial);
  Serial.println("\nEscaneando...");
  for (byte i = 1; i < 127; ++i) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo I2C encontrado en 0x");
      Serial.println(i, HEX);
    }
  }
  Serial.println("Escaneo terminado.");
}
void loop() {}