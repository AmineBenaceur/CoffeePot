/*****************************************************************************
 * CofeePot_Assignment1.cpp
 *****************************************************************************/

#include <sys/platform.h>
#include "adi_initialize.h"
//#include "../MockDevices/CoffeePot_SimulatorFunctions2018.h"
#include "CoffeePot_Simulator_Main.h"
#include <stdio.h>

void My_CoffeePot_Main(void);

/** 
 * If you want to use command program arguments, then place them in the following string. 
 */
char __argv_string[] = "";

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to 
	 * the project.
	 * @return zero on success 
	 */
	adi_initComponents();
	
	/* Begin adding your custom code here */

	My_CoffeePot_Main();

	return 0;
}

