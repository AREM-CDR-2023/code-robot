#include "Mouvement.h"

Mouvement::Mouvement(BlocMoteurs* moteurs, ReseauCapteur* ResCapteurs)
{
    // set motors to the specified motor
    motors = moteurs;
    capteurs = ResCapteurs;

    safe_mode = Safe;

    /* Debug print */
    if(Serial)
    {
        Serial.println("Mouvement initialised");
    }
}

Mouvement::~Mouvement()
{
    delete motors;
}

// Fait avancer le robot... For testing purposes.
void Mouvement::deplacement(SensDeplacement sens, double distance/*unit?*/)
{
    int signe;
    int tempsAttente;
    int lost_time = 0;

    temp_measure = 0;
    if(sens == Avancer)
        signe = 1;
    else
        signe = -1;

    
    while(temp_measure < distance)
    {
        motors->motors_on();
        int time_start = millis();
        motors->commande_vitesses(signe*VITESSE, signe*VITESSE, signe*VITESSE, signe*VITESSE); // Bouge

        if(safe_mode)
            lost_time = capteurs->EvitementTranslation(signe, motors); // Regarde autour de lui pour reperer un robot adverse
        
        while(millis() < time_start + lost_time + QUANTUM_TEMPS); // On attend pour avancer la bonne distance
        
        motors->motors_stop_low_hiz();
        temp_measure += QUANTUM_DIST;
    }
}

/* Unused */
void Mouvement::mouvementElementaire(int signe)
{
    motors->motors_on();
    motors->commande_vitesses(signe*VITESSE, signe*VITESSE, signe*VITESSE, signe*VITESSE);
    delay(QUANTUM_TEMPS);
    motors->motors_stop_low_hiz();
}

// Rotation dans la direction précisée.
void Mouvement::rotate(SensRotation sens)
{
    switch (sens)
    {
        case Droite:
            motors->motors_on();
            motors->commande_vitesses(0.5, -0.5, 0.5, -0.5);
            delay(DUREE_ROTATION_DROITE);
            motors->motors_stop_low_hiz();
            break;

        case Gauche:
            motors->motors_on();
            motors->commande_vitesses(-0.5, 0.5, -0.5, 0.5);
            delay(DUREE_ROTATION_GAUCHE);
            motors->motors_stop_low_hiz();
            break;
    }
}

void Mouvement::setMode(Mode mode)
{
    safe_mode = (bool) mode;
}

