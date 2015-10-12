/*
 * MiscFunctions.c
 *
 *  Created on: Oct 6, 2015
 *      Author: damien
 */

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "prototypes.h"
#include "defines.h"

void config()
{
	SysCtrlRegs.PLLSTS.bit.MCLKSTS = 0;

	InitSysCtrl();
	DINT;
	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	initEQep2();
	initEPwm2(30000);
	initSPI();
}
