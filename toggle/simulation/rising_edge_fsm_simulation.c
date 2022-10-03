#include <stdio.h>
#include "../fsm/rising_edge_fsm.h"

int main()
{
    int state = LOW_STATE, input, output = 0;
    printf("INPUT OUTPUT\n");
    for (int i = 0; i < 10; i++)
    {
        input = i < 5 ? 0 : 1;
        rising_edge_fsm(&state, input, &output);
        printf("%-5d %-5d\n", input, output);
    }
    for (int i = 0; i < 10; i++)
    {
        input = i < 5 ? 0 : 1;
        rising_edge_fsm(&state, input, &output);
        printf("%-5d %-5d\n", input, output);
    }
    return 0;
}