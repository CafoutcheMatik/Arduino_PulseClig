#ifndef YPULSECLIG_H
#define YPULSECLIG_H

class yPulseClig // Objet relai
{
private:
    unsigned int choixTemps = 0;     // temps de déclenchement en milliseconde
    unsigned int cumulTemps = 0;     // mémoire du temps en milliseconde
    unsigned int choixTempsClig = 0; // choixTemps divisé par 2 pour le clignotement

public:
    yPulseClig(unsigned int temps_ms);   // Constructeur : attend le temps de déclenchement en parametre.
    void loop(unsigned int cycleMS); // calcul à mettre dans loop
    bool pulse = false;                       // pulse toutes les "choixTemps"
    bool clig = false;                        // clignotement à "choixTemps"
};

#endif