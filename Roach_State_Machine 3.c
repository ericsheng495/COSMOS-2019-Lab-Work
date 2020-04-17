#include <stdio.h>

#include "Roach_Events.h"
#include "roach.h"
#include "Roach_Top_Level_SM.h"
#include "timers.h"

//a list of states that this SM uses:

enum {
    //your states here
    Moving_Forward,
    Arc_Left,
    Arc_Right,
    Turn_Left,
    Turn_Right,
    Timed_Move_Forward,
    Right_Corner_Turn,
    Left_Corner_Turn,
    
};

int current_state;

/* This function initializes the roach state machine.
 * At a minimum, this requires setting the first state.
 * Also, execute any actions associated with initializing the SM
 * (that is, the actions on the arrow from the black dot in the SM diagram)*/
// visual studio code
void Initialize_NavigateObstacleField_StateMachine(void)
{
    current_state = Moving_Forward;
    Roach_LeftMtrSpeed(100);
    Roach_RightMtrSpeed(100);
};

/*
 * @briefThis function feeds newly detected events to the roach state machine.
 * @param event:  The most recently detected event*/

Event Run_Roach_NavigateObstacleField_StateMachine(Event event)
{
    switch (current_state) {
        case Moving_Forward:
            printf("Current state = MOVING FORWARD\r\n");
            if(event == STATE_TRANSITION){
                Roach_LeftMtrSpeed(100);
                Roach_RightMtrSpeed(100);
            }
            if(event == FRONT_LEFT_BUMP_PRESSED){
                TRANSITION_TO(Arc_Left);
                Roach_LeftMtrSpeed(100);
                Roach_RightMtrSpeed(-100);
            }
            if(event == FRONT_RIGHT_BUMP_PRESSED){
                TRANSITION_TO(Arc_Right);
                Roach_LeftMtrSpeed(-100);
                Roach_RightMtrSpeed(100);
                
            }
            break;
            
        case Arc_Left:
            printf("Current state = Arc Left\r\n");
            if(event == STATE_TRANSITION){
                //   Roach_LeftMtrSpeed(-100);
                //   Roach_RightMtrSpeed(-100);
            }
            if (event == FRONT_LEFT_BUMP_PRESSED && event == FRONT_RIGHT_BUMP_PRESSED ){
                TRANSITION_TO(Left_Corner_Turn);
            }
            if (event == FRONT_LEFT_BUMP_RELEASED){
                TRANSITION_TO(Turn_Left);
                Roach_LeftMtrSpeed(-100);
                Roach_RightMtrSpeed(100);
            }
            break;
            
        case Arc_Right:
            printf("Current state = Arc Left\r\n");
            if(event == STATE_TRANSITION){
                //    Roach_LeftMtrSpeed(-100);
                //    Roach_RightMtrSpeed(-100);
            }
            if(event == FRONT_LEFT_BUMP_PRESSED && event == FRONT_RIGHT_BUMP_PRESSED) {
                TRANSITION_TO(Right_Corner_Turn);
                
            }
            if(event == FRONT_RIGHT_BUMP_RELEASED) {
                TRANSITION_TO(Turn_Right);
                Roach_LeftMtrSpeed(100);
                Roach_RightMtrSpeed(-100);
            }
            
            break;
            
        case Turn_Left:
            printf("Current state = Turn_Left \r\n");
            if(event == STATE_TRANSITION){
                // Roach_LeftMtrSpeed(100);
                // Roach_RightMtrSpeed(-100);
            }
            if(event == FRONT_LEFT_BUMP_RELEASED){
                TRANSITION_TO(Arc_Left);
                Roach_LeftMtrSpeed(100);
                Roach_RightMtrSpeed(-100);
            }
            break;
            
        case Turn_Right:
            printf("Current state = Turn_Right \r\n");
            if(event == STATE_TRANSITION){
                // Roach_LeftMtrSpeed(-100);
                // Roach_RightMtrSpeed(100);
                
            }
            if(event == FRONT_RIGHT_BUMP_PRESSED){
                TRANSITION_TO(Arc_Right);
                // Roach_LeftMtrSpeed(-100);
                // Roach_RightMtrSpeed(100);
            }
            break;
            
        case Right_Corner_Turn;
            printf("Current state = Right_Corner_Turn \r\n");
            if(event == FRONT_LEFT_BUMP_RELEASED){
                TRANSITION_TO(Arc_Right);
            }
            if (event == STATE_TRANSITION) {
                //stuff
            }
            break;
            
        case Left_Corner_Turn;
            printf("Current state = Left_Corner_Turn \r\n");
            if(FRONT_RIGHT_BUMP_RELEASED){
                TRANSITION_TO(Arc_Left);
            }
            if (event == STATE_TRANSITION) {
                //stuff
            }
            break;
            
        case Timed_Move_Forward:
            printf("Current state = Timed_Move_Forward \r\n");
            if(event == STATE_TRANSITION){
                
            }
            break;
            
    }
    
    return event;
}









