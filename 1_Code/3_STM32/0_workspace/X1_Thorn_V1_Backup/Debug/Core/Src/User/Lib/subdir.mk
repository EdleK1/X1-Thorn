################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Lib/Algebra.c 

OBJS += \
./Core/Src/User/Lib/Algebra.o 

C_DEPS += \
./Core/Src/User/Lib/Algebra.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Lib/%.o Core/Src/User/Lib/%.su Core/Src/User/Lib/%.cyclo: ../Core/Src/User/Lib/%.c Core/Src/User/Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Lib

clean-Core-2f-Src-2f-User-2f-Lib:
	-$(RM) ./Core/Src/User/Lib/Algebra.cyclo ./Core/Src/User/Lib/Algebra.d ./Core/Src/User/Lib/Algebra.o ./Core/Src/User/Lib/Algebra.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Lib

