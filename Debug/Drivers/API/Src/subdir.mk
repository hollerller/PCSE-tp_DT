################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_LCDhandler.c \
../Drivers/API/Src/API_controlFSM.c \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/API_i2c.c \
../Drivers/API/Src/API_uart.c \
../Drivers/API/Src/driver_BME280.c \
../Drivers/API/Src/driver_LCD.c 

OBJS += \
./Drivers/API/Src/API_LCDhandler.o \
./Drivers/API/Src/API_controlFSM.o \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/API_i2c.o \
./Drivers/API/Src/API_uart.o \
./Drivers/API/Src/driver_BME280.o \
./Drivers/API/Src/driver_LCD.o 

C_DEPS += \
./Drivers/API/Src/API_LCDhandler.d \
./Drivers/API/Src/API_controlFSM.d \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/API_i2c.d \
./Drivers/API/Src/API_uart.d \
./Drivers/API/Src/driver_BME280.d \
./Drivers/API/Src/driver_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/hollerller/Documents/UBA/CESE/PCSE/PCSE-tp_DT/Drivers/API/Inc" -I"/Users/hollerller/Documents/UBA/CESE/PCSE/PCSE-tp_DT/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_LCDhandler.cyclo ./Drivers/API/Src/API_LCDhandler.d ./Drivers/API/Src/API_LCDhandler.o ./Drivers/API/Src/API_LCDhandler.su ./Drivers/API/Src/API_controlFSM.cyclo ./Drivers/API/Src/API_controlFSM.d ./Drivers/API/Src/API_controlFSM.o ./Drivers/API/Src/API_controlFSM.su ./Drivers/API/Src/API_delay.cyclo ./Drivers/API/Src/API_delay.d ./Drivers/API/Src/API_delay.o ./Drivers/API/Src/API_delay.su ./Drivers/API/Src/API_i2c.cyclo ./Drivers/API/Src/API_i2c.d ./Drivers/API/Src/API_i2c.o ./Drivers/API/Src/API_i2c.su ./Drivers/API/Src/API_uart.cyclo ./Drivers/API/Src/API_uart.d ./Drivers/API/Src/API_uart.o ./Drivers/API/Src/API_uart.su ./Drivers/API/Src/driver_BME280.cyclo ./Drivers/API/Src/driver_BME280.d ./Drivers/API/Src/driver_BME280.o ./Drivers/API/Src/driver_BME280.su ./Drivers/API/Src/driver_LCD.cyclo ./Drivers/API/Src/driver_LCD.d ./Drivers/API/Src/driver_LCD.o ./Drivers/API/Src/driver_LCD.su

.PHONY: clean-Drivers-2f-API-2f-Src

