################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CoffeePot_Simulator_main.cpp \
../src/LocalCoffeePotFunctions.cpp \
../src/MyCoffeePotFunctions.cpp \
../src/My_CoffeePot_Main.cpp 

SRC_OBJS += \
./src/CoffeePot_Simulator_main.doj \
./src/LocalCoffeePotFunctions.doj \
./src/MyCoffeePotFunctions.doj \
./src/My_CoffeePot_Main.doj 

CPP_DEPS += \
./src/CoffeePot_Simulator_main.d \
./src/LocalCoffeePotFunctions.d \
./src/MyCoffeePotFunctions.d \
./src/My_CoffeePot_Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/CoffeePot_Simulator_main.doj: ../src/CoffeePot_Simulator_main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeePot_Assignment1_BF533" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-80ec83b661d2b3cd6b142e30f1d1508f.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/CoffeePot_Simulator_main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LocalCoffeePotFunctions.doj: ../src/LocalCoffeePotFunctions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeePot_Assignment1_BF533" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-80ec83b661d2b3cd6b142e30f1d1508f.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/LocalCoffeePotFunctions.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MyCoffeePotFunctions.doj: ../src/MyCoffeePotFunctions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeePot_Assignment1_BF533" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-80ec83b661d2b3cd6b142e30f1d1508f.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/MyCoffeePotFunctions.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/My_CoffeePot_Main.doj: ../src/My_CoffeePot_Main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore Blackfin C/C++ Compiler'
	ccblkfn -c -file-attr ProjectName="CoffeePot_Assignment1_BF533" -proc ADSP-BF533 -flags-compiler --no_wrap_diagnostics -si-revision any -g -DCORE0 -D_DEBUG @includes-80ec83b661d2b3cd6b142e30f1d1508f.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -decls-strong -cplbs -gnu-style-dependencies -MD -Mo "src/My_CoffeePot_Main.d" -c++ -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


