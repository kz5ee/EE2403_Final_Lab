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

    extern volatile BYTE_VAL Flags;

#define LOW_LEVEL(state)       Flags.bits.b0 = (state);
#define LOW_MED_LEVEL(state)   Flags.bits.b1 = (state);
#define MED_HI_LEVEL(state)    Flags.bits.b2 = (state);
#define HI_LEVEL(state)        Flags.bits.b3 = (state);

    extern void InitGlobals(void);

    extern unsigned char command[13];


#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

