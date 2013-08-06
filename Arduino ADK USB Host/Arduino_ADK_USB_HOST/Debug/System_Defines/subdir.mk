################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../System_Defines/Command_Interpreter.cpp \
../System_Defines/NVRAM_API.cpp \
../System_Defines/Packet_Watchdog.cpp 

OBJS += \
./System_Defines/Command_Interpreter.o \
./System_Defines/NVRAM_API.o \
./System_Defines/Packet_Watchdog.o 

CPP_DEPS += \
./System_Defines/Command_Interpreter.d \
./System_Defines/NVRAM_API.d \
./System_Defines/Packet_Watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
System_Defines/%.o: ../System_Defines/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Program Files (x86)\Arduino\libraries" -I"C:\Users\fjpapin\workspace\USB_Device" -I"C:\Program Files (x86)\Arduino\hardware\tools\avr\avr\include" -I"C:\Program Files (x86)\Arduino\hardware\arduino\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\variants\mega" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -v -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


