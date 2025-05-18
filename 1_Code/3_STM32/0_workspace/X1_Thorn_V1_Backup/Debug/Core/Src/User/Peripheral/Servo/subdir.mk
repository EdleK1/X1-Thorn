################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Peripheral/Servo/Servo.c 

OBJS += \
./Core/Src/User/Peripheral/Servo/Servo.o 

C_DEPS += \
./Core/Src/User/Peripheral/Servo/Servo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Peripheral/Servo/%.o Core/Src/User/Peripheral/Servo/%.su Core/Src/User/Peripheral/Servo/%.cyclo: ../Core/Src/User/Peripheral/Servo/%.c Core/Src/User/Peripheral/Servo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Peripheral-2f-Servo

clean-Core-2f-Src-2f-User-2f-Peripheral-2f-Servo:
	-$(RM) ./Core/Src/User/Peripheral/Servo/Servo.cyclo ./Core/Src/User/Peripheral/Servo/Servo.d ./Core/Src/User/Peripheral/Servo/Servo.o ./Core/Src/User/Peripheral/Servo/Servo.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Peripheral-2f-Servo

