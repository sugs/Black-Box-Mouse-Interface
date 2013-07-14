/*
 * Emulation_Packet_Aseembler.cpp
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#include "../USB_Implementation/USB_Reports.h"
#include "../System_Defines/Main_Defines.h"
#include "Emulation_Packet_Assembler.h"

#include <avr/interrupt.h>

//! Default Constructor
EMULATION_PACKET_ASSEMBLER::EMULATION_PACKET_ASSEMBLER(){
	//! Sending mutex
	sending_mutex = false;

	//! Initializing the enviroment variables
	packet_buffer = EMPTY;
	packet_id = EMPTY;
	packet_in_sending_queue = true;
	packet_size = USB_CFG_HID_REPORT_DESCRIPTOR_LENGTH;


}

//! Creates USB report frame
void EMULATION_PACKET_ASSEMBLER::create_usb_report_frame(){

#ifdef MOUSE_REPORT

	//! Setup the structure values
	mouse_report.report_id = 1;
	mouse_report.buttons = random(255);
	mouse_report.wheel = random(255);
	mouse_report.x = random(255);
	mouse_report.y = random(255);

	//! Reassign the structure to send.
	packet_buffer = &mouse_report;
#endif

#ifdef JOYSTICK_REPORT

	//! Setup the structure values
	joystick_report.report_id = 1;
	joystick_report.buttons = random(255);
	joystick_report.x = random(6556);
	joystick_report.y = random(6556);

	//! Reassign the structure to send.
	packet_buffer = &joystick_report;
#endif

#ifdef MOUSE_JOYSTICK_REPORT

	//! Setup the structure values
	joystick_mouse_report.mouse.report_id = 1;
	joystick_mouse_report.mouse.buttons = random(255);
	joystick_mouse_report.mouse.wheel = random(255);
	joystick_mouse_report.mouse.x = random(255);
	joystick_mouse_report.mouse.y = random(255);

	joystick_mouse_report.joystick.report_id = 1;
	joystick_mouse_report.joystick.buttons = random(255);
	joystick_mouse_report.joystick.x = random(6556);
	joystick_mouse_report.joystick.y = random(6556);

	//! Reassign the structure to send.
	packet_buffer = &joystick_mouse_report;

#endif
	update_packet_id();
	packet_in_sending_queue = true;
}

//! Sends a USB report frame
void EMULATION_PACKET_ASSEMBLER::send_usb_report_frame(){

#ifdef MOUSE_REPORT

	//! Send the structure.
	usbSendHidReport(&(byte)packet_buffer, sizeof(mouse_report));
#endif

#ifdef JOYSTICK_REPORT

	//! Send the structure.
	usbSendHidReport(&(byte)packet_buffer, sizeof(joystick_report));
#endif

#ifdef MOUSE_JOYSTICK_REPORT

	//! Send the structure.
	usbSendHidReport(&(byte)packet_buffer, sizeof(joystick_report));
#endif

	packet_in_sending_queue = false;
}

//! Update packet id
void EMULATION_PACKET_ASSEMBLER::update_packet_id(){
	packet_id ++;
}

//! Gets a packet id
word EMULATION_PACKET_ASSEMBLER::get_packet_id(){
	return (word)packet_id;
}

//! Emulates a USB interface
void EMULATION_PACKET_ASSEMBLER::emulate_usb(){

	//! Do this forever.
	while(1){

		//! Poll the USB Line
		usbPoll();

		//! Check to see if a report needs to be sent, using
		//! the idle rate.
		if ((TCNT1 > ((4 * (F_CPU / 1024000)) * idle_rate)
				|| TCNT1 > 0x7FFF) && idle_rate != 0) {

			//! Needs to send
			sending_mutex = true;
		}else{

			//! Create a valid random USB Frame
			create_usb_report_frame();
		}

		//! Poll the USB Line
		usbPoll();

		//! If we need to send.
		if(sending_mutex){

			//! Send the report.
			//! and reset the timer.
			send_usb_report_frame();
			TCNT1 = 0;
		}

		//! Poll the USB line
		usbPoll();

		//! No need to send anymore.
		sending_mutex = false;
	}
}
