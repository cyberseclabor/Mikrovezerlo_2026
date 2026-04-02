  GNU nano 8.0                                                             sketch_mar31a.ino                                                                      
void szamol()
{

}

void setup() {

  Serial.begin(115200);

  Serial.println(ESP.getChipCores());
  Serial.println(ESP.getChipModel());


}

void loop() {

  // ezt a for ciklust a Serial Plotter miatt tettük be
  
/*
  for (int a = 0; a < 100; a++) {

    Serial.println(random(10, 100));

  }
*/

}

