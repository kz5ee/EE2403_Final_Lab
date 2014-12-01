/* 
 * File:   globals.h
 * Author: Mike
 *
 * Created on November 18, 2014, 2:26 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <Generic.h>
#define FOSC        (80000000ULL)
#define FCY         (FOSC/2)

    extern volatile BYTE_VAL Flags;

#define FLOW_LEVEL       Flags.bits.b0
#define FLOW_MED_LEVEL   Flags.bits.b1
#define FMED_HI_LEVEL    Flags.bits.b2
#define FHI_LEVEL        Flags.bits.b3
#define COMMANDRCD       Flags.bits.b4
#define LEVELCHANGED     Flags.bits.b5

#define PUMP(state)      LATBbits.LATB5 = (state);

    extern void InitGlobals(void);
    extern void Process_CMD(void);
    extern void ReportLevelChanged(void);
    extern void SystemsTest(void);

    extern char command[13];
    extern volatile unsigned int Index;

//    typedef enum {
//        LEVELCHANGED=0,
//
//    };

    typedef enum {
        EMPTY =0,
                LOW,
                LOWMED,
                MEDHI,
                HI
    }_TANKLEVEL;

    extern _TANKLEVEL TankLevel;


#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

