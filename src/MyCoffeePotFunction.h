/*
 * MyCoffeePotFunction.h
 *
 *  Created on: Nov 13, 2018
 *      Author: amine.benaceur
 */

#ifndef MYCOFFEEPOTFUNCTION_H_
#define MYCOFFEEPOTFUNCTION_H_

#include <stdio.h>

#include "Sim_CoffeePot_Functions2018.h"
//void Init_CoffeePot_Smith(void);
//void Demonstrate_LEDControl_Smith_CPP(void);
//extern "C" void Demonstate_LEDControl_Smith_ASM(void);

//DESIGN_PLAN1
void ShowNameProcessorUsed(void);
void My_init_CoffeePotSimulation(void);
void My_init_CoffeePot(COFFEEPOT_DEVICE *ptr);
void My_init_CoffeePot(void);
void My_Activate_LED_Control(void);
void My_Activate_LED_Control(COFFEEPOT_DEVICE *pCoffeePot);
void My_Demo_LEDControl_CPP(void);
void My_Demo_LEDControl_CPP(COFFEEPOT_DEVICE *pCoffeePot);
inline void Show_Function_Stub_Information(char *functionNameInformation);
//LATER

//EVEN LATER
void My_Activate_WaterControl(COFFEEPOT_DEVICE *pCoffeePot );
void My_fillCoffeePotToWaterLevel(COFFEEPOT_DEVICE *pCoffeePot,unsigned short int levelRequired);
void My_Activate_HeaterControl(COFFEEPOT_DEVICE *pCoffeePot);
void My_HeatWaterToTemperature(COFFEEPOT_DEVICE *pCoffeePot, unsigned short int heatRequired);

//Finally

void Control_Both_Temp_Water( COFFEEPOT_DEVICE *pCoffeePot,unsigned short int levelRequired , unsigned short int heatRequired);


#endif /* MYCOFFEEPOTFUNCTION_H_ */
