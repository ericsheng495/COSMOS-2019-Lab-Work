/* 
 * File:   Hello_World_main.c
 * Author: AutonomousSystemsLab
 *
 * Created on July 5, 2019, 1:32 PM
 */

//Standard C libraries:
#include <stdio.h>
#include <stdlib.h>

//Microchip's specialized library
#include <xc.h>

//A library to use the uc32 board
#include "BOARD.h"
#include "roach.h"
#include "timers.h"



char timer0_Expired_EventFlag = 0;

int checkForTimer0Event()
{
    static previous_timer_state = TIMER_NOT_ACTIVE;
    char current_timer_state = TIMERS_IsTimerActive(0);
    
    if (previous_timer_state == TIMER_ACTIVE && 
            current_timer_state == TIMER_NOT_ACTIVE) {
        //then an event occurred!
            timer0_Expired_EventFlag = 1;
    }
    previous_timer_state = current_timer_state;
}

void ToggleLED_Service()
{
    Roach_LEDSSet(~Roach_LEDSGet());
    TIMERS_InitTimer(0, 1000);
}

int main(void)
{
    // <editor-fold defaultstate="collapsed" desc="//Initialization code (BOARD_Init(), etc)">


    //These calls configure the Pic32 so that it can interact with the Roach hardware
    BOARD_Init();
    Roach_Init();
    TIMERS_Init();

    //Initialization code here:
    printf("Welcome to Events and Services lab, compiled on %s %s\r\n", __TIME__, __DATE__);
    // </editor-fold>

    //first, setup the framework:
    TIMERS_InitTimer(0, 1000);

    while (1) {
        //continuous services (event checkers):
        checkForTimer0Event();

        //poll for events:
        if (timer0_Expired_EventFlag) {
            printf("EVENT:  TIMER0_EXPIRED\r\n");
            //clear event flag
            timer0_Expired_EventFlag = 0;
            //run service        
            ToggleLED_Service();
        }
    }

    return (EXIT_SUCCESS);
}

