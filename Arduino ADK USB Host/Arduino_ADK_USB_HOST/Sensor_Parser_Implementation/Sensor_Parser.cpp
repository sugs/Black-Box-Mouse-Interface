/*
 * Sensor_Parser.c
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#include "Sensor_Parser.h"
#include "../JSON_API/json_arduino.h"

PARSER::PARSER(){

}

void PARSER::parse_packet(String packet){

}

bool PARSER::check_packet_integrity(String packet_str){


}

void PARSER::parse(token_list_t* token_list, byte packet_type){

	assign_run_variables();

	switch(packet_type){

		case PACKET_INFO: // Always run.
		case ROUTER_STATUS:

		case ROUTER_NMAP:

		case ROUTER_ACK:

		case SENSOR_EN:

		case ERROR_MSG:

		case SENSOR_CONFIG:

		case SENSOR_DATA:

		default:
			break;
	}
}
