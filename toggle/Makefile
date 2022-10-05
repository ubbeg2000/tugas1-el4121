debounce-fsm-simulation:
	gcc -o debounce-fsm-simulation ./simulation/debounce_fsm_simulation.c ./fsm/debounce_fsm.c

debounce-fsm-test:
	gcc -o debounce-fsm-test ./test/debounce_fsm_test.c ./fsm/debounce_fsm.c

rising-edge-fsm-simulation:
	gcc -o rising-edge-fsm-simulation ./simulation/rising_edge_fsm_simulation.c ./fsm/rising_edge_fsm.c

rising-edge-fsm-test:
	gcc -o rising-edge-fsm-test ./test/rising_edge_fsm_test.c ./fsm/rising_edge_fsm.c

toggle-fsm-simulation:
	gcc -o toggle-fsm-simulation ./simulation/toggle_fsm_simulation.c ./fsm/toggle_fsm.c

toggle-fsm-test:
	gcc -o toggle-fsm-test ./test/toggle_fsm_test.c ./fsm/toggle_fsm.c

full-fsm-simulation:
	gcc -o full-fsm-simulation ./simulation/full_fsm_simulation.c ./fsm/toggle_fsm.c ./fsm/rising_edge_fsm.c ./fsm/debounce_fsm.c

all: 
	$(MAKE) debounce-fsm-simulation
	$(MAKE) debounce-fsm-test
	$(MAKE) toggle-fsm-test
	$(MAKE) rising-edge-fsm-test
	$(MAKE) toggle-fsm-simulation
	$(MAKE) rising-edge-fsm-simulation

clean:
	del *.exe