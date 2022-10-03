test-rising-edge:
	gcc -o test-rising-edge ./test/rising_edge_fsm_test.c ./fsm/rising_edge_fsm.c

test-toggle:
	gcc -o test-toggle ./test/toggle_fsm_test.c ./fsm/toggle_fsm.c

simulate-rising-edge:
	gcc -o simulate-rising-edge ./simulation/rising_edge_fsm_simulation.c ./fsm/rising_edge_fsm.c

simulate-toggle:
	gcc -o simulate-toggle ./simulation/toggle_fsm_simulation.c ./fsm/toggle_fsm.c

all: 
	$(MAKE) test-toggle
	$(MAKE) test-rising-edge
	$(MAKE) simulate-toggle
	$(MAKE) simulate-rising-edge

clean:
	del *.exe