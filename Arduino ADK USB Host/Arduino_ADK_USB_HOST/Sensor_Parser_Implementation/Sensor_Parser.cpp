/*
 * Sensor_Parser.c
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#include "Sensor_Parser.h"
#include "../JSON_API/json_arduino.h"

PARSER::PARSER(){
	packet_type = 0;
    packet = "<DEFAULT>";
    token_list = nullptr;
}
void* PARSER::allocate_packet_memory(void* packet){
	return malloc(sizeof(packet));
}

void PARSER::free_memory(void* memory){

	if(token_list->length != NULL)
		release_token_list(token_list);

	free(memory);
}

void PARSER::parse_packet(String packet){

	byte packet_type = packet.c_str()[1];
	char* token_list_str = packet.substring(3, (packet.length() - 2));

	create_token_list(MAX_TOKENS);

	// Convert JSON String to a Hashmap of Key/Value Pairs
	json_to_token_list(token_list_str, token_list);

	parse(token_list, packet_type);

}

union packet* PARSER::get_parsed_handle(){


}

bool PARSER::check_packet_integrity(String packet_str){

	byte length = packet_str.c_str()[2];
	byte header = packet_str.c_str()[0];
	byte tail = packet_str.c_str()[3];

	if(packet_str == NULL)
		if(length < 1)
			if(header != "+")
				if(tail != "*")
					return false;

	this->packet_str = packet_str;
	this->packet_type = packet_str.c_str()[1];

	return true;
}

void PARSER::parse(token_list_t* token_list, byte packet_type){

	assign_run_variables();

	switch(packet_type){

		case PACKET_INFO: // Always run.
		case ROUTER_STATUS:

			assign_router_status_variables();
			break;
		case ROUTER_NMAP:

			assign_nmap_variables();
		 	break;
		case ROUTER_ACK:

			assign_ack();
			break;
		case SENSOR_EN:

			//packet.router_sensor_enable_report
			break;
		case ERROR_MSG:

			assign_error_message();
			break;
		case SENSOR_CONFIG:

		case SENSOR_DATA:

		default:
			break;
	}
}

void PARSER::assign_run_variables(){

	packet.packet_structure_info.message_size = json_get_value(token_list, "SIZE");
	packet.packet_structure_info.packet_id = json_get_value(token_list, "ID");
	packet.packet_structure_info.run_time = json_get_value(token_list, "RUN");
	packet.packet_structure_info.sensor_id = json_get_value(token_list, "SID");
	packet.packet_structure_info.time_stamp = json_get_value(token_list, "TIME");

}

void PARSER::assign_router_status_variables(){

	packet.router_status_info.acks_sent_counter = json_get_value(token_list, "ACKS");
	packet.router_status_info.address = json_get_value(token_list, "ADD");
	packet.router_status_info.battey_level = json_get_value(token_list, "BATT");
	packet.router_status_info.debug_enable_flag = json_get_value(token_list, "DBG");
	packet.router_status_info.error_count = json_get_value(token_list, "ERR");
	packet.router_status_info.machine_state = json_get_value(token_list, "STATE");
	packet.router_status_info.mode = json_get_value(token_list, "MODE");
	packet.router_status_info.packet_counter = json_get_value(token_list, "PCOUNT");
	packet.router_status_info.power_state = json_get_value(token_list, "PWR");
	packet.router_status_info.router_address = json_get_value(token_list, "RADD");
	packet.router_status_info.rx_count = json_get_value(token_list, "RCOUNT");
	packet.router_status_info.sent_request_counter = json_get_value(token_list, "RESNT");
	packet.router_status_info.system_status = json_get_value(token_list, "STAT");
	packet.router_status_info.tx_count = json_get_value(token_list, "TX");

}

void PARSER::assign_nmap_variables(){

	// get the root node and the end node
	struct router_nmap_info_t nmap;

	router_nmap_info_t::data* root = nmap.data;
	router_nmap_info_t::data* end = nmap.data;

	root = packet.router_nmap_info.data;

	// loop to find the end node
	while(end != 0){
		end = end->next;
	}

	// loop through all the sensors
	packet.router_nmap_info.number_sensors = json_get_value(token_list, "NUM");
	for(register byte i = 0; i < atoi(packet.router_nmap_info.number_sensors); i++){

		// assign info
		end->battery_charge = json_get_value(token_list, "BATT");
		end->data_type = json_get_value(token_list, "DTYPE");
		end->rx_buffer_size = json_get_value(token_list, "RXBUF");
		end->sensor_address = json_get_value(token_list, "SADD");
		end->sensor_id = json_get_value(token_list, "SID");
		end->sensor_speed = json_get_value(token_list, "SSPD");
		end = end->next;
	}
}

void PARSER::assign_ack(){

	packet.router_ack_info.ack_message = json_get_value(token_list, "ACK");

}

void PARSER::assign_error_message(){

	packet.error_message.error_cause = json_get_value(token_list, "ERR");
	packet.error_message.sensor_address = json_get_value(token_list, "ADD");
	packet.error_message.sensor_id - json_get_value(token_list, "SID");

}
