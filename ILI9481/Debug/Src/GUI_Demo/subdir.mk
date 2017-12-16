################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GUI_Demo/GUIDEMO.c \
../Src/GUI_Demo/GUIDEMO_AntialiasedText.c \
../Src/GUI_Demo/GUIDEMO_Automotive.c \
../Src/GUI_Demo/GUIDEMO_BarGraph.c \
../Src/GUI_Demo/GUIDEMO_Bitmap.c \
../Src/GUI_Demo/GUIDEMO_ColorBar.c \
../Src/GUI_Demo/GUIDEMO_Conf.c \
../Src/GUI_Demo/GUIDEMO_Cursor.c \
../Src/GUI_Demo/GUIDEMO_Fading.c \
../Src/GUI_Demo/GUIDEMO_Graph.c \
../Src/GUI_Demo/GUIDEMO_IconView.c \
../Src/GUI_Demo/GUIDEMO_ImageFlow.c \
../Src/GUI_Demo/GUIDEMO_Intro.c \
../Src/GUI_Demo/GUIDEMO_Listview.c \
../Src/GUI_Demo/GUIDEMO_RadialMenu.c \
../Src/GUI_Demo/GUIDEMO_Resource.c \
../Src/GUI_Demo/GUIDEMO_Skinning.c \
../Src/GUI_Demo/GUIDEMO_Speed.c \
../Src/GUI_Demo/GUIDEMO_Speedometer.c \
../Src/GUI_Demo/GUIDEMO_Start.c \
../Src/GUI_Demo/GUIDEMO_TransparentDialog.c \
../Src/GUI_Demo/GUIDEMO_Treeview.c \
../Src/GUI_Demo/GUIDEMO_VScreen.c \
../Src/GUI_Demo/GUIDEMO_WashingMachine.c \
../Src/GUI_Demo/GUIDEMO_ZoomAndRotate.c 

OBJS += \
./Src/GUI_Demo/GUIDEMO.o \
./Src/GUI_Demo/GUIDEMO_AntialiasedText.o \
./Src/GUI_Demo/GUIDEMO_Automotive.o \
./Src/GUI_Demo/GUIDEMO_BarGraph.o \
./Src/GUI_Demo/GUIDEMO_Bitmap.o \
./Src/GUI_Demo/GUIDEMO_ColorBar.o \
./Src/GUI_Demo/GUIDEMO_Conf.o \
./Src/GUI_Demo/GUIDEMO_Cursor.o \
./Src/GUI_Demo/GUIDEMO_Fading.o \
./Src/GUI_Demo/GUIDEMO_Graph.o \
./Src/GUI_Demo/GUIDEMO_IconView.o \
./Src/GUI_Demo/GUIDEMO_ImageFlow.o \
./Src/GUI_Demo/GUIDEMO_Intro.o \
./Src/GUI_Demo/GUIDEMO_Listview.o \
./Src/GUI_Demo/GUIDEMO_RadialMenu.o \
./Src/GUI_Demo/GUIDEMO_Resource.o \
./Src/GUI_Demo/GUIDEMO_Skinning.o \
./Src/GUI_Demo/GUIDEMO_Speed.o \
./Src/GUI_Demo/GUIDEMO_Speedometer.o \
./Src/GUI_Demo/GUIDEMO_Start.o \
./Src/GUI_Demo/GUIDEMO_TransparentDialog.o \
./Src/GUI_Demo/GUIDEMO_Treeview.o \
./Src/GUI_Demo/GUIDEMO_VScreen.o \
./Src/GUI_Demo/GUIDEMO_WashingMachine.o \
./Src/GUI_Demo/GUIDEMO_ZoomAndRotate.o 

C_DEPS += \
./Src/GUI_Demo/GUIDEMO.d \
./Src/GUI_Demo/GUIDEMO_AntialiasedText.d \
./Src/GUI_Demo/GUIDEMO_Automotive.d \
./Src/GUI_Demo/GUIDEMO_BarGraph.d \
./Src/GUI_Demo/GUIDEMO_Bitmap.d \
./Src/GUI_Demo/GUIDEMO_ColorBar.d \
./Src/GUI_Demo/GUIDEMO_Conf.d \
./Src/GUI_Demo/GUIDEMO_Cursor.d \
./Src/GUI_Demo/GUIDEMO_Fading.d \
./Src/GUI_Demo/GUIDEMO_Graph.d \
./Src/GUI_Demo/GUIDEMO_IconView.d \
./Src/GUI_Demo/GUIDEMO_ImageFlow.d \
./Src/GUI_Demo/GUIDEMO_Intro.d \
./Src/GUI_Demo/GUIDEMO_Listview.d \
./Src/GUI_Demo/GUIDEMO_RadialMenu.d \
./Src/GUI_Demo/GUIDEMO_Resource.d \
./Src/GUI_Demo/GUIDEMO_Skinning.d \
./Src/GUI_Demo/GUIDEMO_Speed.d \
./Src/GUI_Demo/GUIDEMO_Speedometer.d \
./Src/GUI_Demo/GUIDEMO_Start.d \
./Src/GUI_Demo/GUIDEMO_TransparentDialog.d \
./Src/GUI_Demo/GUIDEMO_Treeview.d \
./Src/GUI_Demo/GUIDEMO_VScreen.d \
./Src/GUI_Demo/GUIDEMO_WashingMachine.d \
./Src/GUI_Demo/GUIDEMO_ZoomAndRotate.d 


# Each subdirectory must supply rules for building sources it contributes
Src/GUI_Demo/%.o: ../Src/GUI_Demo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -I"/home/achin/git/ilihal/ILI9481/Inc" -I"/home/achin/git/ilihal/ILI9481/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/achin/git/ilihal/ILI9481/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/achin/git/ilihal/ILI9481/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/achin/git/ilihal/ILI9481/Drivers/CMSIS/Include" -I"/home/achin/git/ilihal/ILI9481/Utilities/Components/ili9481" -I"/home/achin/git/ilihal/ILI9481/Middlewares/ST/STemWin/Config" -I"/home/achin/git/ilihal/ILI9481/Middlewares/ST/STemWin/inc" -I/ILI9481/Src/GUI_Demo  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


