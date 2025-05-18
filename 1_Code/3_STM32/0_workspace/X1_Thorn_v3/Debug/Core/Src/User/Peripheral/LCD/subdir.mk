################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/Peripheral/LCD/lcd.c \
../Core/Src/User/Peripheral/LCD/logo_160_80.c \
../Core/Src/User/Peripheral/LCD/st7735.c \
../Core/Src/User/Peripheral/LCD/st7735_reg.c 

OBJS += \
./Core/Src/User/Peripheral/LCD/lcd.o \
./Core/Src/User/Peripheral/LCD/logo_160_80.o \
./Core/Src/User/Peripheral/LCD/st7735.o \
./Core/Src/User/Peripheral/LCD/st7735_reg.o 

C_DEPS += \
./Core/Src/User/Peripheral/LCD/lcd.d \
./Core/Src/User/Peripheral/LCD/logo_160_80.d \
./Core/Src/User/Peripheral/LCD/st7735.d \
./Core/Src/User/Peripheral/LCD/st7735_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/Peripheral/LCD/%.o Core/Src/User/Peripheral/LCD/%.su Core/Src/User/Peripheral/LCD/%.cyclo: ../Core/Src/User/Peripheral/LCD/%.c Core/Src/User/Peripheral/LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/acados" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/acados_c" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v3/Core/Src/User/Lib/AcadosAPI/include/hpipm/include" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-Peripheral-2f-LCD

clean-Core-2f-Src-2f-User-2f-Peripheral-2f-LCD:
	-$(RM) ./Core/Src/User/Peripheral/LCD/lcd.cyclo ./Core/Src/User/Peripheral/LCD/lcd.d ./Core/Src/User/Peripheral/LCD/lcd.o ./Core/Src/User/Peripheral/LCD/lcd.su ./Core/Src/User/Peripheral/LCD/logo_160_80.cyclo ./Core/Src/User/Peripheral/LCD/logo_160_80.d ./Core/Src/User/Peripheral/LCD/logo_160_80.o ./Core/Src/User/Peripheral/LCD/logo_160_80.su ./Core/Src/User/Peripheral/LCD/st7735.cyclo ./Core/Src/User/Peripheral/LCD/st7735.d ./Core/Src/User/Peripheral/LCD/st7735.o ./Core/Src/User/Peripheral/LCD/st7735.su ./Core/Src/User/Peripheral/LCD/st7735_reg.cyclo ./Core/Src/User/Peripheral/LCD/st7735_reg.d ./Core/Src/User/Peripheral/LCD/st7735_reg.o ./Core/Src/User/Peripheral/LCD/st7735_reg.su

.PHONY: clean-Core-2f-Src-2f-User-2f-Peripheral-2f-LCD

