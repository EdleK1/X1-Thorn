################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Test/TestOdometry/TestOdometry.c 

OBJS += \
./Core/Src/User/Test/TestOdometry/TestOdometry.o 

C_DEPS += \
./Core/Src/User/Test/TestOdometry/TestOdometry.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Test/TestOdometry/%.o Core/Src/User/Test/TestOdometry/%.su Core/Src/User/Test/TestOdometry/%.cyclo: ../Core/Src/User/Test/TestOdometry/%.c Core/Src/User/Test/TestOdometry/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/acados" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/acados_c" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/hpipm/include" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Test-2f-TestOdometry

clean-Core-2f-Src-2f-User-2f-Test-2f-TestOdometry:
	-$(RM) ./Core/Src/User/Test/TestOdometry/TestOdometry.cyclo ./Core/Src/User/Test/TestOdometry/TestOdometry.d ./Core/Src/User/Test/TestOdometry/TestOdometry.o ./Core/Src/User/Test/TestOdometry/TestOdometry.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Test-2f-TestOdometry

