################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Demo\ App/main.c 

OBJS += \
./Demo\ App/main.o 


# Each subdirectory must supply rules for building sources it contributes
Demo\ App/main.o: ../Demo\ App/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -O3 -g0 -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


