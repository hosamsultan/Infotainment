################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buttons.c \
../Gpio.c \
../Interrupt.c \
../KYP_prog.c \
../LCD.c \
../Led.c \
../Sos.c \
../Timer.c \
../del.c \
../main.c 

OBJS += \
./Buttons.o \
./Gpio.o \
./Interrupt.o \
./KYP_prog.o \
./LCD.o \
./Led.o \
./Sos.o \
./Timer.o \
./del.o \
./main.o 

C_DEPS += \
./Buttons.d \
./Gpio.d \
./Interrupt.d \
./KYP_prog.d \
./LCD.d \
./Led.d \
./Sos.d \
./Timer.d \
./del.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


