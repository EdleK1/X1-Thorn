################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/User/Test/TestOdometry/subdir.mk
-include Core/Src/User/Test/TestGroundCommands/subdir.mk
-include Core/Src/User/Test/TestESP32/subdir.mk
-include Core/Src/User/Test/TestAttitudeMPC/subdir.mk
-include Core/Src/User/Test/subdir.mk
-include Core/Src/User/Peripheral/Servo/subdir.mk
-include Core/Src/User/Peripheral/LCD/subdir.mk
-include Core/Src/User/Peripheral/ESP32/subdir.mk
-include Core/Src/User/Peripheral/BNO055/subdir.mk
-include Core/Src/User/Lib/subdir.mk
-include Core/Src/User/App/Odometry/subdir.mk
-include Core/Src/User/App/MainApp/subdir.mk
-include Core/Src/User/App/GroundCommands/subdir.mk
-include Core/Src/User/App/Control/subdir.mk
-include Core/Src/User/App/AttitudeMPC/CGeneratedCode/Aircraft_Attitude_model/subdir.mk
-include Core/Src/User/App/AttitudeMPC/CGeneratedCode/subdir.mk
-include Core/Src/User/App/AttitudeMPC/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := X1_Thorn_v2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
X1_Thorn_v2.elf \

MAP_FILES += \
X1_Thorn_v2.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
X1_Thorn_v2.list \


# All Target
all: main-build

# Main-build Target
main-build: X1_Thorn_v2.elf secondary-outputs

# Tool invocations
X1_Thorn_v2.elf X1_Thorn_v2.map: $(OBJS) $(USER_OBJS) C:\Users\marcv\Desktop\X1-Thorn\1_Code\3_STM32\0_workspace\X1_Thorn_v2\STM32H743VITX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "X1_Thorn_v2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\marcv\Desktop\X1-Thorn\1_Code\3_STM32\0_workspace\X1_Thorn_v2\STM32H743VITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="X1_Thorn_v2.map" -Wl,--gc-sections -static -L"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_v2/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/lib" -u_printf_float --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

X1_Thorn_v2.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "X1_Thorn_v2.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) X1_Thorn_v2.elf X1_Thorn_v2.list X1_Thorn_v2.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
