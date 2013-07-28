/*
 * NVRAM_API.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: fjpapin
 */

#include "Main_Defines.h"

//! Define the structure
struct NVRAM::nv_data_t NVRAM_default PROGMEM = {

        9600,   // serial1 speed
        9600,	// serial2 speed
        9600,   // serial3 speed
        0x0A,	// node address
        0x01,   // device mode, setup.
        SELECT_BUTTON_1,
        INPUT,
        SELECT_BUTTON_2,
        INPUT,
        DBG_LED_1,
        OUTPUT,
        DBG_LED_2,
        OUTPUT,
        DBG_LED_3,
        OUTPUT,
        DBG_LED_4,
        OUTPUT
};

//! Load the saved args.
void NVRAM::load(void){
        // check for signature
        if (('m' != EEPROM.read(0)) ||
            ('s' != EEPROM.read(1))) {
                // load defaults
                memcpy_P(&nv, &NVRAM_default, sizeof(nv));
        } else {
                // load from NVRAM
                _loadx(2, sizeof(nv), &nv);
        }
}

//! Save the args
void NVRAM::save(void){
        // save to NVRAM
        _savex(2, sizeof(nv), &nv);

        EEPROM.write(0, 'm');
        EEPROM.write(1, 's');
}

//! Load bytes
void NVRAM::_loadx(uint8_t address, uint8_t size, void *value){
        uint8_t         *rp;

        rp = (uint8_t *)value;
        while (size--)
                *rp++ = EEPROM.read(address++);
}

//! Save bytes
void NVRAM::_savex(uint8_t address, uint8_t size, void *value){
        uint8_t         *rp;

        rp = (uint8_t *)value;
        while (size--)
                EEPROM.write(address++, *rp++);
}



