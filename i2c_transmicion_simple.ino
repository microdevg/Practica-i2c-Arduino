#include <Wire.h>
// PINES POR DEFECTO SDA 21, SCL 22

const int I2C_SDA = 21;
const int I2C_SCL = 22;
const uint32_t I2C_FREQ = 100000; // 100 kHz
const uint8_t SLAVE_ADDR = 0x3C;  // Cambia según tu dispositivo esclavo

int contador = 0;

void setup() {
  Serial.begin(115200);
  
  // Inicializa I2C con pines personalizados
  Wire.begin(I2C_SDA, I2C_SCL, I2C_FREQ);
  Serial.println("I2C inicializado con SDA=9, SCL=13 a 100kHz.");
}

void loop() {
  char buffer[32];  // Ajusta el tamaño si necesitas más espacio
  snprintf(buffer, sizeof(buffer), "contador = %d", contador);

  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write((uint8_t*)buffer, strlen(buffer));
  Wire.endTransmission();

  Serial.println(buffer);  // Imprime en Serial lo enviado

  contador++;
  delay(1000);  // Espera 1 segundo entre envíos
}

