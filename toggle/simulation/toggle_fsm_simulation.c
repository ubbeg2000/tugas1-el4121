#include <stdio.h>
#include "../fsm/toggle_fsm.h"

int main()
{
    int state = TOGGLE_OFF_STATE, input = 0, output = 0;
    printf("INPUT OUTPUT\n");
    for (int i = 0; i < 20; i++)
    {
        input = i % 5 == 0 ? 1 : 0;
        toggle_fsm(&state, input, &output);
        printf("%-5d %-5d\n", input, output);
    }
    return 0;
}