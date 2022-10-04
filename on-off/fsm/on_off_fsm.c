#include "on_off_fsm.h"

void on_off_fsm(int *state, int *cnt, int input, int *output)
{
    switch (*state)
    {
    case OFF_STATE:
    {
        if (input == 1)
        {
            *cnt = 0;
            *state = JUST_ON_STATE;
            *output = 1;
        }
        else
        {
            *cnt = 0;
            *state = OFF_STATE;
            *output = 0;
        }
        break;
    }
    case JUST_ON_STATE:
    {
        if (input == 1)
        {
            *cnt = 0;
            *output = 1;
            *state = JUST_ON_STATE;
        }
        else
        {
            *cnt = 0;
            *output = 1;
            *state = ON_STATE;
        }
        break;
    }
    case ON_STATE:
    {
        if (input == 1)
        {
            if (*cnt < OFF_DELAY)
            {
                *cnt = *cnt + 1;
                *state = ON_STATE;
                *output = 1;
            }
            else
            {
                *cnt = 0;
                *state = JUST_OFF_STATE;
                *output = 0;
            }
        }
        else
        {
            *cnt = 0;
            *state = ON_STATE;
            *output = 1;
        }
        break;
    }
    case JUST_OFF_STATE:
    {
        if (input == 1)
        {
            *cnt = 0;
            *output = 0;
            *state = JUST_OFF_STATE;
        }
        else
        {
            *cnt = 0;
            *output = 0;
            *state = OFF_STATE;
        }
        break;
    }
    default:
        break;
    }
}
