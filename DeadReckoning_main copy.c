//Standard C libraries:
#include <stdio.h>
#include <stdlib.h>

//Microchip's specialized library
#include <xc.h>

//A library to use the uc32 board
#include "BOARD.h"
#include "roach.h"

#define ONE_SECOND 500000
#define DRIVE_TIME 31000
#define TURN_LEFT_TIME 6000
#define TURN_RIGHT_TIME 10000
int i;
/*
 * 
 */
void fwd(){
    for (i = 0; i < DRIVE_TIME; i++) {
            Roach_LeftMtrSpeed(100);
            Roach_RightMtrSpeed(100);
        }
        Roach_LeftMtrSpeed(0);
        Roach_RightMtrSpeed(0);
        
        for (i = 0; i < ONE_SECOND; i++) {
            
        }
}

void right(){
     for (i = 0; i <  TURN_LEFT_TIME; i++) {
            Roach_LeftMtrSpeed(100);
            Roach_RightMtrSpeed(-100);
        }
        Roach_LeftMtrSpeed(0);
        Roach_RightMtrSpeed(0);
        
        for (i = 0; i < ONE_SECOND; i++) {
            
        }
}

void left(){
    for (i = 0; i <  TURN_RIGHT_TIME; i++) {
            Roach_LeftMtrSpeed(-100);
            Roach_RightMtrSpeed(100);
        }
        Roach_LeftMtrSpeed(0);
        Roach_RightMtrSpeed(0);
}

int main(void)
{
    //These calls configure the Pic32 so that it can interact with the Roach hardware
    BOARD_Init();
    Roach_Init();

    printf("Welcome to Dead Recokining!  This program was compiled on %s as %s.\r\n", __DATE__, __TIME__);

    //Initialization code here:

    


    while (1) {
        //Continuous code here:

        //Sample one-second loop
        i = 0;

        //identical one-second loop
        fwd();
        left();
        fwd();
        left();
        fwd();
        left();
        fwd();
        fwd();
        left();
        left();
        fwd();
        right();
        
        
       
        
        
        

        //yet another identical one-second loop?
    };

    return (EXIT_SUCCESS);
}

