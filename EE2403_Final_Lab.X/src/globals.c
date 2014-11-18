#include <p24Hxxxx.h>
#include <stdio.h>
#include <string.h>
#include "../inc/globals.h"

volatile BYTE_VAL Flags;
unsigned char command[13];

void InitGlobals(void)
{

    Flags.Val = 0;
    memset(command, '\0', sizeof(command));

    return;
}
