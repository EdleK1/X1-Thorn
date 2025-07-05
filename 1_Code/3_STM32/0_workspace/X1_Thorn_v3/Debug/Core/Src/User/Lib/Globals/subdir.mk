################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Lib/Globals/Globals.c 

OBJS += \
./Core/Src/User/Lib/Globals/Globals.o 

C_DEPS += \
./Core/Src/User/Lib/Globals/Globals.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Lib/Globals/%.o Core/Src/User/Lib/Globals/%.su Core/Src/User/Lib/Globals/%.cyclo: ../Core/Src/User/Lib/Globals/%.c Core/Src/User/Lib/Globals/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Lib-2f-Globals

clean-Core-2f-Src-2f-User-2f-Lib-2f-Globals:
	-$(RM) ./Core/Src/User/Lib/Globals/Globals.cyclo ./Core/Src/User/Lib/Globals/Globals.d ./Core/Src/User/Lib/Globals/Globals.o ./Core/Src/User/Lib/Globals/Globals.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Lib-2f-Globals

