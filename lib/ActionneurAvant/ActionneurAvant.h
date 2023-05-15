#ifndef ACTIONNEURAVANT_H
#define ACTIONNEURAVANT_H

#include <Arduino.h>

#define TEMPS_VISSAGE 5000

class ActionneurAvant
{
    public:
        ActionneurAvant(int entree_pin_horaire, int entree_pin_fermee);
        void serrer();
        void deserrer();

    private:
        int nm_PIN_Horaire;
        int nm_PIN_Trigo;

};

#endif