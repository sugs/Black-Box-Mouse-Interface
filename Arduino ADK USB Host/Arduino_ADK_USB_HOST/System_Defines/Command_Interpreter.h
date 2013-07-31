/*
 * Command_Interpreter.h
 *
 *  Created on: Jul 25, 2013
 *      Author: francispapineau
 */

#ifndef COMMAND_INTERPRETER_H_
#define COMMAND_INTERPRETER_H_

#include "../System_Defines/Includes.h"

#define WAKEUP_ROUTER				0x01	// Wake up the router
#define WAKEUP_SENSOR				0x02	// Wake up a sensor
#define POWEROFF_ROUTER				0x03 	// Power off router
#define POWEROFF_SENSOR				0x04 	// Power off sensor
#define POWERON_ROUTER				0x05 	// Power on router
#define POWERON_SENSOR				0x06 	// Power on sensor
#define PAUSE_ROUTER				0x07 	// Pause router
#define PAUSE_SENSOR				0x08 	// Pause sensor
#define REQUEST_ROUTER_STATUS		0x09 	// Router status
#define REQUEST_NMAP				0x0A 	// Request NMAP
#define REQUEST_SENSOR_CHANNEL		0x0B	// Request sensor channel info
#define REQUEST_SENSOR_ENABLE		0x0C 	// Request sensor enable
#define REQUEST_SENSOR_CONFIG		0X0D	// Request sensor config
#define REQUEST_ROUTER_RUN			0x0F 	// Request router run
#define PING_ROUTER					0x10 	// Ping Router
#define PING_SENSOR					0x11 	// Ping sensor
#define REQUEST_ROUTER_CONFIG		0x12	// Get Router Config
#define REQUEST_NUMBER_SENSORS		0x13 	// Get the number of sensors
#define REQUEST_NUMBER_CHANNELS		0x14	// Gets the number of channels for one sensor

/**
 * This class handles commands sent from the sensor nodes to the
 * base station, and executes them.
 * We can also send commands through this class.
 */
class COMMAND_INTERPRETER {

	private:

		//! The command buffer to send.
		byte* command_buffer;

		//! Our command database loaded in cache.
		NVRAM* nvram_object;

		/**
		 * Constructs a command
		 *
		 * @param command - byte
		 */
		void _send_command(byte* command);

		/**
		 * Sends a command from the local board
		 *
		 * @param packet_id - byte
		 * @param packet_ver - byte
		 * @param buf - void*
		 */
		void _send_cmd(byte packet_id, void *buf);

		/**
		 * Loads bytes from NVRAM
		 *
		 * @param address - byte
		 * @param size - byte
		 * @param value - void*
		 */
		void _loadx(byte address, byte size, void* value);

		/**
		 * Sends and checks for a response.
		 *
		 * @param packet_id - byte
		 * @param command - byte*
		 */
		void _send_check(byte receive_packet_id, byte* command);

	public:

		/**
		 * Default constructor.
		 *
		 * @param nvram_object
		 */
		COMMAND_INTERPRETER(NVRAM* nvram_object);

		/**
		 * Sends a command via the public domain.
		 *
		 * @param buf - void*
		 */
		void send_cmd(byte packet_id, void *buf);


		/**
		 * Load all of the saved variables.
		 */
		void load(void);
};


#endif /* COMMAND_INTERPRETER_H_ */
