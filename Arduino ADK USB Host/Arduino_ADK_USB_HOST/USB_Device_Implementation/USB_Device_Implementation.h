/*
 * USB_Device_Implementation.h
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#ifndef USB_DEVICE_IMPLEMENTATION_H_
#define USB_DEVICE_IMPLEMENTATION_H_

#include "../System_Defines/Main_Defines.h"

/**
 	// GENERAL INFO ABOUT USB DEVICE FUNCTIONS
    // This is the procedures to gain access to the
    // sensor values on the remote sensors.
    // This document is meant to be a guideline for
    // the future application layer protocol developemnt.

    // This state is accessed when the Arduino ADK
    // (Ground station) needs to map out the network at hand.
    // This state requests a status report from the router, and the
    // router sends a report of all sensors available and their ids and
    // data types (includes number of bytes to allocate for the rx buffer).

    // NOTE: The IF(REMEMBER) condition is implemented using the DB.h
    // library found on Arduino.com. It uses the EEPROM to store information\
    // about the configuration.

    #if(ID_REQUEST)


         * This function sends_a wakeup call to the router and makes the
         * router go into command polling mode. This allows the router to
         * only react to the commands sent by the ground station and not the
         * sensors.
         *
         * -> This function needs an ack before a watchdog timer expires
         *    to continue with the setup process.

*******  1. send_wakeup_router();
                -> receive_router_ack();
                -> ping_router


         * This function requests a router status structure. It sends a
         * request command and polls until a structure is returned or when a
         * watchdog timer exhaust is caught.
         *
         * -> This function needs an ack before a watchdog timer expires
         *    to continue with the setup process.

*******  2. request_router_status();
                -> receive_router_status();


         * This function is very crucial to the network implementation, as
         * it maps out the receiver and sender nodes. This function sends a
         * generic "nmap" command, which activates a network_read() command on
         * the router. Then in turn, the router returns a network structure,
         * which contains enddevice information and other crucial network info.
         *
         * -> This function needs a message before a watchdog timer expires
         *    to continue with the setup process.

*******  3. request_net_map();
                -> receive_nmap();


                 * This part of the code stores the received network info in
                 * non-volatile EEPROM for future storage.\

                IF(REMEMBER)
                    -> store_into_sensor_db(nmap_t* nmap);
                ENDIF


         * Now that the network topology is mapped out, the follwoing command
         * is issued to all endpoint devices (sensors) to acquire their
         * respective specifics, such as channel IDs, speed and data types.
         *
         * -> This function needs a message before a watchdog timer expires
         *    to continue with the setup process.

*******  4. request_sensor_channel_info();
                -> receive_channel_info();


                 * This part of the code stores the received network info in
                 * non-volatile EEPROM for future storage.\

                IF(REMEMBER)
                    -> store_into_sensor_db(channel_info_t* channel_info);
                ENDIF


         * This function polls for an enabled sensor report generated by the
         * user on the router, by slecting which sensor is enabled.

*******  5. get_user_enable_sensors();
                -> set_flags(byte sensor flags);


         * Then to finalize the ground station network initialization,
         * we need to allocate buffers for each sensor and then create a
         * call priority table, which in other words is a call scheduler.
         * This finalizes the network setup on the ground station side.
         *
         * -> This function needs a message before a watchdog timer expires
         *    to continue with the setup process.

*******  6. configure_ground_station();
                -> allocate_buffers(nampe_t* nmap, channel_info_t* channel_info);
                -> create_call_priority_table();
    #ENDIF


    // This state is reached when we have successfully finished the init stage
    // and we are requesting data from the router.

    #IF(RUN_REQUEST)


         * This function checks the sensor states based off the argument passed.
         * This function reveives 1 byte from the router that contains the
         * bianry equivalent of the states of the sensors
         *  -> HIGH = ON
         *  -> LOW  = OFF
         *
         * -> This function needs a message before a watchdog timer expires
         *    to continue with the setup process.

*******  7. check_sensors_state(byte* sensor_flags);
            -> byte receive_sensor_states();

        // This part is the working loop for the transaction based protocol.
        // It is an INFINITE loop that is only disturbed by the USER I/O on the
        // chronos or an ERROR.
>>>>>>> for INFINITY || Interrupt occurs (I/O or ERROR)

            // For each sensor, we must do teh following tasks.
>>>>>>>     for # of sensors


                 * This function sends a wakeup message to the router, which
                 * in its turn sends a wakeup signal to the remote node
                 * specified in the agument passed.
                 *
                 * -> This function needs a message before a watchdog timer expires
                 *    to continue with the setup process.

*******          8. send_sensors_wakeup(byte* sensor_flags);
                    -> receive_router_ack();

                 * This function sends a sensor data request query to the router,
                 * which then gets a sensor responce structure back. The sequence
                 * in which this process is done is with the call_priority_table
                 * defined above. We go through the table and call each sensor
                 * to get each peice of information.
                 *
                 * This function receives a router ACK structure, and also receives,
                 * a data point objcet. All of which are processed, and passed to
                 * the USB HID object, which then is passed to the CPU.
                 *
*******          9. send_sensor_query(call_priority_table_t* table);
                    -> receive_router_ack();
                    -> receive_data_points();
    #ENDIF

    // This state is reached when either an error occurs on the router
    // side or an error occurs on the remote sensor side. This is a polling
    // interrupt. All systems are stopped when this occurs, or failsafe/debug
    // mode is activated.

    #IF(ERROR)

         * This function presents the interrupt procedure for a remote error.
         * First we receive the error message with the cause, and then we reboot
         * The erroneous device. We must make sure to dealloc or free() the mem
         * used for the device. We must make sure that the device saves its
         * configs and loads them after reboot. We must also make sure that the
         * device node is then powered up correctly afterwards.

*******  interrupt_process();
            -> receive_error_msg(); // contains cause.
            -> send_save_configs_msg(byte* device_node);
            -> reboot_erroneous_device(byte* device_node);
            -> check_remote_configs(byte* device_node);
            -> reinsert_into_ntwk(byte* device_node);

    #ENDIF */

class USB_DEVICE {

	public:

		void run();
};


#endif /* USB_DEVICE_IMPLEMENTATION_H_ */
