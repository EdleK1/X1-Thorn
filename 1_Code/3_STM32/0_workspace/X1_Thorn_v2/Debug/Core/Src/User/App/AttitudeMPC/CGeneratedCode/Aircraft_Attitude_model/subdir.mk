################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_ode_fun.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_adj.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_forw.c 

OBJS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_ode_fun.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_adj.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_forw.o 

C_DEPS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_ode_fun.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_adj.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_forw.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/%.o Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/%.su Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/%.cyclo: ../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/%.c Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/acados" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/acados_c" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/include/hpipm/include" -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Aircraft_Attitude_model

clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Aircraft_Attitude_model:
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_ode_fun.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_ode_fun.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_ode_fun.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_ode_fun.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_adj.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_adj.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_adj.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_adj.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_forw.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_forw.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_forw.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/Aircraft_Attitude_expl_vde_forw.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Aircraft_Attitude_model

