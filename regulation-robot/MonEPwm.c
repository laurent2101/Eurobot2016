
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "prototypes.h"


void initEPwm1(unsigned int period){
	// TODO Auto-generated constructor stub

	InitEPwm1Gpio();

	EALLOW;

	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;			// Ne synchronise pas tant que pas configurÃ©

	EPwm1Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;	    // Load the TBPRD register immediately without using a shadow register.
													// A write or read to the TBPRD register directly accesses the active register.

	EPwm1Regs.TBPHS.all = 0;						// If TBCTL[PHSEN] = 0, then the synchronization event is ignored and the
													// time-base counter is not loaded with the phase.

	EPwm1Regs.TBCTR = 0;							// Set the current time-based value

	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;		// Counter Mode (up, down, freeze,
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;		    // Do not load the time-base counter (TBCTR) from the time-base phase register (TBPHS) when en  EPWMxSYNCI input signal occurs
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;	// Disable Synchronization Output Select. These bits select the source of the EPWMxSYNCO signal.

	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		// High speed time-base clock prescale bits - Div by 1
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;			// Time-base clock prescale bits

	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;	// Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
	EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;	// Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;		// Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
	EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;		// Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

	EPwm1Regs.AQCTLA.bit.ZRO = AQ_CLEAR;            // PWMA force to low when counter equals zero
	EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;				// PWMA force to high when counter equals CMPA
	EPwm1Regs.AQCTLB.bit.CAU = AQ_CLEAR;			// PWMB force to low when counter equals CMPA
	EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;				// PWMB force to high when counter equals CMPA

	EPwm1Regs.HRCNFG.all = 0x0;

	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;

	EPwm1Regs.TBPRD = period-1;

	EDIS;

}

void initEPwm2(unsigned int period)
{

	InitEPwm2Gpio();

	EALLOW;

	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;			// Ne synchronise pas tant que pas configurÃ©

	EPwm2Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;	    // Load the TBPRD register immediately without using a shadow register.
													// A write or read to the TBPRD register directly accesses the active register.

	EPwm2Regs.TBPHS.all = 0;						// If TBCTL[PHSEN] = 0, then the synchronization event is ignored and the
													// time-base counter is not loaded with the phase.

	EPwm2Regs.TBCTR = 0;							// Set the current time-based value

	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;		// Counter Mode (up, down, freeze,
	EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;		    // Do not load the time-base counter (TBCTR) from the time-base phase register (TBPHS) when en  EPWMxSYNCI input signal occurs
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;	// Disable Synchronization Output Select. These bits select the source of the EPWMxSYNCO signal.

	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		// High speed time-base clock prescale bits - Div by 1
	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;			// Time-base clock prescale bits

	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;	// Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
	EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;	// Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;		// Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
	EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;		// Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

	EPwm2Regs.AQCTLA.bit.ZRO = AQ_CLEAR;            // PWMA force to low when counter equals zero
	EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;				// PWMA force to high when counter equals CMPA
	EPwm2Regs.AQCTLB.bit.CAU = AQ_CLEAR;			// PWMB force to low when counter equals CMPA
	EPwm2Regs.AQCTLB.bit.ZRO = AQ_SET;				// PWMB force to high when counter equals CMPA

	EPwm2Regs.HRCNFG.all = 0x0;

	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;

	EPwm2Regs.TBPRD = period-1;

	EDIS;
}

