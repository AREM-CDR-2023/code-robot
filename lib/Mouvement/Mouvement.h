#ifndef MOUVEMENT_H
#define MOUVEMENT_H
// Constantes à modifier selon le test robot

#include "BlocMoteurs.h"
#include "config.h"
#include "ReseauCapteur.h"

enum Mode
{
    Unsafe, // Yes, you may go full speed into that wall...
    Safe // SONAR ON, pls don't disqualify me
};

enum SensDeplacement
{
    Reculer,
    Avancer
};

enum SensRotation
{
    Gauche,
    Droite
};

// Classe mouvement pour des déplacements de base
class Mouvement
{
    public:
        Mouvement(BlocMoteurs* _moteurs, ReseauCapteur* ResCapteurs);
        ~Mouvement();

        void deplacement(SensDeplacement sens, double distance/*unit?*/);
        void rotate(SensRotation sens);

        // signe = 1 pour avancer et -1 pour reculer
        void mouvementElementaire(int signe);

        void setMode(Mode mode);
  
        BlocMoteurs* motors;
        ReseauCapteur* capteurs;

    private:
    
        double temp_measure; // for simple methods like forward...
        bool safe_mode;

       
};

#endif