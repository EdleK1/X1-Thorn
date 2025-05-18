################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Test/TestGroundCommands/TestGroundCommands.c 

OBJS += \
./Core/Src/User/Test/TestGroundCommands/TestGroundCommands.o 

C_DEPS += \
./Core/Src/User/Test/TestGroundCommands/TestGroundCommands.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Test/TestGroundCommands/%.o Core/Src/User/Test/TestGroundCommands/%.su Core/Src/User/Test/TestGroundCommands/%.cyclo: ../Core/Src/User/Test/TestGroundCommands/%.c Core/Src/User/Test/TestGroundCommands/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Test-2f-TestGroundCommands

clean-Core-2f-Src-2f-User-2f-Test-2f-TestGroundCommands:
	-$(RM) ./Core/Src/User/Test/TestGroundCommands/TestGroundCommands.cyclo ./Core/Src/User/Test/TestGroundCommands/TestGroundCommands.d ./Core/Src/User/Test/TestGroundCommands/TestGroundCommands.o ./Core/Src/User/Test/TestGroundCommands/TestGroundCommands.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Test-2f-TestGroundCommands

