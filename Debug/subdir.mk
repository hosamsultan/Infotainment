################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buttons.c \
../Gpio.c \
../Interrupt.c \
../KeyPad.c \
../LCD.c \
../SOS_Scheduler.c \
../Timer.c \
../del.c \
../main.c 

OBJS += \
./Buttons.o \
./Gpio.o \
./Interrupt.o \
./KeyPad.o \
./LCD.o \
./SOS_Scheduler.o \
./Timer.o \
./del.o \
./main.o 

C_DEPS += \
./Buttons.d \
./Gpio.d \
./Interrupt.d \
./KeyPad.d \
./LCD.d \
./SOS_Scheduler.d \
./Timer.d \
./del.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


