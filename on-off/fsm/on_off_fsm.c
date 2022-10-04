#include "on_off_fsm.h"

void on_off_fsm(int *state, int *cnt, int input, int *output)
{
    switch (*state)
    {
    case OFF_STATE:
    {
        if (input == 1)
        {
            if (*cnt >= OFF_DELAY)
            {
                *cnt = *cnt + 1;
                *state = OFF_STATE;
                *output = 0;
            }
            else
            {
                *cnt = 0;
                *state = ON_STATE;
                *output = 1;
            }
        }
        else
        {
            *cnt = 0;
            *state = OFF_STATE;
            *output = 0;
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
                *cnt = *cnt + 1;
                *state = OFF_STATE;
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
    default:
        break;
    }
}
