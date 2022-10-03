#include <stdio.h>
#include "../fsm/rising_edge_fsm.h"

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
    state = LOW_STATE;
    input = 0;

    rising_edge_fsm(&state, input, &output);
    check(state == LOW_STATE && output == 0);

    state = LOW_STATE;
    input = 1;

    rising_edge_fsm(&state, input, &output);
    check(state == EDGE_STATE && output == 1);

    state = EDGE_STATE;
    input = 0;

    rising_edge_fsm(&state, input, &output);
    check(state == LOW_STATE && output == 0);

    state = EDGE_STATE;
    input = 1;

    rising_edge_fsm(&state, input, &output);
    check(state == HIGH_STATE && output == 0);

    state = EDGE_STATE;
    input = 0;

    rising_edge_fsm(&state, input, &output);
    check(state == LOW_STATE && output == 0);

    state = EDGE_STATE;
    input = 1;

    rising_edge_fsm(&state, input, &output);
    check(state == HIGH_STATE && output == 0);

    return 0;
}