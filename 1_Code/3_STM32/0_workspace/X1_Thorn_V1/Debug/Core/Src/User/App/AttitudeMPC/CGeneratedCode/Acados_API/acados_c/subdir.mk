################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/condensing_interface.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/dense_qp_interface.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/external_function_interface.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_nlp_interface.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_qp_interface.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/sim_interface.c 

OBJS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/condensing_interface.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/dense_qp_interface.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/external_function_interface.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_nlp_interface.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_qp_interface.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/sim_interface.o 

C_DEPS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/condensing_interface.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/dense_qp_interface.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/external_function_interface.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_nlp_interface.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_qp_interface.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/sim_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/%.o Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/%.su Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/%.cyclo: ../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/%.c Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/hpipm/include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados_c

clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados_c:
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/condensing_interface.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/condensing_interface.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/condensing_interface.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/condensing_interface.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/dense_qp_interface.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/dense_qp_interface.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/dense_qp_interface.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/dense_qp_interface.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/external_function_interface.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/external_function_interface.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/external_function_interface.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/external_function_interface.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_nlp_interface.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_nlp_interface.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_nlp_interface.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_nlp_interface.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_qp_interface.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_qp_interface.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_qp_interface.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/ocp_qp_interface.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/sim_interface.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/sim_interface.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/sim_interface.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados_c/sim_interface.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados_c

