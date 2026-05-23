#include "esp_sleep.h"

#define uS_TO_S_FACTOR 1000000ULL

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Deep sleep 10 másodpercre...");

  esp_sleep_enable_timer_wakeup(10 * uS_TO_S_FACTOR);

  esp_deep_sleep_start();
}

void loop() {
}
