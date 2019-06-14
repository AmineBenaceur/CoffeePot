/*
 * My_CofeePot_Main.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: amine.benaceur
 */


#include <sys/platform.h>
#include "adi_initialize.h"
#include <stdio.h>
//#include "../MockDevices/CoffeePot_SimulatorFunctions2018.h"
//#include "CofeePot_Assignment1_main.h"
#include "MyCoffeePotFunction.h"
#include "Sim_CoffeePot_SimulatorStructures2018.h"
#include "Sim_CoffeePot_Functions2018.h"
//#include "HeaterControl_ASM.asm"
#include "My_ASM_Functions.h"
#include <stdio.h>
#define MAX_SECONDS  300
#define MAX_WATER_LEVEL 600
#define MAX_TEMPERATURE 100
#define NUM_COFFEE_POTS 2
#define Design_PLAN1
#define DESIGN_PLAN2
#define EVEN_LATER
#define FINAL_CONTROL
//#define LATER

void My_CoffeePot_Main( void ){
	unsigned long int secondsCounter;
	unsigned long int CP1HEAT = 0.86*MAX_TEMPERATURE;
	unsigned long int CP2HEAT = 86; //0.85*MAX_TEMPERATURE;
	unsigned long int CP1WATER = .43*MAX_WATER_LEVEL;
	unsigned long int CP2WATER = .43*MAX_WATER_LEVEL;

//#ifdef Design_PLAN1
#ifdef DESIGN_PLAN2
	ShowNameProcessorUsed();

	Init_CoffeePotSimulation(NUM_COFFEE_POTS);

// TODO : ADJUST VIRTUAL MEMORY LOADER DESCRIPTION FILE (ldf) -- TO SIMULATE ADD THE VIRTUAL COFFEE POTS TO PC -- ELSE ADD_COFFEEPOTTOSYSTEM...() WILL CRASJ
#if 1
	COFFEEPOT_DEVICE *pMyCP1 = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT1, "Amine's Example ");
	COFFEEPOT_DEVICE *pMyCP2 = Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT2, "SMITH's Example ");
#endif
	My_init_CoffeePot(pMyCP1);
	My_init_CoffeePot(pMyCP2);

	My_Activate_LED_Control(pMyCP1);
	My_Activate_LED_Control(pMyCP2);
	#if 0
		bool continueDomonstrate_LEDControl = true;
		secondsCounter = 0;

		while(continueDomonstrate_LEDControl){
			My_Demo_LEDControl_CPP(pMyCP1);
			if (++secondsCounter >= MAX_SECONDS) continueDomonstrate_LEDControl = false;
		}
		printf("DESIGN_PLAN1 -- FINISHED \n \n");
	#endif
#endif
		#ifdef LATER
		My_Activate_HeaterControl(pMyCP1);
			bool continueDemonstrate_LEDcontrol_ASM = true;
			while(continueDemonstrate_LEDcontrol_ASM){
				//HeaterControl_ASM(pMyCP1,CP1HEAT);
				if(++secondsCounter >= MAX_SECONDS) continueDemonstrate_LEDcontrol_ASM = false;
			}
			printf("LATER -- FINISHED \n \n");
		#endif

		#ifdef EVEN_LATER
			#if 0
			My_Activate_WaterControl(pMyCP1);
			My_Activate_WaterControl(pMyCP2);
			bool continueDemonstrate_WaterControl = true;
			secondsCounter = 0;

			while( continueDemonstrate_WaterControl ){
				My_fillCoffeePotToWaterLevel(pMyCP1, CP1WATER );
				My_fillCoffeePotToWaterLevel(pMyCP2, CP2WATER );
				if (++secondsCounter >= MAX_SECONDS) continueDemonstrate_WaterControl = false;
			}
			#endif

			#if 0
			My_Activate_HeaterControl(pMyCP1);
			My_Activate_HeaterControl(pMyCP2);
			bool continueDemonstrate_HeaterControl = true;
			secondsCounter = 0;

				while( continueDemonstrate_HeaterControl ){
					My_HeatWaterToTemperature(pMyCP1,CP1HEAT);
					My_HeatWaterToTemperature(pMyCP2,CP2HEAT);
					if (++secondsCounter >= MAX_SECONDS) continueDemonstrate_HeaterControl = false;
				}
				printf(" EVEN LATER -- FINISHED \n \n");
			#endif
		#endif

		#ifdef FINAL_CONTROL

				My_Activate_WaterControl(pMyCP1);
				My_Activate_HeaterControl(pMyCP1);
				My_Activate_WaterControl(pMyCP2);
				My_Activate_HeaterControl(pMyCP2);
				bool continueDemonstrate_Both_Temp_Water = true;
				while (continueDemonstrate_Both_Temp_Water){
					Control_Both_Temp_Water( pMyCP1,CP1WATER,CP1HEAT);
					Control_Both_Temp_Water( pMyCP2,CP2WATER,CP2HEAT);
					if (++secondsCounter <= MAX_SECONDS) continueDemonstrate_Both_Temp_Water = false;
				}
				printf("FINAL CONTROL -- FINISHED \n \n");
		#endif

}
