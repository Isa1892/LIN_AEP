################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application/task.c" \

C_SRCS += \
../Sources/Application/task.c \

OBJS += \
./Sources/Application/task_c.obj \

OBJS_QUOTED += \
"./Sources/Application/task_c.obj" \

C_DEPS += \
./Sources/Application/task_c.d \

OBJS_OS_FORMAT += \
./Sources/Application/task_c.obj \

C_DEPS_QUOTED += \
"./Sources/Application/task_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application/task_c.obj: ../Sources/Application/task.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Application/task.args" -o "Sources/Application/task_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Application/%.d: ../Sources/Application/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


