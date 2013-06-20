################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../logic/acceleration.c \
../logic/agility.c \
../logic/alarm.c \
../logic/altitude.c \
../logic/battery.c \
../logic/bluerobin.c \
../logic/clock.c \
../logic/countdowntimer.c \
../logic/date.c \
../logic/display2.c \
../logic/menu.c \
../logic/miscellaneous.c \
../logic/random.c \
../logic/rfbsl.c \
../logic/rfsimpliciti.c \
../logic/stopwatch.c \
../logic/stubs.c \
../logic/temperature.c \
../logic/test.c \
../logic/user.c 

OBJS += \
./logic/acceleration.o \
./logic/agility.o \
./logic/alarm.o \
./logic/altitude.o \
./logic/battery.o \
./logic/bluerobin.o \
./logic/clock.o \
./logic/countdowntimer.o \
./logic/date.o \
./logic/display2.o \
./logic/menu.o \
./logic/miscellaneous.o \
./logic/random.o \
./logic/rfbsl.o \
./logic/rfsimpliciti.o \
./logic/stopwatch.o \
./logic/stubs.o \
./logic/temperature.o \
./logic/test.o \
./logic/user.o 


# Each subdirectory must supply rules for building sources it contributes
logic/%.o: ../logic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -I"/Users/francispapineau/Documents/4th year project/msp430-toolchain-mac_os_x-x86_64-2.2/msp430/include" -include"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/V2.2/include/project.h" -O0 -g -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


