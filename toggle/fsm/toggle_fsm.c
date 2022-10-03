#include "toggle_fsm.h"

void toggle_fsm(int *state, int input, int *output)
{
    switch (*state)
    {
    case TOGGLE_OFF_STATE:
    {
        if (input == 1)
        {
            *state = TOGGLE_ON_STATE;
            *output = 1;
        }
        else
        {
            *state = TOGGLE_OFF_STATE;
            *output = 0;
        }
        break;
    }
    case TOGGLE_ON_STATE:
    {
        if (input == 1)
        {
            *state = TOGGLE_OFF_STATE;
            *output = 0;
        }
        else
        {
            *state = TOGGLE_ON_STATE;
            *output = 1;
        }

        break;
    }

    default:
        break;
    }
}