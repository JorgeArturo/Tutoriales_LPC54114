################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_LPC54114_cm4.c 

OBJS += \
./device/system_LPC54114_cm4.o 

C_DEPS += \
./device/system_LPC54114_cm4.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC54114J256BD64 -DCPU_LPC54114J256BD64_cm4 -D__LPC5411X__ -DCORE_M4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\board" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\source" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\drivers" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\device" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\component\uart" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\utilities" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\component\serial_manager" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\component\lists" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\startup" -I"D:\HDD Files\MCUXpresso\LPC54114\Tutorial WS\Tutorial_3\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

