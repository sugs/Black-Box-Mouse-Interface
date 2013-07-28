/*
 * USB_Device_Implementation.h
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#ifndef USB_DEVICE_IMPLEMENTATION_H_
#define USB_DEVICE_IMPLEMENTATION_H_

#include <Arduino.h>

	/*		// flow:
			// GND_STATION (request) -----------------------> ROUTER (Acknowledge)
			//                       <-----------------------
			// Poll for results		 <----------------------- Results are sent (with id)
			// Send stanby command   -----------------------> Standby (Poll for run)
		/->	// Send run command 	 -----------------------> Run
		|-	// Receive data structs  <-----------------------
	*/

class USB_DEVICE {

	private:

		void create_network_mem_map();

		void send_id_request(byte sensor_address);
		void poll_for_results();
		void send_standby_command(byte sensor_address);
		void send_run_command(byte sensor_address);

		byte get_number_of_packets();
		byte receive_packet();

		String get_sensor_map();
		String get_sensor_info();
		router_nmap_info_t* get_network_topology();

	public:

		void run();
};


#endif /* USB_DEVICE_IMPLEMENTATION_H_ */
