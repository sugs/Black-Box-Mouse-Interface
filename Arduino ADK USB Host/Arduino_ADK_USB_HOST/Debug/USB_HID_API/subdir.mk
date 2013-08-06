################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB_HID_API/oddebug.c \
../USB_HID_API/usbdrv.c 

S_UPPER_SRCS += \
../USB_HID_API/usbdrvasm.S 

ASM_SRCS += \
../USB_HID_API/usbdrvasm.asm 

OBJS += \
./USB_HID_API/oddebug.o \
./USB_HID_API/usbdrv.o \
./USB_HID_API/usbdrvasm.o 

C_DEPS += \
./USB_HID_API/oddebug.d \
./USB_HID_API/usbdrv.d 

S_UPPER_DEPS += \
./USB_HID_API/usbdrvasm.d 

ASM_DEPS += \
./USB_HID_API/usbdrvasm.d 


# Each subdirectory must supply rules for building sources it contributes
USB_HID_API/%.o: ../USB_HID_API/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Program Files (x86)\Arduino\hardware\arduino\cores\arduino" -I"C:\Users\fjpapin\workspace\USB_Device" -I"C:\Program Files (x86)\Arduino\hardware\tools\avr\avr\include" -I"C:\Program Files (x86)\Arduino\hardware\arduino\variants\mega" -I"C:\Program Files (x86)\Arduino\libraries" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_HID_API/%.o: ../USB_HID_API/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -g2 -gstabs -mmcu=atmega2560 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USB_HID_API/%.o: ../USB_HID_API/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -g2 -gstabs -mmcu=atmega2560 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


