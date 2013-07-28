/*
 * Parser_State_Machine.h
 *
 *  Created on: Jul 24, 2013
 *      Author: fjpapin
 */

#ifndef USB_STATE_MACHINE_H_
#define USB_STATE_MACHINE_H_

//! USB State machine
#define LOCAL_RESET							-1
#define NETWORK_RESET						-2
#define LOCAL_DEVICE_SETUP					0
#define NETWORK_SETUP						1
	#define NETWORK_ID_REQUEST				2
	#define NETWORK_STATUS_REQUEST			3
	#define NETWORK_MAP_REQUEST				4
	#define NETWORK_SENSOR_CONFIGS			5
#define LOCAL_CONFIGURATION					6
#define NETWORK_REQUEST_ROUTER_STATE_RUN	7
#define LOCAL_PACKET_WAIT					8
#define LOCAL_PACKET_RECEIVED				9
#define LOCAL_PARSE_PACKET					10
#define LOCAL_USB_REPORT_ASSEMBLE			11
#define LOCAL_USB_REPORT_SEND				12

#define LOCAL_ERROR_MODE(state)				(20 + state)
#define NETWORK_ERROR_MODE(state)			(40 + state)

#define LOCAL_COMMAND_MODE					70


/**
 * This class handles the operations with the USB
 * state machine.
 */
class USB_STATE_MACHINE {

	private:

		static byte current_state;
		static byte next_state;

		/**
		 * Defines the reset state function
		 */
		void(*reset_device);

	public:

		/**
		 * Default constructor.
		 */
		USB_STATE_MACHINE();

		/**
		 * Move state forwards by 1
		 */
		void move_state_forward();

		/**
		 * Move state backwards by 1
		 */
		void move_state_backwards();

		/**
		 * Move state to the local error hang
		 * state.
		 */
		void move_state_to_local_error(byte previous_state);

		/**
		 * Move state to the network error
		 * hang state.
		 */
		void move_state_to_network_error(byte previous_state);

		/**
		 * Move the state to reset... calls reset_device.
		 */
		void move_state_to_local_reset();

		/**
		 * Move the state to the network reset states, and
		 * polls until ack.
		 */
		void move_state_to_network_reset();

		/**
		 * Gets the state current state.
		 */
		byte get_current_state();
};
