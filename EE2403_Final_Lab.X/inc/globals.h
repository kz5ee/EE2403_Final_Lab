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

#define FLOW_LEVEL(state)       Flags.bits.b0 = (state);
#define FLOW_MED_LEVEL(state)   Flags.bits.b1 = (state);
#define FMED_HI_LEVEL(state)    Flags.bits.b2 = (state);
#define FHI_LEVEL(state)        Flags.bits.b3 = (state);
#define COMMANDRCD(state)       Flags.bits.b4 = (state);

    extern void InitGlobals(void);

    extern unsigned char command[13];


#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALS_H */

