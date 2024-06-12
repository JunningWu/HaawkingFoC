################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src_freemaster/freemaster_Kxx.c \
../src_freemaster/freemaster_appcmd.c \
../src_freemaster/freemaster_bdm.c \
../src_freemaster/freemaster_can.c \
../src_freemaster/freemaster_lin.c \
../src_freemaster/freemaster_pipes.c \
../src_freemaster/freemaster_protocol.c \
../src_freemaster/freemaster_rec.c \
../src_freemaster/freemaster_scope.c \
../src_freemaster/freemaster_serial.c \
../src_freemaster/freemaster_sfio.c \
../src_freemaster/freemaster_tsa.c 

OBJS += \
./src_freemaster/freemaster_Kxx.o \
./src_freemaster/freemaster_appcmd.o \
./src_freemaster/freemaster_bdm.o \
./src_freemaster/freemaster_can.o \
./src_freemaster/freemaster_lin.o \
./src_freemaster/freemaster_pipes.o \
./src_freemaster/freemaster_protocol.o \
./src_freemaster/freemaster_rec.o \
./src_freemaster/freemaster_scope.o \
./src_freemaster/freemaster_serial.o \
./src_freemaster/freemaster_sfio.o \
./src_freemaster/freemaster_tsa.o 

C_DEPS += \
./src_freemaster/freemaster_Kxx.d \
./src_freemaster/freemaster_appcmd.d \
./src_freemaster/freemaster_bdm.d \
./src_freemaster/freemaster_can.d \
./src_freemaster/freemaster_lin.d \
./src_freemaster/freemaster_pipes.d \
./src_freemaster/freemaster_protocol.d \
./src_freemaster/freemaster_rec.d \
./src_freemaster/freemaster_scope.d \
./src_freemaster/freemaster_serial.d \
./src_freemaster/freemaster_sfio.d \
./src_freemaster/freemaster_tsa.d 


# Each subdirectory must supply rules for building sources it contributes
src_freemaster/%.o: ../src_freemaster/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-haawking-elf-gcc -march=rv32imfc_xhaawkaa1p0_xhaawkab1p0_xhaawkac1p0 -D__RUNNING_IN_FLASH_ -T "D:/Users/ab/haawking-workspace-V2.2.8Pre/FASTLib_HX280025CEDC_V2.0_pre/haawking-drivers/ldscripts/HXS320F280025C_EDC_link_FLASH.ld" -mabi=ilp32f -mcmodel=medlow -mno-save-restore -menable-experimental-extensions --target=riscv32-unknown-elf --sysroot="D:/Program Files (x86)/Haawking-IDE_V2.2.8Pre\haawking-tools/compiler/haawking-elf-gcc/riscv32-unknown-elf" --gcc-toolchain="D:/Program Files (x86)/Haawking-IDE_V2.2.8Pre\haawking-tools/compiler/haawking-elf-gcc" -Odefault -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-inline-functions -cl-single-precision-constant -Wall -Wextra -Wl,--no-warn-rwx-segments  -g3 -gdwarf-3 -Wl,--defsym,IDE_VERSION_2_2_8Pre=0 -DDSC280025C_EDC -DFMSTR_USE_SCI -DDEBUG -I../haawking-drivers/haawking-dsc280025_edc-board/common -I"D:\Users\ab\haawking-workspace-V2.2.8Pre\FASTLib_HX280025CEDC_V2.0_pre\src_freemaster" -I"D:\Users\ab\haawking-workspace-V2.2.8Pre\FASTLib_HX280025CEDC_V2.0_pre\haawking-drivers\haawking-dsc280025_edc-board\f28002x_common\include" -I"D:\Users\ab\haawking-workspace-V2.2.8Pre\FASTLib_HX280025CEDC_V2.0_pre\haawking-drivers\haawking-dsc280025_edc-board\f28002x_headers\include" -I"D:\Users\ab\haawking-workspace-V2.2.8Pre\FASTLib_HX280025CEDC_V2.0_pre\src_board" -I"D:\Users\ab\haawking-workspace-V2.2.8Pre\FASTLib_HX280025CEDC_V2.0_pre\src_control" -I"D:\Users\ab\haawking-workspace-V2.2.8Pre\FASTLib_HX280025CEDC_V2.0_pre\src_est" -I../device -I../haawking-drivers/haawking-dsc280025_edc-board -I../src -std=gnu99 -x c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


