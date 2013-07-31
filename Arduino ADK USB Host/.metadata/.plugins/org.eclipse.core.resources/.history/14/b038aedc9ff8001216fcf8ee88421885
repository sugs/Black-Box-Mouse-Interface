/*
 * Hardware_Defines.h
 *
 *  Created on: Jul 26, 2013
 *      Author: fjpapin
 */

#ifndef HARDWARE_DEFINES_H_
#define HARDWARE_DEFINES_H_

 //#define DEVELOPMENT						//! In Windows Development Mode
 #define DEBUG								//! Serial Debug Define
 #define USER_INPUT							//! User Button Define
 #define DEBUG_LEDs							//! Debug LEDs Define

#define NUMBER_OF_LEDS		4

//! Serial device map
//!	- Serial 1 - USB Endpoint - PC COMS
//! - Serial 2 - USB Host 	  - RF COMS
//! - Serial 3 - Debug		  - FTDI COMS

 //! Normal Output Stream
#define SERIAL				Serial1
#define PRINT				Serial1.print	//! Serial API
#define PRINTLN				Serial1.println //! Serial API

//! RF output stream
#define RF_SERIAL			Serial2
#define RF_PRINT			Serial2.print
#define RF_PRINTLN			Serial2.println

//! Debug Output Stream
 #ifdef DEBUG
	#define DEBUG_SERIAL	Serial3
	#define DEBUG_PRINT 	Serial3.print 	//! Serial API
	#define DEBUG_PRINTLN 	Serial3.println //! Serial API

	debug_code_struct_t debug_api;
	error_type_counts_t error_type_counts;
 #endif

 //! User Button Activation
 //! TODO - ADD THE PORT MAP

 #ifdef USER_INPUT
	#define SELECT_BUTTON_1	2				//! PORT MAPS
	#define SELECT_BUTTON_2 3
 #endif

 //! Debug LEDs Activation
 //! TODO - ADD THE PORT MAP

 #ifdef DEBUG_LEDs
	#define DBG_LED_1		3				//! PORT MAPS
	#define DBG_LED_2		4
	#define DBG_LED_3		5
	#define DBG_LED_4		6
 #endif

#endif /* HARDWARE_DEFINES_H_ */
