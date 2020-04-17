//Standard C libraries:
#include <stdio.h>
#include <stdlib.h>

//Microchip's specialized library
#include <xc.h>

//A library to use the uc32 board
#include "BOARD.h"
#include "roach.h"

#define ONE_SECOND 500000

/*
 * 
 */
int main(void)
{
    //These calls configure the Pic32 so that it can interact with the Roach hardware
    BOARD_Init();
    Roach_Init();

    printf("Welcome to Dead Recokining!  This program was compiled on %s as %s.\r\n", __DATE__, __TIME__);

    //Initialization code here:

    int i;


    while (1) {
        //Continuous code here:

        //Sample one-second loop
        i = 0;
        while (i < ONE_SECOND) {
            i++;
        }
        Roach_LEDSSet(0x924);

        //identical one-second loop
        for (i = 0; i < ONE_SECOND; i++) {
            //do nothing
        }
        Roach_LEDSSet(0x492);

        //yet another identical one-second loop?
        i=0;
        while (1) {
            i++;
            if (i >= ONE_SECOND) {
                break;
            }
        }
        Roach_LEDSSet(0x249);
    };

    return (EXIT_SUCCESS);
}

