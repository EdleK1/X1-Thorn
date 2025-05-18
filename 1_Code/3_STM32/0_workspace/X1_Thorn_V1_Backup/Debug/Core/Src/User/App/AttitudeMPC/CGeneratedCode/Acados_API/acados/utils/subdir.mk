################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/external_function_generic.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/math.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/mem.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/print.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/timing.c 

OBJS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/external_function_generic.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/math.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/mem.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/print.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/timing.o 

C_DEPS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/external_function_generic.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/math.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/mem.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/print.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/timing.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/%.o Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/%.su Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/%.cyclo: ../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/%.c Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/hpipm/include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-utils

clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-utils:
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/external_function_generic.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/external_function_generic.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/external_function_generic.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/external_function_generic.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/math.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/math.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/math.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/math.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/mem.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/mem.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/mem.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/mem.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/print.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/print.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/print.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/print.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/timing.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/timing.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/timing.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/utils/timing.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-utils

