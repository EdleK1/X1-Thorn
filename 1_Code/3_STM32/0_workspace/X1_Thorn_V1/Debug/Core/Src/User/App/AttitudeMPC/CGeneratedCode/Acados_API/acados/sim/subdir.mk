################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_collocation_utils.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_erk_integrator.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_gnsf.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_irk_integrator.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_lifted_irk_integrator.c 

OBJS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_collocation_utils.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_erk_integrator.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_gnsf.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_irk_integrator.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_lifted_irk_integrator.o 

C_DEPS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_collocation_utils.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_erk_integrator.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_gnsf.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_irk_integrator.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_lifted_irk_integrator.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/%.o Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/%.su Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/%.cyclo: ../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/%.c Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/hpipm/include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-sim

clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-sim:
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_collocation_utils.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_collocation_utils.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_collocation_utils.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_collocation_utils.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_erk_integrator.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_erk_integrator.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_erk_integrator.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_erk_integrator.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_gnsf.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_gnsf.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_gnsf.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_gnsf.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_irk_integrator.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_irk_integrator.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_irk_integrator.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_irk_integrator.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_lifted_irk_integrator.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_lifted_irk_integrator.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_lifted_irk_integrator.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/sim/sim_lifted_irk_integrator.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-sim

