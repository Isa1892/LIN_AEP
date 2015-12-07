################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application/Slave2_LIN.c" \
"../Sources/Application/Slave2_actions.c" \
"../Sources/Application/task.c" \

C_SRCS += \
../Sources/Application/Slave2_LIN.c \
../Sources/Application/Slave2_actions.c \
../Sources/Application/task.c \

OBJS += \
./Sources/Application/Slave2_LIN_c.obj \
./Sources/Application/Slave2_actions_c.obj \
./Sources/Application/task_c.obj \

OBJS_QUOTED += \
"./Sources/Application/Slave2_LIN_c.obj" \
"./Sources/Application/Slave2_actions_c.obj" \
"./Sources/Application/task_c.obj" \

C_DEPS += \
./Sources/Application/Slave2_LIN_c.d \
./Sources/Application/Slave2_actions_c.d \
./Sources/Application/task_c.d \

OBJS_OS_FORMAT += \
./Sources/Application/Slave2_LIN_c.obj \
./Sources/Application/Slave2_actions_c.obj \
./Sources/Application/task_c.obj \

C_DEPS_QUOTED += \
"./Sources/Application/Slave2_LIN_c.d" \
"./Sources/Application/Slave2_actions_c.d" \
"./Sources/Application/task_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application/Slave2_LIN_c.obj: ../Sources/Application/Slave2_LIN.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Application/Slave2_LIN.args" -o "Sources/Application/Slave2_LIN_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Application/%.d: ../Sources/Application/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Application/Slave2_actions_c.obj: ../Sources/Application/Slave2_actions.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Application/Slave2_actions.args" -o "Sources/Application/Slave2_actions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Application/task_c.obj: ../Sources/Application/task.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Application/task.args" -o "Sources/Application/task_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


