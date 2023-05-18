#ifndef EVITEMENT_H
#define EVITEMENT_H

#include "BlocMoteurs.h"
#include "Ultrasonic.h"
#include "Arduino.h"
#include "config.h"

class ReseauCapteur
{
public:
    ReseauCapteur(Ultrasonic Avant1, Ultrasonic Avant2, Ultrasonic Arriere1, Ultrasonic Arriere2);

    /* On fonce pas dans un obstacle, on s'arrête. Renvoie le temps d'arrêt. */
    uint32_t EvitementTranslation(int signe, BlocMoteurs* motors);

    Ultrasonic Avant1;
    Ultrasonic Avant2;
    Ultrasonic Arriere1;
    Ultrasonic Arriere2;
};

#endif
