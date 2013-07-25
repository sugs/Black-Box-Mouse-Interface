/*
 * Sensor_Parser.h
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#ifndef SENSOR_PARSER_H_
#define SENSOR_PARSER_H_

#include "Network_Protocol.h"
#include "../System_Defines/Main_Defines.h"

#define MAX_TOKENS		40

struct packet_handler packet_handlers[] = {

		//{/*PACKET ID*/, /*TARGET FUNCTION*/, /*OBJECT ADDRESS*/},

};

/**
 * [HEADER][ID][MESSAGE_LENGTH][JSON_STRING][TAIL]
 * [+][##][##][{SRINGS}][*]
 */

class PARSER {

	private:

		void parse(token_list_t* token_list, byte packet_type);
		void check_memory_space();

	public :
		PARSER();

		bool check_packet_integrity(String packet);
		void parse_packet(String packet);
};

#endif /* SENSOR_PARSER_H_ */
