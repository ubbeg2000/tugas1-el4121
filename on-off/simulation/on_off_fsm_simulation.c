#include <stdio.h>
#include "../fsm/on_off_fsm.h"

int zeros[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int ones[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main()
{
    int state = OFF_STATE, cnt = 0, output = 0;

    printf("INPUT OUTPUT\n");
    for (int i = 0; i < 10; i++)
    {
        on_off_fsm(&state, &cnt, zeros[i], &output);
        printf("%-5d %-5d\n", zeros[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        on_off_fsm(&state, &cnt, ones[i], &output);
        printf("%-5d %-5d\n", ones[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        on_off_fsm(&state, &cnt, ones[i], &output);
        printf("%-5d %-5d\n", ones[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        on_off_fsm(&state, &cnt, zeros[i], &output);
        printf("%-5d %-5d\n", zeros[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            on_off_fsm(&state, &cnt, ones[i], &output);
        }
        printf("%-5d %-5d\n", ones[i], output);
    }

    return 0;
}