/*
 * CoffeePotSimulatorFunctions2016.h
 *
 *  Created on: Sep 6, 2016
 *      Author: smithmr
 */

#ifndef COFFEEPOT_SIMULATORFUNCTIONS2018_H_
#define COFFEEPOT_SIMULATORFUNCTIONS2018_H_

#include "Sim_CoffeePot_SimulatorStructures2018.h" // Change Include Path to use < >
void Init_CoffeePotSimulation(int numCoffeePots);

enum COFFEEPOT_ID {COFFEEPOT1 = 1, COFFEEPOT2, COFFEEPOT3, COFFEEPOT4};
COFFEEPOT_DEVICE *Add_CoffeePotToSystem_PlugAndPlay(COFFEEPOT_ID coffeepotNumber, char coffeePotName[]);

void OpenChannel_CoffeePot(COFFEEPOT_DEVICE *pCoffeePot);
void CloseChannel_CauseSimulationTIC(COFFEEPOT_DEVICE *pCoffeePot);

unsigned short int WriteControlRegister_CPP(COFFEEPOT_DEVICE *baseAddress, unsigned short int newControlRegisterValue);
unsigned short int ReadControlRegister_CPP(COFFEEPOT_DEVICE *baseAddress);
unsigned short int CurrentWaterLevel_CPP  (COFFEEPOT_DEVICE *baseAddress);
unsigned short int CurrentTemperature_CPP (COFFEEPOT_DEVICE *baseAddress);

void FastForward_OneSimulationTIC(COFFEEPOT_DEVICE *baseAddress);

void TurnOffNotification(bool turnOffNotification);

#if 0
//#include <MOCKDEVICES2016\CoffeePot_SimulatorStructures2016.h"


enum WHICHDISPLAY {USE_TEXT_GUI = 1, USE_IMPROVED_ECLIPSE_GRAPHICS_GUI = 2, USE_EXTERNAL_DISPLAY = 4};  // Make all display modes available simultaneously


void Init_CoffeePotSimulation(int numCoffeePots, WHICHDISPLAY whichDisplay);
// void UpdateSimulationDisplay(void);



// void Remove_CoffeePotFromSystem(COFFEEPOT_DEVICE *baseAddress);
void ShowDeviceRegisterValues(COFFEEPOT_DEVICE *baseAddress);

void NetworkTimingFudge_USE_CCES_GUI_Delay(void);
#endif

#endif /* COFFEEPOT_SIMULATORFUNCTIONS2018_H_ */
