#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

#include "Ultrasonic.h"
#include "config.h"
#include "BlocMoteurs.h"
#include "Mouvement.h"
#include "ReseauCapteur.h"
#include "Trappe.h"
#include "ActionneurAvant.h"
#include "Leds.h"
#include "Calibration.h"

/* Moteurs */
SPIClass* dev_spi;
BlocMoteurs* motors;

/* Leds */
// Leds* leds;


/* Capteurs ultrasons */
Ultrasonic* capteur_front_left;
Ultrasonic* capteur_front_right;
Ultrasonic* capteur_back_left;
Ultrasonic* capteur_back_right;
Ultrasonic* capteur_left;
Ultrasonic* capteur_right;
ReseauCapteur* capteurs;

/* Mouvement */
Mouvement* mouvement;

/* Servo */
Servo myservo;

/* Actionneur */
ActionneurAvant* actionneur;

/* Calibration */
Calibration* calibration;

void setup()
{

    /* Configure pins */ 
    pinMode(pinUltrasonFLE, OUTPUT);
    pinMode(pinUltrasonFLT, INPUT);

    pinMode(pinServoPanier, OUTPUT);

    pinMode(pinUltrasonFRE, INPUT);
    pinMode(pinUltrasonFRT, OUTPUT);

    pinMode(pinUltrasonRE, INPUT);
    pinMode(pinUltrasonRT, OUTPUT);

    pinMode(pinUltrasonLE, INPUT); 
    pinMode(pinUltrasonLT, OUTPUT);

    pinMode(pinUltrasonBLE, INPUT); 
    pinMode(pinUltrasonBLT, OUTPUT);

    pinMode(pinUltrasonBRE, INPUT); 
    pinMode(pinUltrasonBRT, OUTPUT);

    pinMode(pinTeamSelector, INPUT_PULLUP);
    
    pinMode(pinHacheur1, OUTPUT);
    pinMode(pinHacheur2, OUTPUT);

    pinMode(pinStarter, INPUT);
    // pinMode(pinLeds, OUTPUT);


    /* Init moteurs */
    
    dev_spi = new SPIClass(D11, D12, D13);
    dev_spi->begin();
    motors = new BlocMoteurs(dev_spi);

    /* Init capteurs */

    capteur_front_left = new Ultrasonic(pinUltrasonFLT, pinUltrasonFLE);
    capteur_front_right = new Ultrasonic(pinUltrasonFRT, pinUltrasonFRE);
    capteur_back_left = new Ultrasonic(pinUltrasonBLT, pinUltrasonBLE);
    capteur_back_left = new Ultrasonic(pinUltrasonBLT, pinUltrasonBRE);

    capteurs = new ReseauCapteur(*capteur_front_left, *capteur_front_right, *capteur_back_left, *capteur_back_right);
 
    /* Init mouvement */
    mouvement = new Mouvement(motors, capteurs);

    /* Init serial */
    Serial.begin(115200);
    while (!Serial);
    //delay(5000); // attendre que le terminal s'ouvre

    /* Init Leds */
    /* leds = new Leds(A3);
    leds->startTimer(95000); // start 95s timer
    leds->Off();
    // leds->On(); // pour tester l'allumage */

    /* Init servo */
    myservo.attach(pinServoPanier);

    /* Calibration */
    calibration = new Calibration(mouvement);

    /* Actionneur */
    actionneur = new ActionneurAvant(pinHacheur1, pinHacheur2);



    /* On attend le signal de start */
    Serial.println("Robot initialised");
    // GLISSIERE A AJOUTER ICI
    delay(2000);
    Serial.println("Match started !");

    /* Ajouter du code de test ici */

    

    /* Fin du code de test*/

    Serial.println("Done");
    /* Tests mouvement */
    /*
    mouvement->deplacement(Avancer, 1000);
    delay(1000);
    mouvement->rotate(Droite);
    delay(1000);
    mouvement->deplacement(Avancer, 1000);
    */

    /* Ancienne version des tests moteurs pour vérif */
    /*
    motors->commande_vitesses(0.3, 0.3, 0.3, 0.3); // avancer
    delay(1000);
    motors->motors_stop_low_hiz();
    delay(500);
    motors->motors_on();
    motors->commande_vitesses(0.3, -0.3, 0.3, -0.3); // tourner à droite
    delay(1500);
    motors->motors_stop_low_hiz();
    delay(500);
    motors->motors_on();
    motors->commande_vitesses(0.3, 0.3, 0.3, 0.3); // avancer
    delay(1000);
    motors->motors_stop_low_hiz();
    */

/* Test servo*/
    motors->motors_stop_low_hiz();

    
}


void loop()
{

}