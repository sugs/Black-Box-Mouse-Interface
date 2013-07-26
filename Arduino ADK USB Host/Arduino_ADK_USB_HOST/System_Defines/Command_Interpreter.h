/*
 * Command_Interpreter.h
 *
 *  Created on: Jul 25, 2013
 *      Author: francispapineau
 */

#ifndef COMMAND_INTERPRETER_H_
#define COMMAND_INTERPRETER_H_

#include <avr/pgmspace.h>
#include "../System_Defines/Main_Defines.h"

#define WAKEUP_ROUTER				0x01	// Wake up the router
#define WAKEUP_SENSOR				0x02	// Wake up a sensor
#define POWEROFF_ROUTER				0x03 	// Power off router
#define POWEROFF_SENSOR				0x04 	// Power off sensor
#define POWERON_ROUTER				0x05 	// Power on router
#define POWERON_SENSOR				0x06 	// Power on sensor
#define PAUSE_ROUTER				0x07 	// Pause router
#define PAUSE_SENSOR				0x08 	// Pause sensor
#define ROUTER_STATUS				0x09 	// Router status
#define REQUEST_NMAP				0x0A 	// Request NMAP
#define REQUEST_SENSOR_CHANNEL		0x0B	// Request sensor channel info
#define REQUEST_SENSOR_ENABLE		0x0C 	// Request sensor enable
#define REQUEST_SENSOR_CONFIG		0X0D	// Request sensor config
#define REQUEST_SENSOR_STATE		0x0E 	// Request sensor state
#define REQUEST_ROUTER_RUN			0x0F 	// Request router run
#define PING_ROUTER					0x10 	// Ping Router
#define PING_SENSOR					0x11 	// Ping sensor

/**
 * This class handles commands sent from the sensor nodes to the
 * base station, and executes them.
 * We can also send commands through this class.
 */
class COMMAND_INTERPRETER {

	private:

		//! The command buffer to send.
		byte* command_buffer;

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

		byte* _ping_router();

		byte* _ping_sensor(byte sensor_address);

		byte* _request_router_run();

		byte* _request_sensor_state(byte* command);

		byte* _request_sensor_config();

		byte* _request_sensor_enable();

		byte* _request_sensor_channel(byte* command);

		byte* _request_nmap();

		byte* _request_router_status();

		byte* _pause_sensor(byte* command);

		byte* _pause_router();

		byte* _power_on_router();

		byte* _power_on_sensor(byte* command);

		byte* _poweroff_router();

		byte* _poweroff_sensor(byte* command);

		byte* _wakeup_router();

		byte* _wakeup_sensor(byte* command);

	public:

		/**
		 * Sends a command via the public domain.
		 *
		 * @param buf - void*
		 */
		void send_cmd(byte packet_id, void *buf);
};


#endif /* COMMAND_INTERPRETER_H_ */
