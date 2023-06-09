/**
 ******************************************************************************
 * @file    XNucleoIHM02A1.cpp
 * @author  AST / Software Platforms and Cloud
 * @version V1.0
 * @date    November 3rd, 2015
 * @brief   Implementation file for the X_NUCLEO_IHM02A1 expansion board.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */


/* Generated with STM32CubeTOO -----------------------------------------------*/


/* Includes ------------------------------------------------------------------*/

/* ACTION 1 ------------------------------------------------------------------*
 * Include here platform specific header files.                               *
 *----------------------------------------------------------------------------*/
#include "Arduino.h"
#include "SPI.h"
/* ACTION 2 ------------------------------------------------------------------*
 * Include here expansion board specific header files.                        *
 *----------------------------------------------------------------------------*/
#include "XNucleoIHM02A1.h"


/* Variables -----------------------------------------------------------------*/

/* Number of expansion boards. */
uint8_t XNucleoIHM02A1::number_of_boards = 0;


/* Methods -------------------------------------------------------------------*/

/**
 * @brief Constructor.
 * @param init_0        pointer to the initialization structure of the first motor.
 * @param init_1        pointer to the initialization structure of the second motor.
 * @param flag_irq      pin name of the FLAG pin of the component.
 * @param busy_irq      pin name of the BUSY pin of the component.
 * @param standby_reset pin name of the STBY\RST pin of the component.
 * @param ssel          pin name of the SSEL pin of the SPI device to be used for communication.
 * @param spi           SPI device to be used for communication.
 */
XNucleoIHM02A1::XNucleoIHM02A1(L6470_init_t *init_0, L6470_init_t *init_1, L6470_init_t *init_2, L6470_init_t *init_3,  uint8_t flag_irq, uint8_t flag_irq2, uint8_t busy_irq, uint8_t busy_irq2, uint8_t standby_reset, uint8_t standby_reset2, uint8_t ssel, uint8_t ssel2, SPIClass *spi) : standby_reset(standby_reset), standby_reset2(standby_reset2), dev_spi(spi)
{
    ssl1 = ssel;
    ssl2 = ssel2;
    /* Checking stackability. */
    if (!(number_of_boards < EXPBRD_MOUNTED_NR_MAX)) {
        /*Do nothing*/
    }
    instance_id = number_of_boards++;

    /* SPI communication. */


    pinMode(standby_reset, OUTPUT);
    pinMode(standby_reset, OUTPUT);
    pinMode(ssel, OUTPUT);
    pinMode(ssel2, OUTPUT);
    digitalWrite(ssel2, LOW);
    digitalWrite(ssel, HIGH);
  

    /* Instantiating the components. */
    /* ACTION 3 --------------------------------------------------------------*
     * Instantiate here the expansion board's components.                     *
     *                                                                        *
     * Example:                                                               *
     *   component_1 = new COMPONENT_1(ssel, *dev_spi);                       *
     *   component_2 = new COMPONENT_2(ssel, *dev_spi);                       *
     *------------------------------------------------------------------------*/

    components[0] = l6470_0 = new L6470(flag_irq, busy_irq, standby_reset, ssel, dev_spi);
    components[1] = l6470_1 = new L6470(flag_irq, busy_irq, standby_reset, ssel, dev_spi);
    digitalWrite(ssel, LOW);
    digitalWrite(ssel2, HIGH);

  

    // components[2] = l6470_2 = new L6470(flag_irq2, busy_irq2, standby_reset2, ssel2, dev_spi);
    // components[3] = l6470_3 = new L6470(flag_irq2, busy_irq2, standby_reset2, ssel2, dev_spi);

    digitalWrite(ssel2, LOW);

    /* Initializing the components. */
    init_components[0] = init_0;
    init_components[1] = init_1;
    init_components[2] = init_2;
    init_components[3] = init_3;
    if (!init()) {
        /*Do nothing*/
    }
}


bool XNucleoIHM02A1::init(void)
{
    /* Initializing the components. */
    /* ACTION 4 --------------------------------------------------------------*
     * Initialize here the expansion board's components.                      *
     *                                                                        *
     * Example:                                                               *
     *   return (init_COMPONENT_1() && init_COMPONENT_2());                   *
     *------------------------------------------------------------------------*/
    /* Disable the L6470. */
    digitalWrite(standby_reset, 0);

    /* Wait for at least t_STBY,min */
    delay(1);

    /* Enable the L6470. */
    digitalWrite(standby_reset, 1);

    /* Wait for at least t_logicwu */
    delay(1);

    return (init_L6470_0() && init_L6470_1() && init_L6470_2() && init_L6470_3());
}


/* ACTION 5 ------------------------------------------------------------------*
 * Implement here an initialization method for each expansion board's         *
 * component.                                                                 *
 *                                                                            *
 * Example:                                                                   *
 *   bool ExpansionBoard::init_COMPONENT_1(void)                              *
 *   {                                                                        *
 *     // Verifying identity.                                                 *
 *     uint8_t id = 0;                                                        *
 *     int ret = component_1->read_id(&id);                                   *
 *     if ((ret != COMPONENT_OK) || (id != I_AM_COMPONENT_1))                 *
 *     {                                                                      *
 *       delete component_1;                                                  *
 *       component_1 = NULL;                                                  *
 *       return true;                                                         *
 *     }                                                                      *
 *                                                                            *
 *     // Configuration.                                                      *
 *     COMPONENT_init_t init;                                                 *
 *     init.property_1 = COMPONENT_1_PROPERY_1_INIT;                          *
 *     init.property_N = COMPONENT_1_PROPERY_N_INIT;                          *
 *                                                                            *
 *     // Initialization.                                                     *
 *     if (component_1->init(&init) != COMPONENT_OK)                          *
 *       return false;                                                        *
 *                                                                            *
 *     return true;                                                           *
 *   }                                                                        *
 *----------------------------------------------------------------------------*/
/**
 * @brief  Initialize the L6470 component.
 * @retval true if initialization is successful, false otherwise.
 */
bool XNucleoIHM02A1::init_L6470_0(void)
{
    /* Initialization. */
    components[0]->ssel = ssl1;
    if (l6470_0->init((void *) init_components[0]) != COMPONENT_OK) {
        return false;
    }

    return true;
}

/**
 * @brief  Initialize the L6470 component.
 * @retval true if initialization is successful, false otherwise.
 */
bool XNucleoIHM02A1::init_L6470_1(void)
{
    /* Initialization. */
    
    components[1]->ssel = ssl1;
    if (l6470_1->init((void *) init_components[1]) != COMPONENT_OK) {
        return false;
    }

    return true;
}

bool XNucleoIHM02A1::init_L6470_2(void)
{
    /* Initialization. */
    components[1]->ssel = ssl2;
    if (l6470_0->init((void *) init_components[2]) != COMPONENT_OK) {
        return false;
    }

    return true;
}

bool XNucleoIHM02A1::init_L6470_3(void)
{
    /* Initialization. */
    components[1]->ssel = ssl2;
    if (l6470_1->init((void *) init_components[3]) != COMPONENT_OK) {
        return false;
    }

    return true;
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/ 
