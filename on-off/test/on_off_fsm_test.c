#include <stdio.h>
#include "../fsm/on_off_fsm.h"

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

    state = OFF_STATE;
    cnt = 0;
    input = 0;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == OFF_STATE && cnt == 0 && output == 0);

    state = OFF_STATE;
    cnt = 0;
    input = 1;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == JUST_ON_STATE && cnt == 0 && output == 1);

    state = JUST_ON_STATE;
    cnt = 0;
    input = 1;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == JUST_ON_STATE && cnt == 0 && output == 1);

    state = JUST_ON_STATE;
    cnt = 0;
    input = 0;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == ON_STATE && cnt == 0 && output == 1);

    state = ON_STATE;
    cnt = 0;
    input = 0;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == ON_STATE && cnt == 0 && output == 1);

    state = ON_STATE;
    cnt = 0;
    input = 1;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == ON_STATE && cnt == 1 && output == 1);

    state = ON_STATE;
    cnt = OFF_DELAY;
    input = 1;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == JUST_OFF_STATE && cnt == 0 && output == 0);

    state = JUST_OFF_STATE;
    cnt = 0;
    input = 1;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == JUST_OFF_STATE && cnt == 0 && output == 0);

    state = JUST_OFF_STATE;
    cnt = 0;
    input = 0;
    output = 0;

    on_off_fsm(&state, &cnt, input, &output);
    check(state == OFF_STATE && cnt == 0 && output == 0);

    return 0;
}