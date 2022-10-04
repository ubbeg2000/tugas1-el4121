#define OFF_STATE 80
#define JUST_ON_STATE 81
#define ON_STATE 82
#define JUST_OFF_STATE 83
#define OFF_DELAY 200

void on_off_fsm(int *state, int *cnt, int input, int *output);