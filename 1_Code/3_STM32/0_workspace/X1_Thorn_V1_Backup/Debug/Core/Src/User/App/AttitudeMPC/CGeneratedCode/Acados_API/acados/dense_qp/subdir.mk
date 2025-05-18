################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_daqp.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_hpipm.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_ooqp.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qore.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qpoases.c 

OBJS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_daqp.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_hpipm.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_ooqp.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qore.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qpoases.o 

C_DEPS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_daqp.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_hpipm.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_ooqp.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qore.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qpoases.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/%.o Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/%.su Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/%.cyclo: ../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/%.c Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/hpipm/include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-dense_qp

clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-dense_qp:
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_daqp.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_daqp.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_daqp.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_daqp.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_hpipm.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_hpipm.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_hpipm.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_hpipm.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_ooqp.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_ooqp.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_ooqp.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_ooqp.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qore.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qore.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qore.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qore.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qpoases.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qpoases.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qpoases.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/dense_qp/dense_qp_qpoases.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-dense_qp

