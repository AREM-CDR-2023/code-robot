#include "Calibration.h"

Calibration::Calibration(Mouvement* mouvement)
{
    mouvement = mouvement;
}

Calibration::~Calibration()
{
    delete mouvement;
}

void Calibration::test_rotations() 
{
    // tour complet à droite, retour position initiale
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);

    // tour complet à gauche, retour position initiale
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_GAUCHE);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_GAUCHE);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_GAUCHE);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_GAUCHE);

    // demi-tour droite, demi-tour gauche, retour position initiale
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_DROITE);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_DROITE);
}

// modifier le 1000 du déplacement selon l'unité normalisée
void Calibration::test_deplacements() 
{
    // aller retour sur >50 cm (vérifier distance et décalage aller/retour)
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
    mouvement->deplacement(Reculer, 1000);
    delay(AUTOMATIC_DELAY);
}

void Calibration::test_carre() 
{
    // rotation, départ à gauche
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_DROITE);
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_DROITE);
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
    mouvement->rotate(Gauche);
    delay(DUREE_ROTATION_DROITE);
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);

    // rotation, départ à droite
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
    mouvement->rotate(Droite);
    delay(DUREE_ROTATION_DROITE);
    mouvement->deplacement(Avancer, 1000);
    delay(AUTOMATIC_DELAY);
}

void Calibration::test_global(Servo myservo, ActionneurAvant actionneur)
{
    Serial.println("Test Rotations");
    test_rotations();

    Serial.println("Test Carre");
    test_carre();

    Serial.println("Test Trappe");
    ouvrir(myservo);
    delay(4000);
    fermer(myservo);

    Serial.println("Test Capteur Ultrasons");
    Serial.print("Avant1 : ");
    Serial.println(mouvement->capteurs->Avant1.read()); //Lis juste le capteur
    Serial.print("Avant2 : ");
    Serial.println(mouvement->capteurs->Avant2.read());
    Serial.print("Arriere1 : ");
    Serial.println(mouvement->capteurs->Arriere1.read());
    Serial.print("Arriere2 : ");
    Serial.println(mouvement->capteurs->Arriere2.read());

    Serial.println("Test ActionneurAvant");
    actionneur.serrer();
    actionneur.deserrer();

}