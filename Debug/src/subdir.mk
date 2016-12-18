################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Camera.cpp \
../src/Cube.cpp \
../src/Game.cpp \
../src/Game_obj.cpp \
../src/Launcher.cpp \
../src/Model.cpp \
../src/OpenGL_tes1.cpp \
../src/Plane.cpp \
../src/Player.cpp \
../src/Shader_Loader.cpp \
../src/World.cpp 

OBJS += \
./src/Camera.o \
./src/Cube.o \
./src/Game.o \
./src/Game_obj.o \
./src/Launcher.o \
./src/Model.o \
./src/OpenGL_tes1.o \
./src/Plane.o \
./src/Player.o \
./src/Shader_Loader.o \
./src/World.o 

CPP_DEPS += \
./src/Camera.d \
./src/Cube.d \
./src/Game.d \
./src/Game_obj.d \
./src/Launcher.d \
./src/Model.d \
./src/OpenGL_tes1.d \
./src/Plane.d \
./src/Player.d \
./src/Shader_Loader.d \
./src/World.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


