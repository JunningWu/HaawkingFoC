################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf *.s *.map *.asm

# All of the sources participating in the build are defined here
-include sources.mk
-include src_control/subdir.mk
-include src_board/subdir.mk
-include src/src_freemaster/subdir.mk
-include src/subdir.mk
-include haawking-drivers/haawking-dsc280025_edc-board/f28002x_headers/source/subdir.mk
-include haawking-drivers/haawking-dsc280025_edc-board/f28002x_common/source/subdir.mk
-include haawking-drivers/haawking-dsc280025_edc-board/common/subdir.mk
-include haawking-drivers/haawking-dsc280025_edc-board/subdir.mk
-include device/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_GCCASM += \
FASTLib_HX280025CEDC_V2.0_pre_Freemaster.s \

SECONDARY_LLVMASM += \
FASTLib_HX280025CEDC_V2.0_pre_Freemaster.asm \

SECONDARY_FLASH += \
FASTLib_HX280025CEDC_V2.0_pre_Freemaster.hex \

SECONDARY_SIZE += \
FASTLib_HX280025CEDC_V2.0_pre_Freemaster.siz \


# All Target
all: FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf secondary-outputs

# print-size
print-size:
	llvm-nm -n --print-size "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf">>"FASTLib_HX280025CEDC_V2.0_pre_Freemaster.map"

# Tool invocations
FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	riscv32-haawking-elf-gcc -march=rv32imfc_xhaawkaa1p0_xhaawkab1p0_xhaawkac1p0 -D__RUNNING_IN_FLASH_ -T "E:/Haawking_IDE/A01_AE/FASTLib_HX280025CEDC_V2.0_pre_Freemaster/haawking-drivers/ldscripts/HXS320F280025C_EDC_link_FLASH.ld" -mabi=ilp32f -mcmodel=medlow -mno-save-restore -menable-experimental-extensions --target=riscv32-unknown-elf --sysroot="D:/Program_Files/HaawKing_IDE/Haawking-IDE_V2.2.11beta2\haawking-tools/compiler/haawking-elf-gcc/riscv32-unknown-elf" --gcc-toolchain="D:/Program_Files/HaawKing_IDE/Haawking-IDE_V2.2.11beta2\haawking-tools/compiler/haawking-elf-gcc" -Odefault -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-inline-functions -cl-single-precision-constant -Wall -Wextra -Wl,--no-warn-rwx-segments  -g3 -gdwarf-3 -Wl,--defsym,IDE_VERSION_2_2_11beta2=0 -nostartfiles -nostdlib -Xlinker --gc-sections -L../lib -L../haawking-drivers/ldscripts -L"D:/Program_Files/HaawKing_IDE/Haawking-IDE_V2.2.11beta2/haawking-tools/segger_lib" -Wl,-Map,"FASTLib_HX280025CEDC_V2.0_pre_Freemaster.map" -o "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	$(MAKE) --no-print-directory print-size

FASTLib_HX280025CEDC_V2.0_pre_Freemaster.s: FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf
	@riscv64-unknown-elf-objdump -D "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf" > "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.s"

FASTLib_HX280025CEDC_V2.0_pre_Freemaster.asm: FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf
	@riscv32-haawking-elf-objdump -D "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf" > "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.asm"

FASTLib_HX280025CEDC_V2.0_pre_Freemaster.hex: FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf
	@riscv32-haawking-elf-objcopy -O ihex "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf"  "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.hex"

FASTLib_HX280025CEDC_V2.0_pre_Freemaster.siz: FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf
	riscv32-haawking-elf-size --format=berkeley "FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf"

# Other Targets
clean:
	-$(RM) $(SECONDARY_LLVMASM)$(CLA_DEPS)$(SECONDARY_GCCASM)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) FASTLib_HX280025CEDC_V2.0_pre_Freemaster.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_GCCASM) $(SECONDARY_LLVMASM) $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
