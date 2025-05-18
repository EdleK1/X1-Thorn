################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Peripheral/BNO055/BNO055.c 

OBJS += \
./Core/Src/User/Peripheral/BNO055/BNO055.o 

C_DEPS += \
./Core/Src/User/Peripheral/BNO055/BNO055.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Peripheral/BNO055/%.o Core/Src/User/Peripheral/BNO055/%.su Core/Src/User/Peripheral/BNO055/%.cyclo: ../Core/Src/User/Peripheral/BNO055/%.c Core/Src/User/Peripheral/BNO055/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/acados" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/acados_c" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/hpipm/include" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Peripheral-2f-BNO055

clean-Core-2f-Src-2f-User-2f-Peripheral-2f-BNO055:
	-$(RM) ./Core/Src/User/Peripheral/BNO055/BNO055.cyclo ./Core/Src/User/Peripheral/BNO055/BNO055.d ./Core/Src/User/Peripheral/BNO055/BNO055.o ./Core/Src/User/Peripheral/BNO055/BNO055.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Peripheral-2f-BNO055

