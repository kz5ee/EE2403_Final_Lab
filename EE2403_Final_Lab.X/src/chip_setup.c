
#include <p24Hxxxx.h>
#include <stdio.h>
#include <timer.h>
#include "../inc/chip_setup.h"
#include "../inc/comms.h"

void Setup_GO(void)
{
    UART1_Config();
    Timer1_Setup();
    IO_Setup();
    

    return;
}

inline void Timer1_Setup(void)
{
    OpenTimer1(
            T1_OFF &
            T1_IDLE_CON &
            T1_GATE_OFF &
            T1_PS_1_8 &
            T1_SYNC_EXT_OFF &
            T1_SOURCE_INT,
            50000); //for 10 ms.

    ConfigIntTimer1(
            T1_INT_PRIOR_3 &
            T1_INT_ON
                    );


    printf("Timer 1 setup\r\n");
    return;
}

void IO_Setup(void)
{
    _CNIE = 1;
    AD1PCFGL = 0xffff;

    //RB5 is output for relay.
    TRISBbits.TRISB5 = 0;

    //RB6-9 read the Reed switches.
    TRISBbits.TRISB6 = 1;
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB8 = 1;
    TRISBbits.TRISB9 = 1;

    CNEN2bits.CN21IE = 1;
    CNEN2bits.CN22IE = 1;
    CNEN2bits.CN23IE = 1;
    CNEN2bits.CN24IE = 1;

    printf("I/O Setup\r\n");

    return;
}