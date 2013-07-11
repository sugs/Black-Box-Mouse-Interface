/**
 * State_Machine_Implementation.h
 *
 *  Created on: Jul 10, 2013
 *      Author: francispapineau
 */

#ifndef STATE_MACHINE_IMPLEMENTATION_H_
#define STATE_MACHINE_IMPLEMENTATION_H_

#include "Main_Defines.h"

/**
 *
 */
 class EMULATION_DEVICE {

	private:

	 	/**
	 	 * This enumeration is the definition for the
	 	 * USB Emulation physical device. It is chosen
	 	 * by reading a button or switch on the Arduino
	 	 * Mega.
	 	 */
	 	enum STATE_MACHINE {

	 		/// Generic states
	 		PWR_ON_STATE 				= 0x00,
	 		INITIALIZATION_STATE 		= 0x01,
	 		SETUP_STATE 				= 0x02,
	 		USB_SETUP_STATE 			= 0x03,
	 		START_STATE 				= 0x04,
			ASSEMBLE_REPORT_STATE 		= 0x05,
			ASSEMBLE_USB_FRAME_STATE 	= 0x06,
			SEND_USB_FRAME_STATE		= 0x07,
	 		REBOOT_ERROR_STATE 			= 0x08,
	 		RUN_ERROR_STATE 			= 0x09,
	 		SYSTEM_HANG_STATE 			= 0x0A
	 	};

	public:
	
	 	/**
	 	 * This is the default constructor.
		 * Nothing is done here.
	 	 */
	 	EMULATION_DEVICE();

	 	/**
	 	 *
	 	 * @param state
	 	 */
		void set_state(byte state);

		/**
		 *
		 */
		void step_next_state();

		/**
		 *
		 */
		void go_back_one_state();

		/**
		 *
		 */
		void go_error_reboot();

		/**
		 *
		 */
		void go_error_hang();

		/**
		 *
		 * @return
		 */
		byte return_current_state();

		/**
		 *
		 * @return
		 */
		byte return_next_state();
 };

/**
 *
 */
 class USB_HOST_DEVICE {

 	 private:

	 	/**
	 	 * This enumeration is the definition for the
	 	 * USB HOST physical device. It is chosen
	 	 * by reading a button or switch on the Arduino
	 	 * Mega.
	 	 */
	 	enum STATE_MACHINE {

	 		/// Generic states
	 		PWR_ON_STATE 				= 0x00,
	 		INITIALIZATION_STATE 		= 0x01,
	 		SETUP_STATE 				= 0x02,
	 		USB_SETUP_STATE 			= 0x03,
	 		START_STATE 				= 0x04,
			RECEIVE_PACKET_NUMBER_STATE = 0x05,
			RECEIVE_PACKET_STATE 		= 0x06,
			PARSE_PACKET_STATE 			= 0x07,
			ASSEMBLE_USB_REPORT_STATE	= 0x08,
			SEND_USB_FRAME_STATE		= 0x09,
			REBOOT_ERROR_STATE 			= 0x0A,
			RUN_ERROR_STATE 			= 0x0B,
			SYSTEM_HANG_STATE 			= 0x0C

	 	};
		
	public:

	 	/**
	 	 *
	 	 */
	 	USB_HOST_DEVICE();

	 	/**
	 	 *
	 	 * @param state
	 	 */
	 	void set_state(byte state);

	 	/**
	 	 *
	 	 */
	 	void step_next_state();

	 	/**
	 	 *
	 	 */
	 	void go_back_one_state();

	 	/**
	 	 *
	 	 */
	 	void go_error_reboot();

	 	/**
	 	 *
	 	 */
	 	void go_error_hang();

	 	/**
		 *
	 	 * @return
	 	 */
	 	byte return_current_state();

	 	/**
	 	 *
	 	 * @return
	 	 */
	 	byte return_next_state();
 };

#endif /* STATE_MACHINE_IMPLEMENTATION_H_ */
