################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/HighLevelControl/YawController/YawController.c 

OBJS += \
./Core/Src/User/App/HighLevelControl/YawController/YawController.o 

C_DEPS += \
./Core/Src/User/App/HighLevelControl/YawController/YawController.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/HighLevelControl/YawController/%.o Core/Src/User/App/HighLevelControl/YawController/%.su Core/Src/User/App/HighLevelControl/YawController/%.cyclo: ../Core/Src/User/App/HighLevelControl/YawController/%.c Core/Src/User/App/HighLevelControl/YawController/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-HighLevelControl-2f-YawController

clean-Core-2f-Src-2f-User-2f-App-2f-HighLevelControl-2f-YawController:
	-$(RM) ./Core/Src/User/App/HighLevelControl/YawController/YawController.cyclo ./Core/Src/User/App/HighLevelControl/YawController/YawController.d ./Core/Src/User/App/HighLevelControl/YawController/YawController.o ./Core/Src/User/App/HighLevelControl/YawController/YawController.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-HighLevelControl-2f-YawController

