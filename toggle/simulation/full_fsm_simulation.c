#include <stdio.h>
#include "../fsm/debounce_fsm.h"
#include "../fsm/rising_edge_fsm.h"
#include "../fsm/toggle_fsm.h"

int bounce[10] = {0, 1, 0, 1, 1, 0, 1, 0, 1, 0};
int zeros[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int ones[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main()
{
    int debounce_state = IDLE_STATE, cnt = 0, debounce_output = 0;
    int rising_edge_state = LOW_STATE, rising_edge_output = 0;
    int toggle_state = TOGGLE_OFF_STATE, output = 0;

    printf("INPUT OUTPUT\n");
    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, bounce[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", bounce[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, ones[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", ones[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, bounce[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", bounce[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, zeros[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", zeros[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, bounce[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", bounce[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, ones[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", ones[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, bounce[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", bounce[i], output);
    }

    for (int i = 0; i < 10; i++)
    {
        debounce_fsm(&debounce_state, &cnt, zeros[i], &debounce_output);
        rising_edge_fsm(&rising_edge_state, debounce_output, &rising_edge_output);
        toggle_fsm(&toggle_state, rising_edge_output, &output);
        printf("%-5d %-5d\n", zeros[i], output);
    }

    return 0;
}