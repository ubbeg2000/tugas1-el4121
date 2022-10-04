#include <stdio.h>
#include "../fsm/debounce_fsm.h"

int state = 0;
int cnt = 0;
int input = 0;
int output = 0;

void check(int cond)
{
    if (cond)
    {
        printf("ok\n");
    }
    else
    {
        printf("state: %d; count %d; input: %d; output: %d\n", &state, &cnt, input, &output);
        printf("not ok\n");
    }
}

int main()
{

    state = IDLE_STATE;
    cnt = 0;
    input = 0;
    output = 0;

    debounce_fsm(&state, &cnt, input, &output);
    check(state == IDLE_STATE && cnt == 0 && output == 0);

    state = IDLE_STATE;
    cnt = 0;
    input = 1;
    output = 0;

    debounce_fsm(&state, &cnt, input, &output);
    check(state == WAITING_STATE && cnt == 0 && output == 0);

    state = WAITING_STATE;
    cnt = 0;
    input = 1;
    output = 0;

    debounce_fsm(&state, &cnt, input, &output);
    check(state == WAITING_STATE && cnt == 1 && output == 0);

    state = WAITING_STATE;
    cnt = 0;
    input = 0;
    output = 0;

    debounce_fsm(&state, &cnt, input, &output);
    check(state == WAITING_STATE && cnt == 1 && output == 0);

    state = WAITING_STATE;
    cnt = DEBOUNCE_DELAY;
    input = 0;
    output = 0;

    debounce_fsm(&state, &cnt, input, &output);
    check(state == READING_STATE && cnt == 0 && output == 0);

    state = READING_STATE;
    cnt = 0;
    input = 0;
    output = 0;

    debounce_fsm(&state, &cnt, input, &output);
    check(state == IDLE_STATE && cnt == 0 && output == 0);

    state = READING_STATE;
    cnt = 0;
    input = 1;
    output = 0;

    debounce_fsm(&state, &cnt, input, &output);
    check(state == READING_STATE && cnt == 0 && output == 1);

    return 0;
}