#include "edge_fsm.h"

void edge_fsm(int *state, int input)
{
    switch (*state)
    {
    case LOW_STATE:
    {
        if (input == 1)
        {
            *state = RISING_EDGE_STATE;
        }
        else
        {
            *state = LOW_STATE;
        }
        break;
    }
    case HIGH_STATE:
    {
        if (input == 1)
        {
            *state = HIGH_STATE;
        }
        else
        {
            *state = FALLING_EDGE_STATE;
        }
        break;
    }
    case RISING_EDGE_STATE:
    {
        if (input == 1)
        {
            *state = HIGH_STATE;
        }
        else
        {
            *state = FALLING_EDGE_STATE;
        }
        break;
    }
    case FALLING_EDGE_STATE:
    {
        if (input == 1)
        {
            *state = RISING_EDGE_STATE;
        }
        else
        {
            *state = LOW_STATE;
        }
        break;
    }
    default:
        break;
    }
}