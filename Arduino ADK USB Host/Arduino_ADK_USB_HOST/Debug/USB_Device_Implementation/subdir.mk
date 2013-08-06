################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../USB_Device_Implementation/USB_Device_Implementation.cpp \
../USB_Device_Implementation/USB_State_Machine.cpp 

OBJS += \
./USB_Device_Implementation/USB_Device_Implementation.o \
./USB_Device_Implementation/USB_State_Machine.o 

CPP_DEPS += \
./USB_Device_Implementation/USB_Device_Implementation.d \
./USB_Device_Implementation/USB_State_Machine.d 


# Each subdirectory must supply rules for building sources it contributes
USB_Device_Implementation/%.o: ../USB_Device_Implementation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Program Files (x86)\Arduino\libraries" -I"C:\Users\fjpapin\workspace\USB_Device" -I"C:\Program Files (x86)\Arduino\hardware\tools\avr\avr\include" -I"C:\Program Files (x86)\Arduino\hardware\arduino\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\variants\mega" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -v -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


