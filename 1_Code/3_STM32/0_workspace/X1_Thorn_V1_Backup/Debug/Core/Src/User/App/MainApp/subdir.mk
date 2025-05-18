################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/MainApp/MainApp.c 

OBJS += \
./Core/Src/User/App/MainApp/MainApp.o 

C_DEPS += \
./Core/Src/User/App/MainApp/MainApp.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/MainApp/%.o Core/Src/User/App/MainApp/%.su Core/Src/User/App/MainApp/%.cyclo: ../Core/Src/User/App/MainApp/%.c Core/Src/User/App/MainApp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-MainApp

clean-Core-2f-Src-2f-User-2f-App-2f-MainApp:
	-$(RM) ./Core/Src/User/App/MainApp/MainApp.cyclo ./Core/Src/User/App/MainApp/MainApp.d ./Core/Src/User/App/MainApp/MainApp.o ./Core/Src/User/App/MainApp/MainApp.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-MainApp

