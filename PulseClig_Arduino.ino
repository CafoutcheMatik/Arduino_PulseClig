// #pragma GCC optimize("O0")

#include <Arduino.h>
#include "yPulseClig.h"

//
// déclaration :
yPulseClig tps_1sec(1000);  //  1sec = 1000 ms
yPulseClig tps_100ms(100);
yPulseClig tps_3sec(3000);
//
void setup() {
  Serial.begin(115200);  // Terminal
  //
  Serial.print("setup : ");
  Serial.print(millis());
  Serial.println(" ms");
}

void loop() {
  //
  // Créations de variables générales pour gain temps de cycle
  static unsigned long gMemMillis = 0;  // Mémoire millis
  unsigned long gMillis = 0;
  unsigned int gCycleMs = 0;
  //
  gMillis = millis();
  if (gMemMillis > 0) {
    gCycleMs = (unsigned int)(gMillis - gMemMillis);
  }
  gMemMillis = gMillis;

  // A  mettre dans la boucle LOOP
  // tps_1sec.loop(gCycleMs);
  // tps_100ms.loop(gCycleMs);
  tps_3sec.loop(gCycleMs);
  //
  if (tps_3sec.pulse) {
    Serial.print(millis());
    Serial.print(" ms : ");
    Serial.println("pulse 3sec");
  }
}