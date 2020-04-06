################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Computer.cpp \
../src/ComputerFactory.cpp \
../src/Game.cpp \
../src/History.cpp \
../src/MLComputer.cpp \
../src/Player.cpp \
../src/RandomComputer.cpp \
../src/main.cpp 

OBJS += \
./src/Computer.o \
./src/ComputerFactory.o \
./src/Game.o \
./src/History.o \
./src/MLComputer.o \
./src/Player.o \
./src/RandomComputer.o \
./src/main.o 

CPP_DEPS += \
./src/Computer.d \
./src/ComputerFactory.d \
./src/Game.d \
./src/History.d \
./src/MLComputer.d \
./src/Player.d \
./src/RandomComputer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


