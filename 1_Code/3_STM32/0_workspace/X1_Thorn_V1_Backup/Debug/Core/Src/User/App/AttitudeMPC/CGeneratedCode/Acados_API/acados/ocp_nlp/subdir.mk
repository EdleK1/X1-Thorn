################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgh.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgp.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_conl.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_external.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_ls.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_nls.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_ddp.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_cont.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_disc.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_fixed_step.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_funnel.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_merit_backtracking.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_common.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_convexify.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_glm.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_mirror.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_noreg.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project_reduc_hess.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_rti.c \
../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_with_feasible_qp.c 

OBJS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgh.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgp.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_conl.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_external.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_ls.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_nls.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_ddp.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_cont.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_disc.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_fixed_step.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_funnel.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_merit_backtracking.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_common.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_convexify.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_glm.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_mirror.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_noreg.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project_reduc_hess.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_rti.o \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_with_feasible_qp.o 

C_DEPS += \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgh.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgp.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_conl.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_external.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_ls.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_nls.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_ddp.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_cont.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_disc.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_fixed_step.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_funnel.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_merit_backtracking.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_common.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_convexify.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_glm.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_mirror.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_noreg.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project_reduc_hess.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_rti.d \
./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_with_feasible_qp.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/%.o Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/%.su Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/%.cyclo: ../Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/%.c Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/blasfeo/include" -I"C:/Users/marcv/Desktop/X1-Thorn/1_Code/3_STM32/0_workspace/X1_Thorn_V1/Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/hpipm/include" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-ocp_nlp

clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-ocp_nlp:
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgh.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgh.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgh.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgh.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgp.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgp.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgp.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_bgp.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_constraints_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_conl.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_conl.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_conl.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_conl.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_external.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_external.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_external.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_external.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_ls.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_ls.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_ls.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_ls.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_nls.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_nls.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_nls.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_cost_nls.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_ddp.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_ddp.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_ddp.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_ddp.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_cont.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_cont.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_cont.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_cont.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_disc.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_disc.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_disc.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_dynamics_disc.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_fixed_step.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_fixed_step.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_fixed_step.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_fixed_step.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_funnel.cyclo
	-$(RM) ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_funnel.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_funnel.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_funnel.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_merit_backtracking.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_merit_backtracking.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_merit_backtracking.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_globalization_merit_backtracking.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_common.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_common.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_common.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_common.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_convexify.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_convexify.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_convexify.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_convexify.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_glm.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_glm.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_glm.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_glm.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_mirror.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_mirror.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_mirror.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_mirror.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_noreg.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_noreg.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_noreg.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_noreg.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project_reduc_hess.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project_reduc_hess.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project_reduc_hess.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_reg_project_reduc_hess.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_rti.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_rti.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_rti.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_rti.su ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_with_feasible_qp.cyclo ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_with_feasible_qp.d ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_with_feasible_qp.o ./Core/Src/User/App/AttitudeMPC/CGeneratedCode/Acados_API/acados/ocp_nlp/ocp_nlp_sqp_with_feasible_qp.su

.PHONY: clean-Core-2f-Src-2f-User-2f-App-2f-AttitudeMPC-2f-CGeneratedCode-2f-Acados_API-2f-acados-2f-ocp_nlp

