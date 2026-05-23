deep sleep (nyomógombos ébresztés)

#define BUTTON_PIN 33

void setup() {
  Serial.begin(115200);

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 0); // LOW-ra ébred

  Serial.println("Nyomd meg a gombot az ébresztéshez...");
  delay(1000);

  esp_deep_sleep_start();
}

void loop() {}
