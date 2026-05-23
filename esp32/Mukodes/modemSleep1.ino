
#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_OFF);   // WiFi kikapcsolás
  btStop();              // Bluetooth kikapcsolás

  Serial.println("Modem sleep mód");
}

void loop() {
  Serial.println("CPU fut, rádió kikapcsolva");
  delay(2000);
}
