/*
 * Sensor_Parser.h
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#ifndef SENSOR_PARSER_H_
#define SENSOR_PARSER_H_

#include "System_Defines/Main_Defines.h"

#define MAX_TOKENS		40

/**
 * Packet Structure Definition.
 * [HEADER][ID][MESSAGE_LENGTH][JSON_STRING][TAIL]
 * [+][##][##][{SRINGS}][*]
 */

/**
 * This class takes care of the packet parsing.
 */
class PACKET_PARSER {

	private:

		//! The structures needed to parse info into.
		struct packet_header_t					_header;
		struct router_ack_info_t				_ack;
		struct router_heartbeat_t 				_heartbeat;
		struct router_status_info_t 			_status;
		struct router_debug_status_t 			_debug;
		struct router_sensor_enable_report_t 	_en_sensors;
		struct remote_radio_values_t			_radio_configs;
		struct error_message_t					_error;
		struct local_command_t					_command;
		struct number_of_sensors_t				_num_sensors;
		struct number_of_channels_t				_num_channels;

		/**
		 * These will get reallocated to how many sensors there are in
		 * the sensor network.
		 */
		sensor_configs_t			 			_configs[1];
		router_nmap_info_t						_nmap	[1];
		remote_sensor_data_t 					_data	[1];

		/**
		 * Gets if a packet was read, and what type.
		 */
		static bool _check_read_packet(byte packet_type);

		/**
		 * Gets the sensor data.
		 * @param buf - void*
		 */
		static void _get_sensor_data(void* buf);

		/**
		 * Gets the sensor configs based on the buf passed.
		 * @param buf - void*
		 */
		static void _get_sensor_configs(void* buf);

		/**
		 * Gets the nmap from the passed buffer.
		 * @param buf - void*
		 */
		static void _get_nmap(void* buf);

		/**
		 * Checks the packet header as any packet comes in.
		 */
		static void _check_packet_header();

		/**
		 * Checks the ack signal and returns if true.
		 * If false, the router reloads as there might be an error.
		 */
		static void _check_ack();

		/**
		 * Checks the heartbeat signals and sees if any error should be
		 * fired off.
		 */
		static void _check_heartbeat();

		/**
		 * Checks the router status and sees if any errors should
		 * be fired off.
		 */
		static void _check_router_status();

		/**
		 * Checks the memory space to see if we can allocate
		 * more structures.
		 */
		static void _check_memory_space(size_t mem_space = MAX_MEMORY);

		/**
		 * Checks the packet integrity
		 *
		 * @param packet - String*
		 * @return bool
		 */
		static bool _check_packet_integrity(String* packet);

		/**
		 * Allocates the memory... saves mem
		 * @param dest_pointer - void*
		 * @param size - size_t
		 * @param buf - void *
		 */
		static void _alloc_mem(void* dest_pointer, size_t size, void* buff);

		/**
		 * Parses a packet
		 *
		 * @param packet_id - byte
		 * @param packet_ver - byte
		 * @param buf - void*
		 */
		static void _parse(byte packet_id, byte packet_ver, void *buf);

	public :

		/**
		 * Default constructor
		 */
		PACKET_PARSER();

		/**
		 * Publicly accessible parsing method.
		 *
		 * @param arg - void*
		 * @param packet_id - byte
		 * @param packet_ver - byte
		 * @param buf - void*
		 */
		static void	parse(void *arg, byte packet_id, byte packet_ver, void *buf);

};

#endif /* SENSOR_PARSER_H_ */
