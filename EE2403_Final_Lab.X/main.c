/* 
 * File:   main.c
 * Author: Mike Peters
 *
 * Created on November 5, 2014, 12:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

#if defined (__PIC24F32KA302__)
#include <p24fxxxx.h>

//Words of Power
_FBS(BWRP_OFF & BSS_OFF)
_FGS(GWRP_OFF & GSS0_OFF)
_FOSCSEL(FNOSC_FRCPLL & IESO_OFF)
_FOSC(POSCMOD_HS & OSCIOFNC_OFF & FCKSM_CSECMD)
_FWDT(WDTPS_PS8192 & FWPSA_PR32 & WINDIS_OFF & FWDTEN_OFF )
_FICD(ICS_PGx1)


#endif

#if defined (__PIC24HJ128GP202__)
#include <p24Hxxxx.h>

#endif

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

