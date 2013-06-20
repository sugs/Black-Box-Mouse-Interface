################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Main\ -\ Demo/main.c 

OBJS += \
./Main\ -\ Demo/main.o 


# Each subdirectory must supply rules for building sources it contributes
Main\ -\ Demo/main.o: ../Main\ -\ Demo/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -I"/Users/francispapineau/Documents/4th year project/msp430-toolchain-mac_os_x-x86_64-2.2/msp430/include" -include"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/V2.2/include/project.h" -O0 -g -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


