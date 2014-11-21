#include <p24Hxxxx.h>
#include "../inc/globals.h"

void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;
    T1CONbits.TON = 0;

    if(PORTBbits.RB6 == 1)
    { FHI_LEVEL(1) }
    if(PORTBbits.RB7 == 1)
    { FMED_HI_LEVEL(1) }
    if(PORTBbits.RB8 == 1)
    { FLOW_MED_LEVEL(1) }
    if(PORTBbits.RB9 == 1)
    {FLOW_LEVEL(1) }
    
    return;
}


//void __attribute__((interrupt,auto_psv)) _ISR _U2RXInterrupt(void)
//{
//    //char received;
//    _U2RXIF = 0;
//
//    return;
//}

void __attribute__((interrupt,auto_psv)) _ISR _U1RXInterrupt(void)
{
    //char received;
    _U1RXIF = 0;

    
    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _CNInterrupt(void)
{
    _CNIF = 0;

    T1CONbits.TON = 1;

    return;
}