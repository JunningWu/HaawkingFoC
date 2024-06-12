################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../haawking-drivers/haawking-dsc280025_edb-board/common/hx_intrinsics.c \
../haawking-drivers/haawking-dsc280025_edb-board/common/syscalls.c 

S_UPPER_SRCS += \
../haawking-drivers/haawking-dsc280025_edb-board/common/crt.S \
../haawking-drivers/haawking-dsc280025_edb-board/common/hx_fintdiv.S 

OBJS += \
./haawking-drivers/haawking-dsc280025_edb-board/common/crt.o \
./haawking-drivers/haawking-dsc280025_edb-board/common/hx_fintdiv.o \
./haawking-drivers/haawking-dsc280025_edb-board/common/hx_intrinsics.o \
./haawking-drivers/haawking-dsc280025_edb-board/common/syscalls.o 

S_UPPER_DEPS += \
./haawking-drivers/haawking-dsc280025_edb-board/common/crt.d \
./haawking-drivers/haawking-dsc280025_edb-board/common/hx_fintdiv.d 

C_DEPS += \
./haawking-drivers/haawking-dsc280025_edb-board/common/hx_intrinsics.d \
./haawking-drivers/haawking-dsc280025_edb-board/common/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
haawking-drivers/haawking-dsc280025_edb-board/common/%.o: ../haawking-drivers/haawking-dsc280025_edb-board/common/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-haawking-elf-gcc -march=rv32imfc_xhaawkaa1p0_xhaawkab1p0_xhaawkac1p0 -D__RUNNING_IN_FLASH_ -T HXS320F280025C_EDC_link_FLASH.ld -mabi=ilp32f -mcmodel=medlow -mno-save-restore -menable-experimental-extensions --target=riscv32-unknown-elf --sysroot="D:/IDE/Haawking-IDE_2.2.5beta2/Haawking-IDE_2.2.5beta2\haawking-tools/compiler/haawking-elf-gcc/riscv32-unknown-elf" --gcc-toolchain="D:/IDE/Haawking-IDE_2.2.5beta2/Haawking-IDE_2.2.5beta2\haawking-tools/compiler/haawking-elf-gcc" -Odefault -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-inline-functions -cl-single-precision-constant -Wall -Wextra -Wl,--no-warn-rwx-segments  -g3 -gdwarf-3 -Wl,--defsym,IDE_VERSION__2_5beta2=0 -x assembler-with-cpp -I"C:\Users\Kangaihong\haawking-workspace1\FASTLib_HX280025C_V2.0\src" -I"C:\Users\Kangaihong\haawking-workspace1\FASTLib_HX280025C_V2.0\src_board" -I"C:\Users\Kangaihong\haawking-workspace1\FASTLib_HX280025C_V2.0\src_control" -I"C:\Users\Kangaihong\haawking-workspace1\FASTLib_HX280025C_V2.0\src_est" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

haawking-drivers/haawking-dsc280025_edb-board/common/%.o: ../haawking-drivers/haawking-dsc280025_edb-board/common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-haawking-elf-gcc -march=rv32imfc_xhaawkaa1p0_xhaawkab1p0_xhaawkac1p0 -D__RUNNING_IN_FLASH_ -T HXS320F280025C_EDC_link_FLASH.ld -mabi=ilp32f -mcmodel=medlow -mno-save-restore -menable-experimental-extensions --target=riscv32-unknown-elf --sysroot="D:/IDE/Haawking-IDE_2.2.5beta2/Haawking-IDE_2.2.5beta2\haawking-tools/compiler/haawking-elf-gcc/riscv32-unknown-elf" --gcc-toolchain="D:/IDE/Haawking-IDE_2.2.5beta2/Haawking-IDE_2.2.5beta2\haawking-tools/compiler/haawking-elf-gcc" -Odefault -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-inline-functions -cl-single-precision-constant -Wall -Wextra -Wl,--no-warn-rwx-segments  -g3 -gdwarf-3 -Wl,--defsym,IDE_VERSION__2_5beta2=0 -DDSC280025C_EDC -DDEBUG -I../haawking-drivers/haawking-dsc280025_edc-board/common -I"C:\Users\Kangaihong\haawking-workspace1\FASTLib_HX280025C_V2.0\src_board" -I"C:\Users\Kangaihong\haawking-workspace1\FASTLib_HX280025C_V2.0\src_control" -I"C:\Users\Kangaihong\haawking-workspace1\FASTLib_HX280025C_V2.0\src_est" -I../device -I../haawking-drivers/haawking-dsc280025_edc-board -I../src -std=gnu99 -x c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


