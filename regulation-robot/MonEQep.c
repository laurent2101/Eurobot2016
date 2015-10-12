
/***************************************************************************/
/******************************* EQep functions ****************************/
/***************************************************************************/

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "prototypes.h"

void initEQep1()
{
	EALLOW;

	GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up on GPIO20 (EQEP2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pull-up on GPIO21 (EQEP2B)
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;   // Enable pull-up on GPIO23 (EQEP2I)

    GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;   // Sync to SYSCLKOUT GPIO24 (EQEP2A)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0;   // Sync to SYSCLKOUT GPIO25 (EQEP2B)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 0;   // Sync to SYSCLKOUT GPIO26 (EQEP2I)

    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 2;   // Configure GPIO24 as EQEP2A
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 2;   // Configure GPIO25 as EQEP2B
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 2;   // Configure GPIO26 as EQEP2I

    EQep1Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep1Regs.QEPCTL.bit.WDE=0;
    EQep1Regs.QEPCTL.bit.QCLM = 1;
    EQep1Regs.QEPCTL.bit.UTE =1;
    EQep1Regs.QPOSMAX = 0xFFFFFFFE;
    EQep1Regs.QCAPCTL.bit.UPPS = 0b0011;
    EQep1Regs.QCAPCTL.bit.CCPS = 0b111;

	EQep1Regs.QEPCTL.bit.QPEN=1; 		// QEP enable
	EQep1Regs.QCAPCTL.bit.CEN=1;

	EDIS;
}

void initEQep2()
{
	EALLOW;

	GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;   // Enable pull-up on GPIO20 (EQEP2A)
    GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0;   // Enable pull-up on GPIO21 (EQEP2B)
    GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;   // Enable pull-up on GPIO23 (EQEP2I)

    GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 0;   // Sync to SYSCLKOUT GPIO24 (EQEP2A)
    GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 0;   // Sync to SYSCLKOUT GPIO25 (EQEP2B)
    GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 0;   // Sync to SYSCLKOUT GPIO26 (EQEP2I)

    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 2;   // Configure GPIO24 as EQEP2A
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 2;   // Configure GPIO25 as EQEP2B
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 2;   // Configure GPIO26 as EQEP2I

    EQep2Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep2Regs.QEPCTL.bit.WDE=0;
    EQep2Regs.QEPCTL.bit.QCLM = 1;
    EQep2Regs.QEPCTL.bit.UTE =1;
    EQep2Regs.QPOSMAX = 0xFFFFFFFE;
    EQep2Regs.QCAPCTL.bit.UPPS = 0b0011;
    EQep2Regs.QCAPCTL.bit.CCPS = 0b111;

	EQep2Regs.QEPCTL.bit.QPEN=1; 		// QEP enable
	EQep2Regs.QCAPCTL.bit.CEN=1;

	EDIS;
}
