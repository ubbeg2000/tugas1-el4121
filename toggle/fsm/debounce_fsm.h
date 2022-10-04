#define WAITING_STATE 60
#define READING_STATE 61
#define IDLE_STATE 62
#define DEBOUNCE_DELAY 2

void debounce_fsm(int *state, int *cnt, int input, int *output);