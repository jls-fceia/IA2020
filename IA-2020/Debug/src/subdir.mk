################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IA2020_LEDS.cpp \
../src/Led.cpp \
../src/LedOnOff.cpp \
../src/LedPWM.cpp \
../src/Microcontrolador.cpp \
../src/PWM.cpp 

OBJS += \
./src/IA2020_LEDS.o \
./src/Led.o \
./src/LedOnOff.o \
./src/LedPWM.o \
./src/Microcontrolador.o \
./src/PWM.o 

CPP_DEPS += \
./src/IA2020_LEDS.d \
./src/Led.d \
./src/LedOnOff.d \
./src/LedPWM.d \
./src/Microcontrolador.d \
./src/PWM.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


