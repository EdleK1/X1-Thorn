################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/acados_solver_Aircraft_Attitude.c 

OBJS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/acados_solver_Aircraft_Attitude.o 

C_DEPS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/acados_solver_Aircraft_Attitude.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/AttitudeMPC/CGeneratedCode/%.o Core/Src/User/App/AttitudeMPC/CGeneratedCode/%.su Core/Src/User/App/AttitudeMPC/CGeneratedCode/%.cyclo: ../Core/Src/User/App/AttitudeMPC/CGeneratedCode/%.c Core/Src/User/App/AttitudeMPC/CGeneratedCode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/acados" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/acados_c" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/hpipm/include" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode

clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode:
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/acados_solver_Aircraft_Attitude.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/acados_solver_Aircraft_Attitude.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/acados_solver_Aircraft_Attitude.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/acados_solver_Aircraft_Attitude.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode

