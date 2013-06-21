################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include OpenChronos-master/simpliciti/Components/nwk_applications/subdir.mk
-include OpenChronos-master/simpliciti/Components/nwk/subdir.mk
-include OpenChronos-master/simpliciti/Components/mrfi/radios/family5/subdir.mk
-include OpenChronos-master/simpliciti/Components/mrfi/subdir.mk
-include OpenChronos-master/simpliciti/Components/bsp/drivers/code/subdir.mk
-include OpenChronos-master/simpliciti/Components/bsp/boards/CC430EM/subdir.mk
-include OpenChronos-master/simpliciti/Components/bsp/subdir.mk
-include OpenChronos-master/simpliciti/Applications/application/End_Device/subdir.mk
-include OpenChronos-master/logic/subdir.mk
-include OpenChronos-master/gcc/subdir.mk
-include OpenChronos-master/driver/subdir.mk
-include OpenChronos-master/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ARCHIVES += \
libUSER_OBJS.a \


# All Target
all: OpenChronos\ Platform.elf

# Tool invocations
OpenChronos\ Platform.elf: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	msp430-gcc $(OBJS)  -o "OpenChronos Platform.elf"
	@echo 'Finished building target: $@'
	@echo ' '

libUSER_OBJS.a: $(OBJS) $(USER_OBJS)
	@echo 'Invoking: MSP430 Archiver'
	msp430-ar rcs  "libUSER_OBJS.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ARCHIVES)$(ELFS) "OpenChronos Platform.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
