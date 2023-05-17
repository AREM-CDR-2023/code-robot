#ifndef CALIBRATION_H
#define CALIBRATION_H

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

class Calibration
{
    public:
        Calibration(Mouvement* mouvement);
        ~Calibration();

        void test_rotations();
        void test_deplacements();
        void test_carre();

        void test_global(Servo myservo, ActionneurAvant actionneur);
        
        Mouvement* mouvement;
};

#endif