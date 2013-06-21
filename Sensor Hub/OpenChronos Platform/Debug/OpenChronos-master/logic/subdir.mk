################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../OpenChronos-master/logic/acceleration.o \
../OpenChronos-master/logic/alarm.o \
../OpenChronos-master/logic/altitude.o \
../OpenChronos-master/logic/battery.o \
../OpenChronos-master/logic/clock.o \
../OpenChronos-master/logic/date.o \
../OpenChronos-master/logic/eggtimer.o \
../OpenChronos-master/logic/menu.o \
../OpenChronos-master/logic/phase_clock.o \
../OpenChronos-master/logic/prout.o \
../OpenChronos-master/logic/rfbsl.o \
../OpenChronos-master/logic/rfsimpliciti.o \
../OpenChronos-master/logic/stopwatch.o \
../OpenChronos-master/logic/temperature.o \
../OpenChronos-master/logic/test.o \
../OpenChronos-master/logic/user.o \
../OpenChronos-master/logic/vario.o 

C_SRCS += \
../OpenChronos-master/logic/MYsimpliciti.c \
../OpenChronos-master/logic/acceleration.c \
../OpenChronos-master/logic/alarm.c \
../OpenChronos-master/logic/altitude.c \
../OpenChronos-master/logic/battery.c \
../OpenChronos-master/logic/bluerobin.c \
../OpenChronos-master/logic/clock.c \
../OpenChronos-master/logic/date.c \
../OpenChronos-master/logic/dst.c \
../OpenChronos-master/logic/eggtimer.c \
../OpenChronos-master/logic/gps.c \
../OpenChronos-master/logic/menu.c \
../OpenChronos-master/logic/phase_clock.c \
../OpenChronos-master/logic/prout.c \
../OpenChronos-master/logic/rfbsl.c \
../OpenChronos-master/logic/rfsimpliciti.c \
../OpenChronos-master/logic/sequence.c \
../OpenChronos-master/logic/sidereal.c \
../OpenChronos-master/logic/stopwatch.c \
../OpenChronos-master/logic/strength.c \
../OpenChronos-master/logic/temperature.c \
../OpenChronos-master/logic/test.c \
../OpenChronos-master/logic/user.c \
../OpenChronos-master/logic/vario.c 

OBJS += \
./OpenChronos-master/logic/MYsimpliciti.o \
./OpenChronos-master/logic/acceleration.o \
./OpenChronos-master/logic/alarm.o \
./OpenChronos-master/logic/altitude.o \
./OpenChronos-master/logic/battery.o \
./OpenChronos-master/logic/bluerobin.o \
./OpenChronos-master/logic/clock.o \
./OpenChronos-master/logic/date.o \
./OpenChronos-master/logic/dst.o \
./OpenChronos-master/logic/eggtimer.o \
./OpenChronos-master/logic/gps.o \
./OpenChronos-master/logic/menu.o \
./OpenChronos-master/logic/phase_clock.o \
./OpenChronos-master/logic/prout.o \
./OpenChronos-master/logic/rfbsl.o \
./OpenChronos-master/logic/rfsimpliciti.o \
./OpenChronos-master/logic/sequence.o \
./OpenChronos-master/logic/sidereal.o \
./OpenChronos-master/logic/stopwatch.o \
./OpenChronos-master/logic/strength.o \
./OpenChronos-master/logic/temperature.o \
./OpenChronos-master/logic/test.o \
./OpenChronos-master/logic/user.o \
./OpenChronos-master/logic/vario.o 


# Each subdirectory must supply rules for building sources it contributes
OpenChronos-master/logic/%.o: ../OpenChronos-master/logic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 C Compiler'
	msp430-gcc -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/gcc" -I"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Original Code/OpenChronos-master/include" -I"/Users/francispapineau/Documents/4th year project/msp430-toolchain-mac_os_x-x86_64-2.2/msp430/include" -O0 -g -Wall -std=gnu89 -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


