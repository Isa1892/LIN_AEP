################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Mal/Exceptions.c" \
"../Sources/Mal/Init_all_system.c" \
"../Sources/Mal/IntcInterrupts.c" \
"../Sources/Mal/STM_Timer.c" \
"../Sources/Mal/ivor_branch_table.c" \
"../Sources/Mal/kernel.c" \

C_SRCS += \
../Sources/Mal/Exceptions.c \
../Sources/Mal/Init_all_system.c \
../Sources/Mal/IntcInterrupts.c \
../Sources/Mal/STM_Timer.c \
../Sources/Mal/ivor_branch_table.c \
../Sources/Mal/kernel.c \

OBJS += \
./Sources/Mal/Exceptions_c.obj \
./Sources/Mal/Init_all_system_c.obj \
./Sources/Mal/IntcInterrupts_c.obj \
./Sources/Mal/STM_Timer_c.obj \
./Sources/Mal/ivor_branch_table_c.obj \
./Sources/Mal/kernel_c.obj \

OBJS_QUOTED += \
"./Sources/Mal/Exceptions_c.obj" \
"./Sources/Mal/Init_all_system_c.obj" \
"./Sources/Mal/IntcInterrupts_c.obj" \
"./Sources/Mal/STM_Timer_c.obj" \
"./Sources/Mal/ivor_branch_table_c.obj" \
"./Sources/Mal/kernel_c.obj" \

C_DEPS += \
./Sources/Mal/Exceptions_c.d \
./Sources/Mal/Init_all_system_c.d \
./Sources/Mal/IntcInterrupts_c.d \
./Sources/Mal/STM_Timer_c.d \
./Sources/Mal/ivor_branch_table_c.d \
./Sources/Mal/kernel_c.d \

OBJS_OS_FORMAT += \
./Sources/Mal/Exceptions_c.obj \
./Sources/Mal/Init_all_system_c.obj \
./Sources/Mal/IntcInterrupts_c.obj \
./Sources/Mal/STM_Timer_c.obj \
./Sources/Mal/ivor_branch_table_c.obj \
./Sources/Mal/kernel_c.obj \

C_DEPS_QUOTED += \
"./Sources/Mal/Exceptions_c.d" \
"./Sources/Mal/Init_all_system_c.d" \
"./Sources/Mal/IntcInterrupts_c.d" \
"./Sources/Mal/STM_Timer_c.d" \
"./Sources/Mal/ivor_branch_table_c.d" \
"./Sources/Mal/kernel_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Mal/Exceptions_c.obj: ../Sources/Mal/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Mal/Exceptions.args" -o "Sources/Mal/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Mal/%.d: ../Sources/Mal/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Mal/Init_all_system_c.obj: ../Sources/Mal/Init_all_system.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Mal/Init_all_system.args" -o "Sources/Mal/Init_all_system_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Mal/IntcInterrupts_c.obj: ../Sources/Mal/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Mal/IntcInterrupts.args" -o "Sources/Mal/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Mal/STM_Timer_c.obj: ../Sources/Mal/STM_Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Mal/STM_Timer.args" -o "Sources/Mal/STM_Timer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Mal/ivor_branch_table_c.obj: ../Sources/Mal/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Mal/ivor_branch_table.args" -o "Sources/Mal/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Mal/kernel_c.obj: ../Sources/Mal/kernel.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Mal/kernel.args" -o "Sources/Mal/kernel_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


