################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
semaforotest.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
semaforotest.list \

OBJCOPY_HEX += \
semaforotest.hex \

OBJCOPY_BIN += \
semaforotest.bin \


# All Target
all: semaforotest.elf secondary-outputs

# Tool invocations
semaforotest.elf: $(OBJS) $(USER_OBJS) C:\Users\Matheus\ Cunha\Desktop\Engenharia\ Eletronica\2022.1\microcontroladores2\semaforo_2\STM32F103T4UX_FLASH.ld
	arm-none-eabi-gcc -o "semaforotest.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Matheus Cunha\Desktop\Engenharia Eletronica\2022.1\microcontroladores2\semaforo_2\STM32F103T4UX_FLASH.ld" --specs=nosys.specs -Wl,-Map="semaforotest.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

semaforotest.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "semaforotest.list"
	@echo 'Finished building: $@'
	@echo ' '

semaforotest.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "semaforotest.hex"
	@echo 'Finished building: $@'
	@echo ' '

semaforotest.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "semaforotest.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
