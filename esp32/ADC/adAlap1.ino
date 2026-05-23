// Az ESP32-S3 GPIO 1-es lába alapértelmezés szerint az ADC1_CH0 csatorna
const int analogPin = 1; 

void setup() {
  // A soros kommunikáció inicializálása az eredmények megjelenítéséhez
  Serial.begin(115200);
  delay(1000); 
  Serial.println("Analóg adatgyűjtés indítása...");
}

void loop() {
  // Analóg érték beolvasása (digitális eredmény: 0 - 4095)
  int rawValue = analogRead(analogPin);

  // Az érték átszámítása feszültségre (az ESP32 belső referenciája kb. 3.3V)
  float voltage = (rawValue * 3.3) / 4095.0;

  // Eredmények kiírása a soros monitorra
  Serial.print("Nyers digitális érték: ");
  Serial.print(rawValue);
  Serial.print(" | Megközelítő feszültség: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(500); // Fél másodperces várakozás a mérések között
}
