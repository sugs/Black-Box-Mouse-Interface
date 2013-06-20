################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include logic/subdir.mk
-include driver/subdir.mk
-include Main\ -\ Demo/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ARCHIVES += \
libUSER_OBJS.a \


# All Target
all: Sensor\ Hub\ -\ Demo.elf

# Tool invocations
Sensor\ Hub\ -\ Demo.elf: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	msp430-gcc $(OBJS)  -o "Sensor Hub - Demo.elf"
	@echo 'Finished building target: $@'
	@echo ' '

libUSER_OBJS.a: $(OBJS) $(USER_OBJS)
	@echo 'Invoking: MSP430 Archiver'
	msp430-ar rcs  "libUSER_OBJS.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(ELFS) "Sensor Hub - Demo.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
