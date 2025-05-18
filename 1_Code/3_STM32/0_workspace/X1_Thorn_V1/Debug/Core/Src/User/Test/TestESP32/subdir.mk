################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Test/TestESP32/TestESP32.c 

OBJS += \
./Core/Src/User/Test/TestESP32/TestESP32.o 

C_DEPS += \
./Core/Src/User/Test/TestESP32/TestESP32.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Test/TestESP32/%.o Core/Src/User/Test/TestESP32/%.su Core/Src/User/Test/TestESP32/%.cyclo: ../Core/Src/User/Test/TestESP32/%.c Core/Src/User/Test/TestESP32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Test-2f-TestESP32

clean-Core-2f-Src-2f-User-2f-Test-2f-TestESP32:
	-$(RM) ./Core/Src/User/Test/TestESP32/TestESP32.cyclo ./Core/Src/User/Test/TestESP32/TestESP32.d ./Core/Src/User/Test/TestESP32/TestESP32.o ./Core/Src/User/Test/TestESP32/TestESP32.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Test-2f-TestESP32

