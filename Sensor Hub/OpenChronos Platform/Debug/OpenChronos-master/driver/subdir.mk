################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OpenChronos-master/driver/adc12.c \
../OpenChronos-master/driver/buzzer.c \
../OpenChronos-master/driver/display.c \
../OpenChronos-master/driver/display1.c \
../OpenChronos-master/driver/dsp.c \
../OpenChronos-master/driver/infomem.c \
../OpenChronos-master/driver/pmm.c \
../OpenChronos-master/driver/ports.c \
../OpenChronos-master/driver/radio.c \
../OpenChronos-master/driver/rf1a.c \
../OpenChronos-master/driver/timer.c \
../OpenChronos-master/driver/vti_as.c \
../OpenChronos-master/driver/vti_ps.c 

OBJS += \
./OpenChronos-master/driver/adc12.o \
./OpenChronos-master/driver/buzzer.o \
./OpenChronos-master/driver/display.o \
./OpenChronos-master/driver/display1.o \
./OpenChronos-master/driver/dsp.o \
./OpenChronos-master/driver/infomem.o \
./OpenChronos-master/driver/pmm.o \
./OpenChronos-master/driver/ports.o \
./OpenChronos-master/driver/radio.o \
./OpenChronos-master/driver/rf1a.o \
./OpenChronos-master/driver/timer.o \
./OpenChronos-master/driver/vti_as.o \
./OpenChronos-master/driver/vti_ps.o 


# Each subdirectory must supply rules for building sources it contributes
OpenChronos-master/driver/%.o: ../OpenChronos-master/driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/gcc" -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/include" -I"/Users/francispapineau/Documents/4th year project/msp430-toolchain-mac_os_x-x86_64-2.2/msp430/include" -O0 -g -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


