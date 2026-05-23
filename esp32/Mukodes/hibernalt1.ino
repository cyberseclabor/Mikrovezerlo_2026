void setup() {
  Serial.begin(115200);

  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
  esp_sleep_enable_timer_wakeup(10 * 1000000);

  Serial.println("Hibernation jellegű deep sleep...");
  delay(1000);

  esp_deep_sleep_start();
}

void loop() {}
