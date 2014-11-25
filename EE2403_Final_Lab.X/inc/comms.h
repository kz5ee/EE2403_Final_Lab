/* 
 * File:   comms.h
 * Author: Mike
 *
 * Created on November 8, 2014, 11:37 AM
 */

#ifndef COMMS_H
#define	COMMS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <p24Hxxxx.h>
#include <Generic.h>
#include <uart.h>
#include <spi.h>
#include <pps.h>

typedef enum
{
    ACCEL//,
  //  EEPROM,
  //  COMPASS
}eDevices;

//<editor-fold defaultstate="collapsed" desc="UART Configuration">
#define TRIS_U1TX       (TRISBbits.TRISB15 = 0)
#define TRIS_U1RX       (TRISBbits.TRISB14 = 1)
#define MAP_U1TX        (PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP15))
#define MAP_U1RX        (PPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP14))

#define TRIS_U2TX       (TRISBbits.TRISB8 = 0)
#define TRIS_U2RX       (TRISBbits.TRISB10 = 1)
#define MAP_U2TX        (PPSOutput(OUT_FN_PPS_U2TX, OUT_PIN_PPS_RP8))
#define MAP_U2RX        (PPSInput(IN_FN_PPS_U2RX, IN_PIN_PPS_RP10))

#define __FOSC_ 80000000
#define __FTCY_ (__FOSC_/2)

extern void UART1_Config(void);

#define __U1BAUD_ 9600L //<--- Desired Baud rate UART1 CHANGE THIS
#define __BAUDUART1_ ((__FTCY_/(16*__U1BAUD_))-1)

#ifdef _U2RXIF

#define __U2BAUD_ 2400L //Desired baud rate UART2 CHANGE THIS
#define __BAUDUART2_ ((__FTCY_/(16*__U2BAUD_))-1)

extern void UART2_Config(void);

#endif
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="SPI Configuration">
#define MAP_SCLK PPSOutput(OUT_FN_PPS_SCK1, OUT_PIN_PPS_RP8)//CLK
#define MAP_MOSI PPSOutput(OUT_FN_PPS_SDO1, OUT_PIN_PPS_RP7)//MOSI
#define MAP_MISO PPSInput(IN_FN_PPS_SDI1, IN_PIN_PPS_RP6)   //MISO

#define TRIS_SCLK TRISBbits.TRISB8 = 0;//Clk
#define TRIS_MOSI TRISBbits.TRISB7 = 0;//MOSI
#define TRIS_MISO TRISBbits.TRISB6 = 1;//MISO

extern void Setup_SPI1(void);
extern void Send_SPI(BYTE * Data,int Len,eDevices Device);

//</editor-fold>


#ifdef	__cplusplus
}
#endif

#endif	/* COMMS_H */

