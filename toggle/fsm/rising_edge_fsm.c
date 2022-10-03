#include "rising_edge_fsm.h"

void rising_edge_fsm(int *state, int input, int *output)
{
    switch (*state)
    {
    case LOW_STATE:
    {
        if (input == 1)
        {
            *state = EDGE_STATE;
            *output = 1;
        }
        else
        {
            *state = LOW_STATE;
            *output = 0;
        }
        break;
    }
    case EDGE_STATE:
    {
        if (input == 1)
        {
            *state = HIGH_STATE;
            *output = 0;
        }
        else
        {
            *state = LOW_STATE;
            *output = 0;
        }
        break;
    }
    case HIGH_STATE:
    {
        if (input == 1)
        {
            *state = HIGH_STATE;
            *output = 0;
        }
        else
        {
            *state = LOW_STATE;
            *output = 0;
        }
        break;
    }
    default:
        break;
    }
}