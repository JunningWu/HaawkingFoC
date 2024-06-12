################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src_board/drv8323s.c \
../src_board/hal.c \
../src_board/user_mtr1.c \
../src_board/user_mtr2.c 

OBJS += \
./src_board/drv8323s.o \
./src_board/hal.o \
./src_board/user_mtr1.o \
./src_board/user_mtr2.o 

C_DEPS += \
./src_board/drv8323s.d \
./src_board/hal.d \
./src_board/user_mtr1.d \
./src_board/user_mtr2.d 


# Each subdirectory must supply rules for building sources it contributes
src_board/%.o: ../src_board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-haawking-elf-gcc -march=rv32imfc_xhaawkaa1p0_xhaawkab1p0_xhaawkac1p0 -D__RUNNING_IN_FLASH_ -T "E:/Haawking_IDE/A01_AE/FASTLib_HX280025C_DSC5.1_DUAL_MOTOR_V1.0/haawking-drivers/ldscripts/HXS320F280025C_EDC_link_FLASH.ld" -mabi=ilp32f -mcmodel=medlow -mno-save-restore -menable-experimental-extensions --target=riscv32-unknown-elf --sysroot="D:/Program_Files/HaawKing_IDE/Haawking-IDE_V2.2.11beta2\haawking-tools/compiler/haawking-elf-gcc/riscv32-unknown-elf" --gcc-toolchain="D:/Program_Files/HaawKing_IDE/Haawking-IDE_V2.2.11beta2\haawking-tools/compiler/haawking-elf-gcc" -Odefault -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-inline-functions -cl-single-precision-constant -Wall -Wextra -Wl,--no-warn-rwx-segments  -g3 -gdwarf-3 -Wl,--defsym,IDE_VERSION_2_2_11beta2=0 -DDSC280025C_EDC -DFMSTR_USE_SCI -DDEBUG -I../haawking-drivers/haawking-dsc280025_edc-board/common -I"E:\Haawking_IDE\A01_AE\FASTLib_HX280025C_DSC5.1_DUAL_MOTOR_V1.0\haawking-drivers\haawking-dsc280025_edc-board\f28002x_common\include" -I"E:\Haawking_IDE\A01_AE\FASTLib_HX280025C_DSC5.1_DUAL_MOTOR_V1.0\haawking-drivers\haawking-dsc280025_edc-board\f28002x_headers\include" -I"E:\Haawking_IDE\A01_AE\FASTLib_HX280025C_DSC5.1_DUAL_MOTOR_V1.0\src\src_freemaster" -I"E:\Haawking_IDE\A01_AE\FASTLib_HX280025C_DSC5.1_DUAL_MOTOR_V1.0\src_board" -I"E:\Haawking_IDE\A01_AE\FASTLib_HX280025C_DSC5.1_DUAL_MOTOR_V1.0\src_control" -I"E:\Haawking_IDE\A01_AE\FASTLib_HX280025C_DSC5.1_DUAL_MOTOR_V1.0\src_est" -I../device -I../haawking-drivers/haawking-dsc280025_edc-board -I../src -std=gnu99 -x c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


