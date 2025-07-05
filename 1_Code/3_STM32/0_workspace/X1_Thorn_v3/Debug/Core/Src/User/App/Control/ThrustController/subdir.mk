################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/Control/ThrustController/ThrustController.c 

OBJS += \
./Core/Src/User/App/Control/ThrustController/ThrustController.o 

C_DEPS += \
./Core/Src/User/App/Control/ThrustController/ThrustController.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/Control/ThrustController/%.o Core/Src/User/App/Control/ThrustController/%.su Core/Src/User/App/Control/ThrustController/%.cyclo: ../Core/Src/User/App/Control/ThrustController/%.c Core/Src/User/App/Control/ThrustController/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-Control-2f-ThrustController

clean-Core-2f-Src-2f-User-2f-App-2f-Control-2f-ThrustController:
	-$(RM) ./Core/Src/User/App/Control/ThrustController/ThrustController.cyclo ./Core/Src/User/App/Control/ThrustController/ThrustController.d ./Core/Src/User/App/Control/ThrustController/ThrustController.o ./Core/Src/User/App/Control/ThrustController/ThrustController.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-Control-2f-ThrustController

