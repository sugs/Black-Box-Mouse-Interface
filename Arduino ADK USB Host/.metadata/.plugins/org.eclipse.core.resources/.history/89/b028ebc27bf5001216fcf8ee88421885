/*
 * Command_Interpreter.h
 *
 *  Created on: Jul 25, 2013
 *      Author: francispapineau
 */

#ifndef COMMAND_INTERPRETER_H_
#define COMMAND_INTERPRETER_H_

#include <avr/pgmspace.h>

PROGMEM const prog_char stringModesString[]{

		"WR", // wake router
		"RS", // request status
		"RM", // request net map
		"RC", // request channel map
		"ES", // request enable sensor
		"CS", // check sensor
		"SW", // send wakeup sensor
		"RN", // run poll
		"RE", // reboot specific sensor
		"RB", // reboot router
		"PO"  // power off network
};

class COMMAND_INTERPRETER {

	private:

		struct local_set_t						_set;
		struct local_get_t						_get;
		struct local_command_t					_command;

		void _set_value(byte packet_id, byte packet_ver, void *buf);
		void _get_value(byte packet_id, byte packet_ver, void *buf);
		void _send_cmd(byte packet_id, byte packet_ver, void *buf);

	public:

		void set(void *arg, byte packet_id, byte packet_ver, void *buf);
		void get(void *arg, byte packet_id, byte packet_ver, void *buf);
		void send_cmd(void *arg, byte packet_id, byte packet_ver, void *buf);

};


#endif /* COMMAND_INTERPRETER_H_ */
