#include <p24Hxxxx.h>

void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;
    
    
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