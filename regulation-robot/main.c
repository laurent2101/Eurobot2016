/*
 * main.c
 */

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "DCL.h"
#include "prototypes.h"
#include "defines.h"

float vitesse;
float ek;

flags_spi flagsSPI;
unsigned int sentComBuff[MAX_WORD_COM];
unsigned int recievedComBuff[MAX_WORD_COM];

union float_spi test;
union float_spi test2;

int main(void)
{

	config();

	while(1)
	{
		if(flagsSPI.courrier)
		{
			test.b[1] = recievedComBuff[1];
			test.b[0] = recievedComBuff[2];
			test2.b[1] = recievedComBuff[3];
			test2.b[0] = recievedComBuff[4];

			flagsSPI.courrier = 0;
		}
	}

/*	PI pi1 = PI_DEFAULTS;
	vitesse = 0;
	pi1.Kp = 0.02;
	pi1.Ki = 0.005;

	while(1){
    	if(EQep2Regs.QEPSTS.bit.COEF==1){EQep2Regs.QEPSTS.bit.COEF=1;}
    	if(EQep2Regs.QEPSTS.bit.CDEF==1){EQep2Regs.QEPSTS.bit.CDEF=1;}

    	if(EQep2Regs.QEPSTS.bit.UPEVNT==1){
    		vitesse = 8/(((float) EQep2Regs.QCPRDLAT)/700000)/2000;
    		EQep2Regs.QEPSTS.bit.UPEVNT=1;
    	}
    	ek = DCL_runPI(&pi1, 40, vitesse );
    	 EPwm2Regs.CMPA.half.CMPA = ek*30000;
    	//MonMoteur.setDutyCycle();
    }
*/
	return 0;
}
