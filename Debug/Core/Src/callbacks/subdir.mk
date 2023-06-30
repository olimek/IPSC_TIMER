################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/callbacks/callbacks.c \
../Core/Src/callbacks/par_callbacks.c \
../Core/Src/callbacks/train_callbacks.c 

OBJS += \
./Core/Src/callbacks/callbacks.o \
./Core/Src/callbacks/par_callbacks.o \
./Core/Src/callbacks/train_callbacks.o 

C_DEPS += \
./Core/Src/callbacks/callbacks.d \
./Core/Src/callbacks/par_callbacks.d \
./Core/Src/callbacks/train_callbacks.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/callbacks/%.o Core/Src/callbacks/%.su: ../Core/Src/callbacks/%.c Core/Src/callbacks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DHSE_VALUE=16000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DHSI_VALUE=8000000 -DLSI_VALUE=40000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -DINSTRUCTION_CACHE_ENABLE=0 -DDATA_CACHE_ENABLE=0 -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-callbacks

clean-Core-2f-Src-2f-callbacks:
	-$(RM) ./Core/Src/callbacks/callbacks.d ./Core/Src/callbacks/callbacks.o ./Core/Src/callbacks/callbacks.su ./Core/Src/callbacks/par_callbacks.d ./Core/Src/callbacks/par_callbacks.o ./Core/Src/callbacks/par_callbacks.su ./Core/Src/callbacks/train_callbacks.d ./Core/Src/callbacks/train_callbacks.o ./Core/Src/callbacks/train_callbacks.su

.PHONY: clean-Core-2f-Src-2f-callbacks

