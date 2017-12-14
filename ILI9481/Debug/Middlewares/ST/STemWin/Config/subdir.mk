################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STemWin/Config/GUIConf.c \
../Middlewares/ST/STemWin/Config/LCDConf_FlexColor_ILI9481.c \
../Middlewares/ST/STemWin/Config/SIMConf.c 

OBJS += \
./Middlewares/ST/STemWin/Config/GUIConf.o \
./Middlewares/ST/STemWin/Config/LCDConf_FlexColor_ILI9481.o \
./Middlewares/ST/STemWin/Config/SIMConf.o 

C_DEPS += \
./Middlewares/ST/STemWin/Config/GUIConf.d \
./Middlewares/ST/STemWin/Config/LCDConf_FlexColor_ILI9481.d \
./Middlewares/ST/STemWin/Config/SIMConf.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STemWin/Config/%.o: ../Middlewares/ST/STemWin/Config/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Alex/workspace/ILI9481/Inc" -I"C:/Users/Alex/workspace/ILI9481/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Alex/workspace/ILI9481/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Alex/workspace/ILI9481/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Alex/workspace/ILI9481/Drivers/CMSIS/Include" -I"C:/Users/Alex/workspace/ILI9481/Utilities/Components/ili9481" -I"C:/Users/Alex/workspace/ILI9481/Middlewares/ST/STemWin/Config" -I"C:/Users/Alex/workspace/ILI9481/Middlewares/ST/STemWin/inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


