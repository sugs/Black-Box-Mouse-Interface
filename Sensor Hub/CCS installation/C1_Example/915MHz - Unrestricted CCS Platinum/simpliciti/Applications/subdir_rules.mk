################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
simpliciti/Applications/main_AP_BM.obj: ../simpliciti/Applications/main_AP_BM.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.1.5/bin/cl430" --cmd_file="C:\Program Files (x86)\Texas Instruments\eZ430-Chronos\Software Projects\Chronos Watch\eZ430-Chronos v1.1 - white PCB\CCS\C1_Example\simpliciti\Configuration\smpl_nwk_config.dat" --cmd_file="C:\Program Files (x86)\Texas Instruments\eZ430-Chronos\Software Projects\Chronos Watch\eZ430-Chronos v1.1 - white PCB\CCS\C1_Example\simpliciti\Configuration\Access Point\smpl_config.dat"  -vmspx --abi=coffabi -O3 --opt_for_speed=3 --symdebug:skeletal --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/bluerobin" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.1.5/include" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/F5xx_F6xx_Core_Lib" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/bsp/boards/EZ430-CHRONOS_DONGLE/bsp_external" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/bsp/boards/EZ430-CHRONOS_DONGLE" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/mrfi" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/mrfi/smartrf/CC1101" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/mrfi/smartrf" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/mrfi/radios/common" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/mrfi/radios/family1" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/mrfi/radios" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/bsp/boards" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/bsp/drivers/code" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/bsp/drivers" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/bsp/mcus" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/bsp" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/nwk_applications" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/simpliciti/Components/nwk" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example/USB_config" --include_path="C:/Program Files (x86)/Texas Instruments/eZ430-Chronos/Software Projects/Chronos Watch/eZ430-Chronos v1.1 - white PCB/CCS/C1_Example" --define=__MSP430F5509__ --define=BSP_NO_BUTTONS --define=MRFI_CC1101 --define=ISM_US --define=__CCE__ --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simpliciti/Applications/main_AP_BM.pp" --obj_directory="simpliciti/Applications" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


