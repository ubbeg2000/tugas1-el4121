debounce-fsm-simulation:
	gcc -o debounce-fsm-simulation ./simulation/debounce_fsm_simulation.c ./fsm/debounce_fsm.c

debounce-fsm-test:
	gcc -o debounce-fsm-test ./test/debounce_fsm_test.c ./fsm/debounce_fsm.c

on-off-fsm-simulation:
	gcc -o on-off-fsm-simulation ./simulation/on_off_fsm_simulation.c ./fsm/on_off_fsm.c

on-off-fsm-test:
	gcc -o on-off-fsm-test ./test/on_off_fsm_test.c ./fsm/on_off_fsm.c


all: 
	$(MAKE) debounce-fsm-simulation
	$(MAKE) debounce-fsm-test
	$(MAKE) on-off-fsm-simulation
	$(MAKE) on-off-fsm-test

clean:
	del *.exe