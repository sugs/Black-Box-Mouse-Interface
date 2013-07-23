################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sensor_Parser_Implementation/Sensor_Data_Buffer.cpp \
../Sensor_Parser_Implementation/Sensor_Packet_Assembler.cpp \
../Sensor_Parser_Implementation/Sensor_Parser.cpp 

OBJS += \
./Sensor_Parser_Implementation/Sensor_Data_Buffer.o \
./Sensor_Parser_Implementation/Sensor_Packet_Assembler.o \
./Sensor_Parser_Implementation/Sensor_Parser.o 

CPP_DEPS += \
./Sensor_Parser_Implementation/Sensor_Data_Buffer.d \
./Sensor_Parser_Implementation/Sensor_Packet_Assembler.d \
./Sensor_Parser_Implementation/Sensor_Parser.d 


# Each subdirectory must supply rules for building sources it contributes
Sensor_Parser_Implementation/%.o: ../Sensor_Parser_Implementation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Arduino ADK USB Host/arduino/variants/mega" -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Arduino ADK USB Host/arduino/cores/arduino" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


