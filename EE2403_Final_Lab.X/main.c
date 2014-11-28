/* 
 * File:   main.c
 * Author: Mike Peters
 *
 * Created on November 5, 2014, 12:11 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p24Hxxxx.h>
#include "inc/comms.h"
#include "inc/globals.h"
#include "inc/chip_setup.h"

/*
 * Words of Power
 */

_FBS(BWRP_WRPROTECT_OFF & BSS_NO_BOOT_CODE & RBS_NO_BOOT_RAM )
_FSS(SWRP_WRPROTECT_OFF &  SSS_NO_SEC_CODE  & RSS_NO_SEC_RAM )
_FGS(GWRP_OFF & GCP_OFF)
_FOSCSEL( FNOSC_FRC & IESO_OFF)
_FOSC(OSCIOFNC_ON & POSCMD_NONE & FCKSM_CSECMD)
_FWDT( WDTPOST_PS8192 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF)
_FPOR( FPWRT_PWR128)
_FICD( ICS_PGD1 & JTAGEN_OFF)


int main(int argc, char** argv) {
    void Ludacris_Speed(void); //Make chip go fast
    Ludacris_Speed();
    InitGlobals();
    //Setup_GO();
    UART1_Config();
    IO_Setup();
    Timer1_Setup();
    printf("Ready\n");
    
    
    while(1)
    {
        //Nop();
        if(COMMANDRCD == 1)
        {
            printf("Processing Command\r\n");
            Process_CMD();
        }
        if (LEVELCHANGED)
        {
            ReportLevelChanged();
        }



    }

    return (EXIT_SUCCESS);
}

inline void Ludacris_Speed()
{
    //This code from Microchip Family Ref. 39 Oscillator(Part III)
    //Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBD = 41; // M = 43
    CLKDIVbits.PLLPOST = 0; // N2 = 2
    CLKDIVbits.PLLPRE = 0; // N1 = 2
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while(OSCCONbits.LOCK != 1) {};
    return;
}