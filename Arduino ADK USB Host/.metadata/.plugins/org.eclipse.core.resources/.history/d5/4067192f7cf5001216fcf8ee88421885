/*
 * Network_Protocol.h
 *
 *  Created on: Jul 24, 2013
 *      Author: fjpapin
 */


//! Internal State Machine.


// ENABLES THE COMS DEBUG MESSAGES OVER SERIAL2;
#define ROUTER_COMS_DEBUG

//! Message IDs.
#define ROUTER_ACK				0x01
#define ROUTER_HEARTBEAT		0x02
#define ROUTER_STATUS			0x03
#define ROUTER_NMAP				0x04
#define ROUTER_RADIO			0x05
#define SENSOR_ENABLE			0x06
#define SENSOR_CONFIGS			0x07
#define SENSOR_DATA				0x08

//! Command Descriptors
#define USB_DEVICE_CMD			0x29
#define USB_DEVICE_SET			0x30
#define USB_DEVICE_GET			0x31

//! Optional
#define ROUTER_DEBUG			0x07
#define ERROR_MSG				0x0A

//! Internal packet_id values
#define PACKET_ANY					0xFE
#define PACKET_NULL					0xFF

// *************************************************
// *************** REMOTE DOMAIN *******************
// *************************************************

//! Main packet header structure.
struct packet_header_t {

	byte message_size;
	byte packet_id;
	byte node_id;
	byte sensor_id;
	uint32_t time_stamp;
	uint32_t sensor_run_time;
	byte packet_version;
};

// *************************************************
//! Router acknowledge message structure
struct router_ack_info_t {

	bool ack;
};

// *************************************************
//! The heartbeat sent to the ground station
struct router_heartbeat_t {

	byte router_mode;
	byte battery_voltage;
	word command_index;
};

// *************************************************
//! System status information
struct router_status_info_t {

	// general status
	byte system_status;
	byte power_state;
	byte router_mode;

	byte error_count;
	byte debug_enable_flag;
	byte battery_voltage;

	// device info
	byte router_address;
	String router_id;
};

#ifdef ROUTER_COMS_DEBUG
// *************************************************
//! If we are debugging structure
struct router_debug_status_t {

	// wireless debug
	word router_acks_sent_counter;
	word router_sent_request_counter;
	word router_packet_counter;
	word router_rx_count;
	word router_tx_count;
};
#endif
// *************************************************
//! We need to make this for each sensor
struct router_nmap_data_t {

	byte sensor_id;
	byte sensor_address;
	router_nmap_data_t* next_node;
};

//! Network map linked list
struct router_nmap_info_t {

	//! Remote sensor information
	byte number_sensors;

	//! Implement a list for each sensor node;
	struct router_nmap_data_t sensor_node;
};

// *************************************************
struct router_sensor_enable_report_t {

	byte number_sensors;
	byte sensor_config_enable;
};

// *************************************************
struct error_message_t {

	byte sensor_id;
	byte sensor_address;
	byte error_code;
};

// *************************************************
//! Individual channel configuration.
//! Needs to cycle through each channel
struct channels_config {

	byte channel_id;
	byte data_type; //! 0 = Analog, 1 = Digital
	struct channels_config* next;
};

//! The Sensor config structure.
//! Needs to cycle through each sensor
struct sensor_config {

	byte sensor_id;
	byte packet_id;
	byte sensor_speed;
	byte sensor_data_type; //! 0 = int, 2 = float, 3 = double
	byte channels_config;
	struct channel_config* next_node;
};

//! This is the top level structure
struct remote_sensor_configuration_t {

	byte number_sensors;
	struct sensor_config sensor_node;
	struct remote_sensor_configuration_t* next_config;
};

// *************************************************
//! This is the structure containing each data point
//! from each channel.
struct channel_data {
	byte channel_id;
	word channel_data;
	struct channel_data* next;
};

//! The container for each sensor input.
struct remote_sensor_data_t {

	byte sensor_id;
	byte channels;
	struct channel_data sensor_input;
};

// *************************************************
//! This is the remote radio configs.
struct remote_radio_configs_t {
	word values[8];
};

// *************************************************
// ************* LOCAL DOMAIN **********************
// *************************************************

//! Sets an environment variable on the local system.
struct local_set_t {

	byte value_id_map;
	uint32_t value;
};

// *************************************************
//! This gets a value from the local system.
struct local_get_t{

	byte value_id_map;
	byte broadcast;
};

// *************************************************
//! This executes a command on the local system.
struct local_command_t{
	byte command_id;
	byte target_address;

};

// *************************************************
//! This union contains all possible messages from the router
//! device and their descriptions.
union packet_structure {

	struct packet_header_t 					header;
	struct router_ack_t						ack;
	struct router_heartbeat_t 				heartbeat;
	struct router_status_info_t 			status;
	struct router_debug_status_t 			debug;
	struct router_nmap_info_t 				nmap;
	struct router_sensor_enable_report_t 	en_sensors;
	struct remote_sensor_configuration_t 	configs;
	struct remote_sensor_data_t 			data;
	struct remote_radio_values_t			radio_configs;
	struct local_set_t						set;
	struct local_get_t						get;
	struct local_command_t					command;

	struct error_message_t	 				error;

};



