#include <p24Hxxxx.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../inc/globals.h"

volatile BYTE_VAL Flags;
char command[13];
volatile unsigned int Index;

void InitGlobals(void)
{

    Flags.Val = 0;
    Index = 0;
    memset(command, '\0', sizeof(command));

    return;
}

void Process_CMD(void)
{
    int i;

    for(i=0;i<(strlen(command)); i++)
    {
        command[i] = tolower(command[i]); //make lower case
    }

    if(strcmp(command,"report level") == 0)
    {
        if(FLOW_LEVEL == 1)
        {
            printf("Level is at 1 foot.\n");
        }
        else if(FLOW_LEVEL == 1)
        {
            printf("Level is at 2 feet.\n");
        }
        else if(FLOW_LEVEL == 1)
        {
            printf("Level is at 3 feet.\n");
        }
        else if(FLOW_LEVEL == 1)
        {
            printf("Level is at 4 feet.\n");
        }
        else
        {
            printf("Tank is empty.\n");
        }

    }
    if(strcmp(command,"pump on") == 0)
    {
        LATBbits.LATB5 = 1;
    }
    if(strcmp(command,"pump off") == 0)
    {
        LATBbits.LATB5 = 0;
    }

    COMMANDRCD = 0;
    return;
}
