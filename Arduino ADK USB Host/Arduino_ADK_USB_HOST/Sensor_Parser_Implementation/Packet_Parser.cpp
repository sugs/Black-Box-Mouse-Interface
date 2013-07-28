/*
 * Sensor_PACKET_PARSER.c
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#include "Packet_Parser.h"

//! Parse the structures.
static void PACKET_PARSER::parse(void *arg, byte packet_id, byte packet_ver, void *buf){

	//! Check if there is space left
	_check_memory_space();

	//! Check if the string is ok to process.
	_check_packet_integrity((String*) buf);

	//! Process String
	((PACKET_PARSER*)arg)->_parse(packet_id, packet_ver, buf);
}

//! Check the memory space
void PACKET_PARSER::_check_memory_space(){

    //! Check memory integrity
    if(memory_check() <= EMPTY)
    	reset_device();
}

//! Check packet integrity
bool PACKET_PARSER::_check_packet_integrity(String* packet){

	//! Checks length, Header, Tail
	if(packet->len > EMPTY)
		if(packet[2] > EMPTY)
			if(packet[0] == '+')
				if(packet[packet->len - 1] == '*')
					return true;

	return false;
}

//! Parse the packet
void PACKET_PARSER::_parse(byte packet_id, byte packet_ver, void *buf){

	String* buffer = (String*) buf;
	void* destination_pointer;
	size_t size_of_destination_struct;

	//! Grabs the header structure from the String.
	String header = buffer->substring(1, 13);

	//! Assigns the new construct
	memcpy(&packet_header_t, buffer, sizeof(packet_header_t));

	switch (packet_id) {

		case ROUTER_ACK:
			destination_pointer = &_ack;
			size_of_destination_struct = sizeof(_ack);
			break;

		case ROUTER_HEARTBEAT:
			destination_pointer = &_heartbeat;
			size_of_destination_struct = sizeof(_heartbeat);
			break;

		case ROUTER_STATUS:
			destination_pointer = &_status;
			size_of_destination_struct = sizeof(_status);
			break;

			// TODO
		case ROUTER_NMAP:
			destination_pointer = &_nmap;
			size_of_destination_struct = sizeof(_nmap);
			break;

		case ROUTER_CONFIG:
			destination_pointer = &_radio_configs;
			size_of_destination_struct = sizeof(_radio_configs);
			break;

		case SENSOR_ENABLE:
			destination_pointer = &_en_sensors;
			size_of_destination_struct = sizeof(_en_sensors);
			break;

			// TODO
		case SENSOR_CONFIGS:
			destination_pointer = &_configs;
			size_of_destination_struct = sizeof(_configs);
	        break;

	        // TODO
		case SENSOR_DATA:
			destination_pointer = &_data;
			size_of_destination_struct = sizeof(_data);
	        break;

		case ROUTER_DEBUG:
			destination_pointer = &_debug;
			size_of_destination_struct = sizeof(_debug);
	        break;

		case ERROR_MSG:
			destination_pointer = &_error;
			size_of_destination_struct = sizeof(_error);
	        break;

		case USB_DEVICE_CMD:
			destination_pointer = &_command;
			size_of_destination_struct = sizeof(_command);
			memcpy(destination_pointer, buf, size_of_destination_struct);
			command_interpreter.send_cmd(_command.command_id, (void*)_command.target_address);

	    default:
	    	destination_pointer = NULL;
	}
	if (NULL != destination_pointer)
		memcpy(destination_pointer, buf, size_of_destination_struct);
}
