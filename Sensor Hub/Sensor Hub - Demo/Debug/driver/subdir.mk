################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/adc12.c \
../driver/buzzer.c \
../driver/display.c \
../driver/display1.c \
../driver/pmm.c \
../driver/ports.c \
../driver/radio.c \
../driver/rf1a.c \
../driver/timer.c \
../driver/vti_as.c \
../driver/vti_ps.c 

OBJS += \
./driver/adc12.o \
./driver/buzzer.o \
./driver/display.o \
./driver/display1.o \
./driver/pmm.o \
./driver/ports.o \
./driver/radio.o \
./driver/rf1a.o \
./driver/timer.o \
./driver/vti_as.o \
./driver/vti_ps.o 


# Each subdirectory must supply rules for building sources it contributes
driver/%.o: ../driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -I"/Users/francispapineau/Documents/4th year project/msp430-toolchain-mac_os_x-x86_64-2.2/msp430/include" -include"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/V2.2/include/project.h" -O0 -g -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


