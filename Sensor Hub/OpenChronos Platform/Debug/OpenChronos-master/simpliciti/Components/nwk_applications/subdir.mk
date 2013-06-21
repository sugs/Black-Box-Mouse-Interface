################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OpenChronos-master/simpliciti/Components/nwk_applications/nwk_freq.c \
../OpenChronos-master/simpliciti/Components/nwk_applications/nwk_ioctl.c \
../OpenChronos-master/simpliciti/Components/nwk_applications/nwk_join.c \
../OpenChronos-master/simpliciti/Components/nwk_applications/nwk_link.c \
../OpenChronos-master/simpliciti/Components/nwk_applications/nwk_mgmt.c \
../OpenChronos-master/simpliciti/Components/nwk_applications/nwk_ping.c \
../OpenChronos-master/simpliciti/Components/nwk_applications/nwk_security.c 

OBJS += \
./OpenChronos-master/simpliciti/Components/nwk_applications/nwk_freq.o \
./OpenChronos-master/simpliciti/Components/nwk_applications/nwk_ioctl.o \
./OpenChronos-master/simpliciti/Components/nwk_applications/nwk_join.o \
./OpenChronos-master/simpliciti/Components/nwk_applications/nwk_link.o \
./OpenChronos-master/simpliciti/Components/nwk_applications/nwk_mgmt.o \
./OpenChronos-master/simpliciti/Components/nwk_applications/nwk_ping.o \
./OpenChronos-master/simpliciti/Components/nwk_applications/nwk_security.o 


# Each subdirectory must supply rules for building sources it contributes
OpenChronos-master/simpliciti/Components/nwk_applications/%.o: ../OpenChronos-master/simpliciti/Components/nwk_applications/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/gcc" -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/include" -I"/Users/francispapineau/Documents/4th year project/msp430-toolchain-mac_os_x-x86_64-2.2/msp430/include" -O0 -g -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


