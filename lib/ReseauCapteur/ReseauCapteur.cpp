#include "ReseauCapteur.h"

ReseauCapteur::ReseauCapteur(Ultrasonic pinAvant1, Ultrasonic pinAvant2, Ultrasonic pinArriere1, Ultrasonic pinArriere2, Ultrasonic pinGauche, Ultrasonic pinDroite)
    : Avant1(pinAvant1), Avant2(pinAvant2), Arriere1(pinArriere1), Arriere2(pinArriere2), Gauche(pinGauche), Droite(pinDroite)
{
    //Mettre en argument les paires de pin
}

uint32_t ReseauCapteur::EvitementTranslation(int signe, BlocMoteurs* motors)
{
    uint32_t stop_time;
    uint32_t start_time;
    uint32_t time_lost = 0;
    switch (signe) //Choix d'avant ou arriere
    {
    case 1:
        
        if (((Avant1.read() < LIMITE_CM) && (Avant1.read() != 0)) || ((Avant2.read() < LIMITE_CM) && (Avant2.read() != 0)))
        {
            //Si l'un des deux capteurs detecte un obstacle à moins de 20cm, le robot s'arrête 
            motors->motors_stop_low_hiz();
            stop_time = millis();

            int secu = 0; //Verifie si le robot abverse s'est éloigné en vérifiant VERIF fois.
            while(secu < VERIF)
            {
                if (((Avant1.read() > LIMITE_CM) && (Avant1.read() != 0)) || ((Avant2.read() > LIMITE_CM) && (Avant2.read() != 0)))
                {
                    secu++;
                }
                else
                {
                    secu = 0;
                }
            }
            // On redémarre le moteur 
            motors->motors_on();
            motors->commande_vitesses(signe*VITESSE, signe*VITESSE, signe*VITESSE, signe*VITESSE);
            // On calcule le temps d'arrêt
            start_time = millis();
            time_lost = start_time - stop_time;
        }
        break;
    
    case -1: //Idem pour l'arriere   
        if (((Arriere1.read() < LIMITE_CM) && (Arriere1.read() != 0)) || ((Arriere2.read() < LIMITE_CM) && (Arriere2.read() != 0))) 
        {
            motors->motors_stop_low_hiz();
            stop_time = millis();

            int secu = 0;
            while(secu < VERIF)
            {
                if (((Arriere1.read() > LIMITE_CM) && (Arriere1.read() != 0)) || ((Arriere2.read() > LIMITE_CM) && (Arriere2.read() != 0)))
                {
                    secu++;
                }
                else
                {
                    secu = 0;
                }
            }
            // On redémarre le moteur 
            motors->motors_on();
            motors->commande_vitesses(signe*VITESSE, signe*VITESSE, signe*VITESSE, signe*VITESSE);
            // On calcule le temps d'arrêt
            start_time = millis();
            time_lost = start_time - stop_time;
        }
        break;
    }
    return time_lost;
}

void ReseauCapteur::EvitementRotation() //Fonctionne de la même manière pour les rotations
{
    while(testCotes());
    return;
}

bool ReseauCapteur::testCotes()
{
    bool test_droite = Droite.read() < LIMITE_CM && Droite.read() != 0;
    bool test_gauche = Gauche.read() < LIMITE_CM && Gauche.read() != 0;

    return test_gauche && test_droite;
}