#pragma once

#include <math.h>

// --- //
// Actionneur Avant (Vis pour faire pression sur les gâteaux)
// --- //

/* Temps de vissage pour passer de la position haute à la position basse [en ms] */
#define TEMPS_VISSAGE 5000 // /!\ PLACEHOLDER /!\ à mesurer

// --- //
// Bloc Moteurs
// --- //

/* Consigne de vitesse max envoyée au shield moteurs (en pulse per second) */
#define MAX_VITESSE 600.0

/* Rayon de la roue [en mm] */
#define RAYON_ROUE 30 // /!\ PLACEHOLDER /!\ à mesurer

/* Distance effectuee par une roue lors d'une rotation, [en mm] */
#define DISTANCE_ROTATION 100 // /!\ PLACEHOLDER /!\ à mesurer

/* Coefficients de vitesses des moteurs pour faire une ligne droite */
// Avant-gauche : FL, Avant-droite : FR, Arrière-gauche : BL, Arrière-droite : BR
#define COEF_FL 1.0
#define COEF_FR 1.0
#define COEF_BL 1.0
#define COEF_BR 1.0

// --- //
// Calibration mouvements
// --- //

/* Durée d'un déplacement élémentaire [en ms]*/
#define QUANTUM_TEMPS           100      

/* Distance parcourue par un déplacement élémentaire [en ??] */
#define QUANTUM_DIST            100 // /!\ PLACEHOLDER /!\ à mesurer     

/* Durée d'une rotation de 90° vers la droite */
#define DUREE_ROTATION_DROITE   1002

/* Durée d'une rotation de 90° vers la gauche */
#define DUREE_ROTATION_GAUCHE   1005

/* Vitesse normalisée des moteurs pendant une rotation (entre 0 et 1) */
#define VITESSE_ROTATION        0.4

/* Vitesse normalisée des moteurs pendant un déplacement en ligne droite (entre 0 et 1) */
#define VITESSE                 0.4

/* Délai entre deux déplacements */
#define AUTOMATIC_DELAY         500

// --- //
// ReseauCapteur
// --- //

/* Distance minimale au robot adverse pour ne pas s'arrêter */
#define LIMITE_CM 20

/* Nombre de mesures nécessaires avant de relancer les moteurs */
#define VERIF 10

// --- //
// Leds
// --- //

// Rien à define, juste le temps de timer est 90 000 ms

// --- //
// Mouvement
// --- //

// Rien à define

// --- //
// Odometrie (à supprimer)
// --- //

// Rien à define

// --- //
// Trajet
// --- //

/* Erreur max sur un déplacement, doit être >= QUANTUM_DIST (défini dans la section Calibration Mouvement) */
#define ERREUR_MAX QUANTUM_DIST*1.1

// --- //
// Trappe
// --- //

/* Commande du servomoteur pour mettre la trappe en position fermée */
#define POS_FERME 10

/* Commande du servomoteur pour mettre la trappe en position ouverte */
#define POS_OUVERTE 160

// --- //
// Ultrasonics
// --- //

/* Diviseurs pour traduire les données du capteur à ultrason [en cm]*/
#define CM 28
#define INC 71

// --- //
// Pins
// --- //

#define pinUltrasonFLE D1       // Pin "Echo" du capteur à ultrason Avant Gauche (câble orange sur le PCB) (en fait c'est peut-être le droite) (FLE c'est pour Feurward Left Echo)
#define pinUltrasonFLT D2       // Pin "Trig" du capteur à ultrason Avant Gauche (câble jaune sur le PCB)
// La D3 est inutilisable
#define pinServoPanier D3       // Pin commandant le servomoteur du portail du panier orange (câble vert sur le PCB)
#define pinUltrasonFRE D5       // Pin "Echo" du capteur à ultrason Avant Droite (câble orange sur le PCB) (en fait c'est peut-être le gauche)
#define pinUltrasonFRT D6       // Pin "Trig" du capteur à ultrason Avant Droite (câble jaune sur le PCB)
#define pinUltrasonRE D7        // Pin "Echo" du capteur à ultrason Droite (câble orange sur le PCB)
#define pinUltrasonRT D8        // Pin "Trig" du capteur à ultrason Droite (câble vert sur le PCB)
#define pinUltrasonLE D9        // Pin "Echo" du capteur à ultrason Gauche (câble jaune sur le PCB)
#define pinUltrasonLT D10       // Pin "Trig" du capteur à ultrason Gauche (câble blanc sur le PCB)
#define pinUltrasonBLE D11      // Pin "Echo" du capteur à ultrason Arrière Gauche (câble gris sur le PCB) (en fait c'est peut-être le droite)
#define pinUltrasonBLT D12      // Pin "Trig" du capteur à ultrason Arrière Gauche (câble bleu sur le PCB)
#define pinUltrasonBRE D13      // Pin "Echo" du capteur à ultrason Arrière Droite (câble orange sur le PCB) (en fait c'est peut-être le gauche)
#define pinUltrasonBRT D14      // Pin "Trig" du capteur à ultrason Arrière Droite (câble rouge sur le PCB)
#define pinTeamSelector D15     // Pin du switch de sélection de l'équipe (câble jaune clair sur le PCB) --> à souder

#define pinHacheur1 A0          // Pin "INT1" du hacheur du MCC de l'actionneur presse palais (câble bleu sur le PCB)
#define pinHacheur2 A1          // Pin "INT2" du hacheur du MCC de l'actionneur presse palais (câble jaune sur le PCB)
#define pinStarter A2           // Pin du machin sur lequel on tire pour lancer le programme du robot au début d'un match (câble rouge sur le PCB)
#define pinLeds A3              // Pin de l'alimentation des LEDs (en analogique parce que y'avait plus de pins digitales) (câble rouge sur le PCB)
