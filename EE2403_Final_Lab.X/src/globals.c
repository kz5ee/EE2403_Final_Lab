#include <p24Hxxxx.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../inc/globals.h"
#include <libpic30.h>


volatile BYTE_VAL Flags;
char command[13];
volatile unsigned int Index;
_TANKLEVEL TankLevel;

void InitGlobals(void)
{
    TankLevel = EMPTY;
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

    printf("OK\r\n");
    //printf("Command Entered:  %s\r\n", command);
    //printf("%d\r\n", strncmp(command,"report level", 12));
    
    if(strncmp(command,"report level", 12) == 0)
    {
        if(TankLevel == LOW)
        {
            printf("Level is at 1 foot.\n");
        }
        else if(TankLevel == LOWMED)
        {
            printf("Level is at 2 feet.\n");
        }
        else if(TankLevel == MEDHI)
        {
            printf("Level is at 3 feet.\n");
        }
        else if(TankLevel == HI)
        {
            printf("Level is at 4 feet.\n");
        }
        else
        {
            printf("Tank is empty.\n");
        }

    }
    
    
    if(strncmp(command,"pump on", 7) == 0)
    {
        LATBbits.LATB5 = 1;
        printf("Turning pump on.\r\n");
    }
    else if(strncmp(command,"pump off", 7) == 0)
    {
        LATBbits.LATB5 = 0;
        printf("Turning pump off.\r\n");
    }
    else if(strncmp(command,"pump state", 10) == 0)
    {
        printf("Pump State:  %d\r\n", PORTBbits.RB5);
    }
    else
    {
        printf("Unrecognized Command\r\n");
    }

    COMMANDRCD = 0;
    return;
}

void ReportLevelChanged(void)
{
    LEVELCHANGED = 0;
    switch (TankLevel)
    {
        case EMPTY:
            printf("Tank is empty.\n");
            break;
        case LOW:
            printf("Level is at 1 foot.\n");
            break;
        case LOWMED:
            printf("Level is at 2 feet.\n");
            break;
        case MEDHI:
            printf("Level is at 3 feet.\n");
            break;
        case HI:
            printf("Level is at 4 feet.\n");
            break;
        default:
            printf("Level is unknown.\n");
            break;
    }

    if( TankLevel == HI && PORTBbits.RB5 != 1)
    {
        printf("Turning pump on.\r\n");
        PUMP(1)
    }
    else if (TankLevel == LOWMED && PORTBbits.RB5 == 1)
    {
        printf("Turning pump off.\r\n");
        PUMP(0)
    }


    return;
}

void SystemsTest(void)
{
    int i;
    printf("Systems Test in progress\n");

    printf("Checking Inputs and Outputs");

    for(i=0; i<=4; i++)
    {
        __delay_ms(1000);
        printf(".");
        if(i==4)
        { printf("OK\r\n"); }
    }

    __delay_ms(1500);

    printf("Testing pump");
    PUMP(1)
    for(i=0;i<=9;i++)
    {
        __delay_ms(1000);
        printf(".");
        if(i==9)
        {
            printf("OK\r\n");
            PUMP(0)
        }
    }

    printf("Systems Test complete.\r\nMay the Schwartz be with you.\r\n");



    return;
}