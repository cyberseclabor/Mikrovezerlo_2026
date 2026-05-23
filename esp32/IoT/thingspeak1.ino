#include <WiFi.h>
#include "ThingSpeak.h"

// WiFi adatok
const char* ssid = "APNev";
const char* password = "jelszo";

// ThingSpeak adatok
unsigned long myChannelNumber = 123456789;    // A Channel ID-d (szám)
const char * myWriteAPIKey = "XXXXXXXXXXX"; // A Write API Key-ed

WiFiClient client;

void setup() {
  Serial.begin(115200);
  
  // WiFi csatlakozás
  WiFi.begin(ssid, password);
  Serial.print("Kapcsolódás a WiFi-hez...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nCsatlakozva!");

  ThingSpeak.begin(client); // ThingSpeak inicializálása
}

void loop() {
  // Véletlenszám generálása 10 és 100 között
  int randomValue = random(10, 101);

  Serial.print("Küldés a ThingSpeak-re: ");
  Serial.println(randomValue);

  // Adat elküldése a Field 1-re
  int response = ThingSpeak.writeField(myChannelNumber, 1, randomValue, myWriteAPIKey);

  if(response == 200){
    Serial.println("Sikeres frissítés!");
  }
  else{
    Serial.println("Hiba a küldés során. HTTP kód: " + String(response));
  }

  // 10 másodperc várakozás
  // Megjegyzés: A ThingSpeak ingyenes verziója 15 másodpercenként enged frissítést.
  // Ha hibát kapsz, érdemes 15000-re emelni.
  delay(20000); 
}
