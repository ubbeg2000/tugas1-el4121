#include "debounce_fsm.h"

void debounce_fsm(int *state, int *cnt, int input, int *output)
{
    switch (*state)
    {
    case WAITING_STATE:
    {
        if (*cnt >= DEBOUNCE_DELAY)
        {
            *cnt = 0;
            *output = 0;
            *state = READING_STATE;
        }
        else
        {
            *cnt = *cnt + 1;
            *output = 0;
            *state = WAITING_STATE;
        }
        break;
    }
    case READING_STATE:
    {
        if (input == 1)
        {
            *cnt = 0;
            *output = 1;
            *state = READING_STATE;
        }
        else
        {
            *cnt = 0;
            *output = 0;
            *state = IDLE_STATE;
        }
        break;
    }
    case IDLE_STATE:
    {
        if (input == 1)
        {
            *cnt = 0;
            *output = 0;
            *state = WAITING_STATE;
        }
        else
        {
            *cnt = 0;
            *output = 0;
            *state = IDLE_STATE;
        }
        break;
    }

    default:
        break;
    }
}