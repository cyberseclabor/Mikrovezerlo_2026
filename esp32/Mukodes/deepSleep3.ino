#include "esp_sleep.h"

RTC_DATA_ATTR int bootCount = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  bootCount++;
  Serial.println("Boot: " + String(bootCount));

  esp_sleep_enable_timer_wakeup(5 * 1000000);

  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);

  Serial.println("Sleep...");
  delay(1000);

  esp_deep_sleep_start();
}

void loop() {}
