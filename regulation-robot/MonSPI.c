/*
 * MonSPI.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: damien
 */

#include "prototypes.h"
#include "defines.h"
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

extern flags_spi flagsSPI;
extern unsigned int sentComBuff[MAX_WORD_COM];
extern unsigned int recievedComBuff[MAX_WORD_COM];

void initSPI()
{

	flagsSPI.Counter = 0;
	flagsSPI.enAck = 0;
	flagsSPI.enTransfert = 0;
	flagsSPI.recepEmit = 0;
	flagsSPI.courrier = 0;

	InitSpiaGpio();

/*	InitCpuTimers();   // For this example, only initialize the Cpu Timers
	ConfigCpuTimer(&CpuTimer0, 90, 100000);
	CpuTimer0Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
*/
	EALLOW;
	// Initialize SPI module
	SpiaRegs.SPICCR.bit.SPILBK = 0;				// Loop-back mode disabled
	SpiaRegs.SPICCR.bit.SPICHAR = 0xF;			// Mots de 8 bits
	SpiaRegs.SPICCR.bit.CLKPOLARITY = 0;
	SpiaRegs.SPICCR.bit.SPILBK = 0;				// Loop-back mode disabled

	SpiaRegs.SPICTL.bit.CLK_PHASE = 0;
	SpiaRegs.SPICTL.bit.MASTER_SLAVE = 0;		// Slave mode
	SpiaRegs.SPICTL.bit.TALK = 1;				// Talk enabled
	SpiaRegs.SPICTL.bit.SPIINTENA = 1;			// Interrupts Enabled

	PieVectTable.SPIRXINTA = &spiInterrupt;

	SpiaRegs.SPICCR.bit.SPISWRESET = 1;

	IER |= M_INT6;
	PieCtrlRegs.PIEIER6.bit.INTx1 = 1;
	PieCtrlRegs.PIEIER6.bit.INTx2 = 1;     // Enable PIE Group 6, INT 2

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

	// Enable global Interrupts and higher priority real-time debug events:
	EINT;   									// Enable Global interrupt INTM
	ERTM;   									// Enable Global realtime interrupt DBGM
	EDIS;
}

__interrupt void spiInterrupt(void){

    if(!flagsSPI.enAck && !flagsSPI.courrier)
    {
		if(flagsSPI.enTransfert)
		{
			if(flagsSPI.Counter != 0)			// Pas le chks
			{
				recievedComBuff[flagsSPI.memPointer] = SpiaRegs.SPIRXBUF;
				flagsSPI.chks += SpiaRegs.SPIRXBUF;
				flagsSPI.Counter--;
			}
			else								// Le chks
			{
				if((flagsSPI.chks + 1) == SpiaRegs.SPIRXBUF)		// CHKS = somme + 1 (pour éviter un ACK en ne transmettant que des 0's)
				{
					SpiaRegs.SPITXBUF = CODE_ACK;
					flagsSPI.courrier = 1;
				}
				else
				{
					SpiaRegs.SPITXBUF = CODE_NACK;
				}
				flagsSPI.enAck = 1;
			}

			flagsSPI.memPointer++;
		}
		else
		{
			flagsSPI.memPointer = 0;

			if((SpiaRegs.SPIRXBUF >> 15) == 0) // Si 1er bit à 0 : Réception
			{
				flagsSPI.Counter = (SpiaRegs.SPIRXBUF % 0x100);					// On extrait la longueur du message
				flagsSPI.enTransfert = 1;
				recievedComBuff[flagsSPI.memPointer++] = SpiaRegs.SPIRXBUF;
				flagsSPI.chks = SpiaRegs.SPIRXBUF;
			}
			else		// Si 1er bit à 1 : Transmission
			{


			}
		}
    }
    else
    {
    	flagsSPI.enAck = 0;
    	flagsSPI.enTransfert = 0;
    	SpiaRegs.SPIRXBUF;
    }


    SpiaRegs.SPIFFRX.bit.RXFFINTCLR = 1;  // Clear Interrupt flag
    SpiaRegs.SPISTS.bit.OVERRUN_FLAG = 1;
    SpiaRegs.SPISTS.bit.INT_FLAG = 1;  // Clear Interrupt flag
    SpiaRegs.SPISTS.bit.BUFFULL_FLAG = 1;  // Clear Interrupt flag
    PieCtrlRegs.PIEACK.all|=0x20;       // Issue PIE ack

}

__interrupt void spiWDT(void)
{



}
