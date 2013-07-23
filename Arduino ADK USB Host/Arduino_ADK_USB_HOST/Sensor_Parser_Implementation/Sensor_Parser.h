/*
 * Sensor_Parser.h
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#ifndef SENSOR_PARSER_H_
#define SENSOR_PARSER_H_

#include "../System_Defines/Main_Defines.h"

#define PACKET_INFO 	0
#define ROUTER_STATUS 	1
#define ROUTER_NMAP		2
#define ROUTER_ACK		3
#define SENSOR_EN		4
#define ERROR_MSG		5
#define SENSOR_CONFIG	6
#define SENSOR_DATA		7

#define MAX_TOKENS		40

struct packet_structure_info_t {

	char* message_size;
	char* packet_id;
	char* sensor_id;
	char* time_stamp;
	char* run_time;

};

struct router_status_info_t {

	// general status
	char* system_status;
	char* error_count;
	char* debug_enable_flag;
	String power_state;
	String machine_state;
	char* battey_level;

	// wireless debug
	char* acks_sent_counter;
	char* sent_request_counter;
	char* packet_counter;
	char* rx_count;
	char* tx_count;

	// device info
	char* address;
	String mode;
	char* router_address;
	String router_id;
};

// Network map linked list
struct router_nmap_info_t {

	// remote sensor information
	word size; //size of the linked list
	char* number_sensors;

	// we need to make this for each sensor
	struct data {
		char* sensor_id;
		char* sensor_address;
		char* sensor_speed;
		char* data_type; // 0 = int, 2 = float, 3 = double
		char* rx_buffer_size;
		char* battery_charge;
		struct data* next;
	};
};

struct router_ack_info_t {
	bool ack_message;
};

struct router_sensor_enable_report_t {

	word size;
	char* number_sensors;
	byte* sensor_config_enable;

};

struct error_message_t {

	char* sensor_id;
	char* sensor_address;
	String error_cause;
};

struct remote_sensor_configuration_t {

	word size;
	char* number_sensors;
	struct data {
		char* sensor_id;
		char* packet_id;
		String mode;
		char* channels;
		struct channels_config {
			char* channel_id;
			char* data_type; // 0 = Analog, 1 = Digital
			struct channels_config* next;
		};
	};
	struct remote_sensor_configuration_t* next_config;
};

struct remote_sensor_data_t {

	char* sensor_id;
	char* packet_id;
	String mode;
	char* channels;
	struct channel_data {
		char* channel_id;
		char* channel_data;
		struct channel_data* next;
	};
};

union packet_structure {

	struct packet_structure_info_t packet_structure_info;
	struct router_status_info_t router_status_info;
	struct router_nmap_info_t router_nmap_info;
	struct router_ack_info_t router_ack_info;
	struct router_sensor_enable_report_t router_sensor_enable_report;
	struct error_message_t error_message;
	struct remote_sensor_configuration_t remote_sensor_configuration;
	struct remote_sensor_data_t remote_sensor_data;

}packet;

/**
 * [HEADER][ID][MESSAGE_LENGTH][JSON_STRING][TAIL]
 * [+][##][##][{SRINGS}][*]
 */

class PARSER {

	private:

		token_list_t *token_list = NULL;
		byte packet_type;
		String packet_str;

		void parse(token_list_t* token_list, byte packet_type);
		void assign_run_variables();
		void assign_router_status_variables();
		void assign_nmap_variables();
		void assign_ack();
		void assign_error_message();
		void assign_sensor_en();
		void assign_sensor_config();
		void assign_sensor_data();

	public :
		PARSER();

		bool check_packet_integrity(String packet);
		void parse_packet(String packet);
};

#endif /* SENSOR_PARSER_H_ */
