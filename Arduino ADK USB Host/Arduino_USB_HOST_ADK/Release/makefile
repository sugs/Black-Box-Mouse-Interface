################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include System_Defines/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Arduino_USB_HOST_ADK.lss \

FLASH_IMAGE += \
Arduino_USB_HOST_ADK.hex \

EEPROM_IMAGE += \
Arduino_USB_HOST_ADK.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Arduino_USB_HOST_ADK.elf secondary-outputs

# Tool invocations
Arduino_USB_HOST_ADK.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,Arduino_USB_HOST_ADK.map,--cref -L"/Users/francispapineau/Documents/4th year project/Source Code/Black-Box-Mouse-Interface/Arduino ADK USB Host" -mmcu=atmega2560 -o "Arduino_USB_HOST_ADK.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Arduino_USB_HOST_ADK.lss: Arduino_USB_HOST_ADK.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Arduino_USB_HOST_ADK.elf  >"Arduino_USB_HOST_ADK.lss"
	@echo 'Finished building: $@'
	@echo ' '

Arduino_USB_HOST_ADK.hex: Arduino_USB_HOST_ADK.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Arduino_USB_HOST_ADK.elf  "Arduino_USB_HOST_ADK.hex"
	@echo 'Finished building: $@'
	@echo ' '

Arduino_USB_HOST_ADK.eep: Arduino_USB_HOST_ADK.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Arduino_USB_HOST_ADK.elf  "Arduino_USB_HOST_ADK.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Arduino_USB_HOST_ADK.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 Arduino_USB_HOST_ADK.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Arduino_USB_HOST_ADK.elf
	@echo 'Invoking: AVRDude'
	/usr/local/CrossPack-AVR-20120217/bin/avrdude -pnull -Uflash:w:Arduino_USB_HOST_ADK.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(ELFS)$(FLASH_IMAGE)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(AVRDUDEDUMMY)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) Arduino_USB_HOST_ADK.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
