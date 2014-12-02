#include <p24Hxxxx.h>
#include <stdio.h>
#include "../inc/globals.h"

static int debounce = 0; //If a level is set, we want to make sure
                         //it has actually changed.

void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;
    //U1TXREG = 0x27;
    T1CONbits.TON = 0;


    if(TankLevel != EMPTY && CHANGECONFIRM != 1)
    { debounce++; T1CONbits.TON = 1; /*printf("%d\n",debounce);*/}

    

    if(debounce == 100 && LEVELCHANGED != 1)
    { CHANGECONFIRM = 1; debounce = 0; T1CONbits.TON = 0; }

    if (CHANGECONFIRM == 1 || TankLevel == EMPTY)
    {
        if(PORTBbits.RB6 == 1)
        { TankLevel = HI; }
        if(PORTBbits.RB7 == 1)
        { TankLevel = MEDHI; }
        if(PORTBbits.RB8 == 1)
        { TankLevel = LOWMED; }
        if(PORTBbits.RB9 == 1)
        { TankLevel = LOW; }
        if(PORTBbits.RB6==0 && PORTBbits.RB7==0 && PORTBbits.RB8==0 && PORTBbits.RB9==0)
        { TankLevel = EMPTY; }

        LEVELCHANGED = 1;
        CHANGECONFIRM = 0;
    }
    
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
    //U1TXREG=0x26;
    _U1RXIF = 0;
    char received;
    received = U1RXREG;

    command[Index] = received;
    U1TXREG = received;
    Index++;

    if(received == 0x0d)
    {
        U1TXREG = 0x0d;
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        U1TXREG = 0x0a;
        command[Index + 1] = '\0';
        Index = 0;
        COMMANDRCD = 1;
    }

    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _CNInterrupt(void)
{
    _CNIF = 0;

    T1CONbits.TON = 1;

    return;
}