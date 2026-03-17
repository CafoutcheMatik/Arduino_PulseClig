#include <Arduino.h>
#include "yPulseClig.h"

/*
 *  Permet de générer un pulse et une variable clignotante d'un temps exprimé en milliseconde
 *  hervé CHUTEAU pour le Bistromatik
 *  version 1.01 du 17/03/2026
*/

yPulseClig::yPulseClig(unsigned int temps_ms)
{
  choixTemps = temps_ms;
  choixTempsClig = choixTemps /2;
  pulse = false;
  clig = false;
}

void yPulseClig::loop(unsigned int cycleMS)
{
  cumulTemps += cycleMS;
  //
  pulse = false;
  if (cumulTemps > choixTemps)
  {
    pulse = true;
    cumulTemps -= choixTemps;
  }
  //
  clig=false;
  if (cumulTemps > choixTempsClig)
  {
    clig = true;
  }
}

