#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

#include "config.h"
#include "BlocMoteurs.h"
#include "MagneticEncodeurs.h"
#include "Odometrie.h"
#include "ControleurPID.h"

SPIClass* dev_spi;
BlocMoteurs* motors;

void setup()
{
    dev_spi = new SPIClass(D11, D12, D13);
    dev_spi->begin();
    motors = new BlocMoteurs(dev_spi);

    motors->motors_on();
    motors->commande_vitesses(0.5,0.5,0.5,0.5);
    delay(1000);
    motors->motors_stop_low_hiz();
}

void loop()
{
}