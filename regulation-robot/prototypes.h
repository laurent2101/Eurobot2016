
#ifndef PROTOTYPES_H
#define PROTOTYPES_H

void config();

void initEQep1();
void initEQep2();

void initEPwm1(unsigned int period);
void initEPwm2(unsigned int period);

__interrupt void spiInterrupt(void);
void initSPI();

#endif
