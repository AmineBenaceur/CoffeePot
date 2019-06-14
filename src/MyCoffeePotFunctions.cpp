/*
 * My_CoffeePotFunctions.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: amine.benaceur
 */

#include "MyCoffeePotFunction.h"
#include "Sim_CoffeePot_SimulatorStructures2018.h"
#include <stdio.h>
#define SHOW_FUNCTION_STUB_INFORMATION true

void ShowNameProcessorUsed(void){
	#if defined(_ADSPBF533_)
		char processor[] = "_ADSPBF533_";
	#else
		char processor[] = "_ADSPBF609_";
	#endif
	printf("Amine's Coffee pot running on %s  System \n\n" , processor);
}

inline void Show_Function_Stub_Information(char *functionNameInformation){
	if (SHOW_FUNCTION_STUB_INFORMATION)
		printf("%s \n", functionNameInformation );

}
void My_init_CoffeePot(void){
	printf("Initializing coffee pot.... \n");
}
void My_init_CoffeePot(COFFEEPOT_DEVICE *cpPtr){
		Show_Function_Stub_Information("void My_init_CoffeePot(COFFEEPOT_DEVICE *cpPtr)");
		FastForward_OneSimulationTIC(cpPtr);
		OpenChannel_CoffeePot(cpPtr);
		//TODO: set POWER_ON and INIT bit in coffeePot control register;
	#if 1
		unsigned short int currentCtrReg = ReadControlRegister_CPP(cpPtr);
		unsigned short int newControlRegisterValue = INIT_STAY_POWERED_ON_BIT;
		WriteControlRegister_CPP(cpPtr, newControlRegisterValue);

	#else
		cpPtr->controlRegister = INIT_STAY_POWERED_ON_BIT;
	#endif


		CloseChannel_CauseSimulationTIC(cpPtr);

		//in a loop read control register and use bitwise and to see if device ready -- exit when ready
		bool done = false;
		while(!done){
		//	printf("Waiting to for INIT_STAY_POWERED_ON_BIT... \n ");

			if ( (ReadControlRegister_CPP(cpPtr)&DEVICE_READY_BIT_RO)   == DEVICE_READY_BIT_RO){
				done = true;

		}
			FastForward_OneSimulationTIC(cpPtr);
		}
}
void My_init_CoffeePotSimulation(void) {
	printf("Here init_CoffeePotSimulation\n ");
}

void My_Activate_LED_Control(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("My_Activate_LED_Control(COFFEEPOT_DEVICE *pCoffeePot)");

	//TODO: turn on LED_POWER bit in control reigster without turning off others
	//build activate-LED-cONTROL_asm USING ACTIVATE_l_ed_control cpp() code as design idea
	//***first parameter pointer *pcoffeepot comes in R0
	//OpenChannel_CoffeePot(pCoffeePot);
	pCoffeePot-> controlRegister |= LED_POWER_ENABLE_BIT ;
	CloseChannel_CauseSimulationTIC(pCoffeePot);
	FastForward_OneSimulationTIC(pCoffeePot);
}
void My_Activate_LED_Control(void){
	printf("Activating LED control\n ");
}
void My_Demo_LEDControl_CPP(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("My_Demo_LEDControl_CPP");
	unsigned short int ctrl = ReadControlRegister_CPP(pCoffeePot);
	unsigned short int led_12_mask = (LED1_CONTROL_BIT|LED2_CONTROL_BIT );
	unsigned short int LED_CTRL = (led_12_mask&ctrl);
	unsigned short int LED1_OFFmask = 0xefff;
	unsigned short int LED2_OFFmask = 0xdfff;
	unsigned short int newCTRL;
	switch(LED_CTRL){
	case 0: //turn on led 1
		//printf(" CASE0 : ----TUNRING ON LED 1");
		 newCTRL = (ctrl|LED1_CONTROL_BIT);
		 pCoffeePot->controlRegister = newCTRL;
		 break;
	case LED1_CONTROL_BIT: // turnoff led1 turn on led2
		newCTRL = ctrl&LED1_OFFmask;
		newCTRL |= LED2_CONTROL_BIT;
		pCoffeePot->controlRegister = newCTRL;
		//printf("CASE1: ----TUNRING ON LED 2");
		break;
	case LED2_CONTROL_BIT:
		newCTRL= ctrl&LED2_OFFmask;
		newCTRL|=LED1_CONTROL_BIT;
		pCoffeePot->controlRegister = newCTRL;
		//printf("CASE1: ----TUNRING ON LED 1");
		break;

	}
	FastForward_OneSimulationTIC(pCoffeePot);

}
void My_Demo_LEDControl_CPP(void){
	printf("Demo LED control \n ");
}

