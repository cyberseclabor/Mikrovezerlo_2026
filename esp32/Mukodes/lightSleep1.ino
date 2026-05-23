#include "esp_sleep.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Light sleep indul...");

  esp_sleep_enable_timer_wakeup(5 * 1000000); // 5 sec

  esp_light_sleep_start();

  Serial.println("Felébredtünk!");
}

void loop() {
}
