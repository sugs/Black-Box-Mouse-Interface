################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OpenChronos-master/simpliciti/Components/mrfi/mrfi.c 

OBJS += \
./OpenChronos-master/simpliciti/Components/mrfi/mrfi.o 


# Each subdirectory must supply rules for building sources it contributes
OpenChronos-master/simpliciti/Components/mrfi/%.o: ../OpenChronos-master/simpliciti/Components/mrfi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/gcc" -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/include" -I"/Users/francispapineau/Documents/4th year project/msp430-toolchain-mac_os_x-x86_64-2.2/msp430/include" -O0 -g -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