//		------------ EVEN LATER --------------
void My_Activate_WaterControl(COFFEEPOT_DEVICE *pCoffeePot ){
	Show_Function_Stub_Information("My_Activate_WaterControl(COFFEEPOT_DEVICE *pCoffeePot )");
	pCoffeePot->controlRegister |= WATER_POWER_ENABLE_BIT;
	FastForward_OneSimulationTIC(pCoffeePot);
}
void My_fillCoffeePotToWaterLevel(COFFEEPOT_DEVICE *pCoffeePot,unsigned short int levelRequired){
	Show_Function_Stub_Information("My_fillCoffeePotToWaterLevel(COFFEEPOT_DEVICE *pCoffeePot,unsigned short int levelRequired)");
	unsigned short int flowRate = 20;
	unsigned short int currentLevel = CurrentWaterLevel_CPP(pCoffeePot);
	unsigned short int diff =0;
	if(levelRequired > currentLevel)
		 diff = (levelRequired - currentLevel);

	if (diff < 5 ){
		flowRate =0;
	}else if( diff < 17 ){
		printf("diff < 17 \n");
		flowRate= 10;
	}else if ( diff < 35 ){
		printf("diff < 25 \n");
		flowRate = 30 ;
	}else if ( diff < 65 ){
		printf("diff < 50 \n");
		flowRate = 50;
	}else if(diff < 100 ){
		printf("diff < 100 \n");
		flowRate = 100;
	}else{
		flowRate = 150;
	}

	/*if ( 50 < diff <= 75 ){
		flowRate = 10 ;
	}
	if( 75 < diff <= 125)
		flowRate = 15 ;
	if( 125 < diff <= 175)
		flowRate =20;
	if( 175 < diff <= 200 )
		flowRate = 25 ;
	if(  200 < diff <= 300 )
		flowRate = 30;
	if (diff > 300 )
		flowRate = 35;*/

	pCoffeePot->waterInFlowRegister = flowRate;
	FastForward_OneSimulationTIC(pCoffeePot);


}

void My_Activate_HeaterControl(COFFEEPOT_DEVICE *pCoffeePot){
	Show_Function_Stub_Information("My_Activate_HeaterControl(COFFEEPOT_DEVICE *pCoffeePot)");
	pCoffeePot->controlRegister |= HEATER_POWER_ENABLE_BIT;
	FastForward_OneSimulationTIC(pCoffeePot);

}

void My_HeatWaterToTemperature(COFFEEPOT_DEVICE *pCoffeePot, unsigned short int heatRequired){
	unsigned short int diff = 0;
	unsigned short int currentTemp = CurrentTemperature_CPP(pCoffeePot);

	if(currentTemp < heatRequired)
		diff = heatRequired - currentTemp;

	unsigned short int heat = 40;
	unsigned short int heaterBoost = 15;

	if (heatRequired > currentTemp)
		diff = heatRequired - currentTemp;

	if ( diff < 2 ){
		heaterBoost = 0;
		heat = 0;
		//printf("----- 0 < diff <= 10      ");
	}else if( diff <= 10 ){
		heaterBoost = 5;
		heat = 25;
		//printf("----- 0 < diff <= 10      ");
	}else if(  diff <= 40 ){
		heaterBoost = 10;
		heat = 100;
		//printf("----- 10 < diff < 40      ");
	}else{
		//printf("----- diff >= 40          ");
		heaterBoost = 15;
		heat = 150;
		}

	pCoffeePot->heaterBoostRegister = heaterBoost;
	pCoffeePot->heaterRegister = heat;

//	printf(" \n heat: %d    heaterboost: %d    \n", heat, heaterBoost);

	FastForward_OneSimulationTIC(pCoffeePot);
}

void Control_Both_Temp_Water( COFFEEPOT_DEVICE *pCoffeePot,unsigned short int levelRequired , unsigned short int heatRequired){
	Show_Function_Stub_Information("Control_Both_Temp_Water");
	My_HeatWaterToTemperature(pCoffeePot,heatRequired);
	int waterDefecit = CurrentWaterLevel_CPP(pCoffeePot) - levelRequired;
	int refillRounds =1;
	if (waterDefecit > 50 ){
		refillRounds =2;
	}else if (waterDefecit > 100 ){
		refillRounds =3;
	}
	for (int i = 0; i < refillRounds ; i ++ )
		if (heatRequired < (CurrentTemperature_CPP(pCoffeePot)) ){
//			pCoffeePot->heaterBoostRegister=0;
//			pCoffeePot->heaterRegister = 0;
			printf("hi");
			FastForward_OneSimulationTIC(pCoffeePot);
			My_fillCoffeePotToWaterLevel(pCoffeePot, levelRequired);

		}
	My_HeatWaterToTemperature(pCoffeePot,heatRequired);
	My_fillCoffeePotToWaterLevel(pCoffeePot, levelRequired);


}

// assignment #2 starts here

void initCT(){
	//*pTCNTL = TMPWR ;
}

//
//void stopCT(){
//
//}
//
//void start_CT_Interrupts(){
//
//}
//
//
//void stop_CT_Interrupts(){
//
//}

