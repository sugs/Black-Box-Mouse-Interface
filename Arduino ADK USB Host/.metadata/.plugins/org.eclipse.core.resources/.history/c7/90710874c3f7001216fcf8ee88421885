/*
 * Command_Interpreter.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: francispapineau
 */

#include "Command_Interpreter.h"

//! Sets up our non volatile nvram object, our command db.
COMMAND_INTERPRETER::COMMAND_INTERPRETER(NVRAM* nvram_object){
	this->command_buffer = nullptr;
	this->nvram_object = nvram_object;
}

/**
 * buf. definition: [Target Address][Command Predicate][Arg 1][Arg 2]
 */
//! Sends a command
void COMMAND_INTERPRETER::_send_cmd(byte packet_id, void *buf){

	String* buffer = (String*) buf;

	if(packet_id == USB_DEVICE_CMD){

		//! Construct a command
		_send_command((byte*)buf[0]);
	}
}

//! Execute a command from a sensor or router
void COMMAND_INTERPRETER::_send_command(byte* command){

	byte* command_send;
	void* packet_pointer;

	switch(command[0]){

	 // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case WAKEUP_ROUTER: 	// Wake up the router
			_send_check(ROUTER_ACK, (byte*)this->nvram_object->nv._wakeup_router);
			break;

		case WAKEUP_SENSOR: 	// Wake up a sensor
			command_send = (byte*)this->nvram_object->nv._wakeup_sensor;
			command_send[5] = command[1];
			_send_check(ROUTER_ACK, command_send);
			break;

 // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case POWEROFF_ROUTER: 	// Power off router
			_send_check(ROUTER_HEARTBEAT, (byte*)this->nvram_object->nv._poweroff_router);
			break;

		case POWEROFF_SENSOR: 	// Power off sensor
			command_send = (byte*)this->nvram_object->nv._poweroff_sensor;
			command_send[5] = command[1];
			_send_check(ROUTER_HEARTBEAT, command_send);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case POWERON_ROUTER: 	// Power on router
			_send_check(ROUTER_HEARTBEAT, (byte*)this->nvram_object->nv._power_on_router);
			break;

		case POWERON_SENSOR: 	// Power on sensor
			command_send = (byte*)this->nvram_object->nv._power_on_sensor;
			command_send[5] = command[1];
			_send_check(ROUTER_HEARTBEAT, command_send);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case PAUSE_ROUTER: 	// Pause router
			_send_check(ROUTER_ACK, (byte*)this->nvram_object->nv._pause_router);
			break;

		case PAUSE_SENSOR: 	// Pause sensor
			command_send = (byte*)this->nvram_object->nv._pause_sensor;
			command_send[6] = command[1];
			_send_check(ROUTER_ACK, command_send);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case ROUTER_STATUS: 	// Router status
			_send_check(ROUTER_STATUS, (byte*)this->nvram_object->nv._request_router_status);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case REQUEST_NMAP: 	// Request NMAP
			_send_check(ROUTER_NMAP, (byte*)this->nvram_object->nv._request_nmap);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case REQUEST_SENSOR_ENABLE: 	// Request sensor enable
			_send_check(SENSOR_ENABLE, (byte*)this->nvram_object->nv._request_sensor_enable);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case REQUEST_SENSOR_CHANNEL:	// Request sensor channel info
		case REQUEST_SENSOR_CONFIG:	// Request sensor config
			_send_check(SENSOR_CONFIGS, (byte*)this->nvram_object->nv._request_sensor_config);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case REQUEST_ROUTER_RUN: 	// Request router run
			_send_check(ROUTER_ACK, (byte*)this->nvram_object->nv._request_router_run);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case PING_ROUTER: 	// Ping Router
			_send_check(ROUTER_ACK, (byte*)this->nvram_object->nv._ping_router);
			return;

		case PING_SENSOR: 	// Ping sensor
			command_send = (byte*)this->nvram_object->nv._ping_sensor;
			command_send[6] = command[1];
			_send_check(ROUTER_ACK, command_send);
			return;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		case REQUEST_ROUTER_CONFIG:
			_send_check(ROUTER_CONFIG, (byte*)this->nvram_object->nv._request_router_config);
			break;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		default:	// Other commands don't exist
			command_send = nullptr;
			break;
	}
}

//! The public send command method
void COMMAND_INTERPRETER::send_cmd(byte packet_id, void *buf){

	//! Process String
	_send_cmd(packet_id, buf);
}

//! Sends and checks a received message.
void COMMAND_INTERPRETER::_send_check(byte receive_packet_id, byte* command){

	RF_SERIAL.print((char*) command);

	while(true){
		packet_decoder.poll();
		if(packet_decoder._packet_id == receive_packet_id)
			return;
		else if ((millis() - packet_decoder._last_received) > PACKET_TIMEOUT)
			error();
	}
}
