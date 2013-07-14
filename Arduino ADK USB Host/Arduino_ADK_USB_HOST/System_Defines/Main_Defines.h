/*
 * Main_Defines.h
 *
 *  Created on: Jul 10, 2013
 *      Author: francispapineau
 */

#ifndef MAIN_DEFINES_H_
#define MAIN_DEFINES_H_

#include <Arduino.h>
#include "usbconfig.h"
#include "USB_HID_API/usbdrv.h"

/**
 * This file contains all of the device DEFINE macros, and
 * also includes all of the libraries that are needed to
 * be references. All of the structures and classes are also
 * built by default in this header file.
 **/

 //#define DEVELOPMENT						//! In Windows Development Mode
 #define DEBUG								//! Serial Debug Define
 #define USER_INPUT							//! User Button Define
 #define DEBUG_LED							//! Debug LEDs Define

 //! ONLY ONE OF THE FOLLOWING SHOULD BE CHOSEN!
 #define MOUSE_REPORT						//! Only send the Mouse USB report
 //#define JOYSTICK_REPORT					//! Only send the joystick USB report
 //#define MOUSE_JOYSTICK_REPORT			//! Send both joystick and mouse USb reports

#define FIVE_SECONDS		5000

 //! Normal Output Stream
 #define PRINT				Serial2.print	//! Serial API
 #define PRINTLN			Serial2.println //! Serial API

//! Debug Output Stream
 #ifdef DEBUG
	#define DEBUG_PRINT 	Serial2.print 	//! Serial API
	#define DEBUG_PRINTLN 	Serial2.println //! Serial API
 #endif

 //! User Button Activation
 //! TODO - ADD THE PORT MAP

 #ifdef USER_INPUT
	#define SELECT_BUTTON_1	2				//! PORT MAPS
	#define SELECT_BUTTON_2 3
 #endif

 //! Debug LEDs Activation
 //! TODO - ADD THE PORT MAP

 #ifdef DEBUG_LED
	#define DBG_LED_1		??				//! PORT MAPS
	#define DBG_LED_2		??
	#define DBG_LED_3		??
	#define DBG_LED_4		??
 #endif

//! If we are developing and the env is not set properly
#ifdef DEVELOPMENT
	typedef unsigned char byte;					//! Redefine the 8 bit values
	typedef unsigned char prog_byte;
	typedef char int8_t;
	typedef int  int16_t;
#endif

	//! A generic pointer to the chosen object.
	void* generic_pointer;

	//! Define which device was chosen.
	byte emulation_chosen;
	byte usb_device_chosen;

#endif /* MAIN_DEFINES_H_ */
