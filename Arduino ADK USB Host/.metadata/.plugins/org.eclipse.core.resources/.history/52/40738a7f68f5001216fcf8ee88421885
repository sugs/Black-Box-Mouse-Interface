/*
 * Sensor_Data_Buffer.h
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#ifndef SENSOR_DATA_BUFFER_H_
#define SENSOR_DATA_BUFFER_H_

/**
 * This Class Implements the ring buffer that will be used
 * to queue up the incoming packets from the sensor nodes.
 * This is only instantialized when the USB HID Host choice
 * is chosen. This library was taken from the mosquito project
 * on GOOGLE CODE as an open source library.
 */

#include <Arduino.h>

//! Define the default buffer size of 32 entries.
#define DEFAULTBUFSIZE 32

/**
 * This class handles all of the circular buffer handling including
 * reset and initializing.
 */
class SENSOR_DATA_BUFFER{

	private:

		//! The pointer to the data buffer.
		byte* data;

		//! The capacity of the buffer
		volatile unsigned int capacity;

		//! The position inside the buffer
		volatile unsigned int position;

		//! The length of the buffer.
		volatile unsigned int length;

		//! The error boolean.
		volatile boolean fillError;

	public:

		/**
		 * The default constructor, which initializes the buffer.
		 */
		SENSOR_DATA_BUFFER() {
			init();
		};

		/**
		 * This is an override for the default constructor.
		 * This implements a resizable buffer by means of the passed
		 * variable buf_size.
		 * @param buf_size - unsigned int.
		 */
		SENSOR_DATA_BUFFER(unsigned int buf_size) {
			init(buf_size);
		};

		/**
		 * This is the work method for the default allocation of the buffer.
		 * It needs a specific size.
		 * @param buf_size - unsigned int.
		 */
		void init(unsigned int buf_size);

		/**
		 * This is the default work method which initializes the buffer with
		 * 32 entries.
		 */
		void init();

		/**
		 * This resets the buffer and clears its entries.
		 */
		void clear();

		/**
		 * This method exits with an error and reboots.
		 */
		void resetError();

		/**
		 * This method returns true if there was a buffer overflow at some point.
		 * @return boolean
		 */
		boolean checkError();

		/**
		 * This method deallocates the ring buffer.
		 */
		void deAllocate();

		/**
		 * This method returns the space the ring buffer occupies.
		 * @return size - int
		 */
		int getSize();

		/**
		 * This method returns the capacity of the ring buffer.
		 * @return capacity (DEFAULT = 32) - int
		 */
		int getCapacity();

		/**
		 * This method returns the byte that is in a specific location.
		 * @param index - unsigned it
		 * @return byte - byte at position specified.
		 */
		byte peek(unsigned int index);

		/**
		 * This puts byte type in the front of the ring buffer.
		 * Returns 1 / 0 for Success and Failure
		 * @param in - byte
		 * @return byte
		 */
		uint8_t putInFront(byte in);

		/**
		 * Puts a byte in the buffer after all other data.
		 * Returns 1 / 0 for Success and Failure
		 * @param in - byte
		 * @return - byte
		 */
		uint8_t put(byte in);

		/**
		 * Puts a String type in the buffer
		 * Returns 1 / 0 for Success and Failure
		 * @param in - char*
		 * @return - byte
		 */
		uint8_t putString(char *in);

		/**
		 * Puts an integer type in the front buffer.
		 * @param in - int
		 * @return int - null
		 */
		int putIntInFront(int in);

		/**
		 * Puts integer type in the buffer.
		 * @param in - int
		 * @return int - null
		 */
		int putInt(int in);

		/**
		 * Puts a long type in the front of buffer.
		 * @param in - long
		 * @return int - null
		 */
		int putLongInFront(long in);

		/**
		 * Puts a long type in the buffer.
		 * @param in - long
		 * @return int - null
		 */
		int putLong(long in);

		/**
		 * Puts a float in the front of the buffer.
		 * @param in - float
		 * @return int - null
		 */
		int putFloatInFront(float in);

		/**
		 * Puts a float in the buffer.
		 * @param in - float
		 * @return int - null
		 */
		int putFloat(float in);

		/**
		 * Gets a byte from the buffer.
		 * @return byte
		 */
		byte get();

		/**
		 * Gets a byte from the back of the buffer.
		 * @return byte
		 */
		byte getFromBack();

		/**
		 * Gets an integer from the buffer at the current index.
		 * @return int
		 */
		int getInt();

		/**
		 * Gets an integer from the back of the buffer.
		 * @return int
		 */
		int getIntFromBack();

		/**
		 * Gets a long type from the buffer at the current index.
		 */
		long getLong();

		/**
		 * Gets a long type from the back of the buffer.
		 */
		long getLongFromBack();

		/**
		 * Gets a float type from the buffer at the current index.
		 * @return float
		 */
		float getFloat();

		/**
		 * Gets a float type from the buffer at the back of the buffer.
		 * @return float
		 */
		float getFloatFromBack();
};
#endif /* SENSOR_DATA_BUFFER_H_ */
