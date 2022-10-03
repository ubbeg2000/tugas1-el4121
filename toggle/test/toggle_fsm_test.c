#include <stdio.h>
#include "../fsm/toggle_fsm.h"

int state;
int input;
int output;

void check(int cond)
{
    if (cond)
    {
        printf("ok\n");
    }
    else
    {
        printf("state: %d; input: %d; output: %d\n", state, input, output);
        printf("not ok\n");
    }
}

int main()
{
    state = TOGGLE_OFF_STATE;
    input = 0;

    toggle_fsm(&state, input, &output);
    check(state == TOGGLE_OFF_STATE && output == 0);

    state = TOGGLE_OFF_STATE;
    input = 1;

    toggle_fsm(&state, input, &output);
    check(state == TOGGLE_ON_STATE && output == 1);

    state = TOGGLE_ON_STATE;
    input = 0;

    toggle_fsm(&state, input, &output);
    check(state == TOGGLE_ON_STATE && output == 1);

    state = TOGGLE_ON_STATE;
    input = 1;

    toggle_fsm(&state, input, &output);
    check(state == TOGGLE_OFF_STATE && output == 0);

    return 0;
}