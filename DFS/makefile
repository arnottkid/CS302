all: bin/gen_graph \
     bin/concomp \
     bin/cycledet0 \
     bin/cycledet1 \
     bin/cycledet2 \
     bin/cycledet3 \
     bin/concomp-pointer 

CFLAGS = -Wall -Wextra 

clean:
	rm -f bin/* a.out

bin/gen_graph: src/gen_graph.cpp
	g++ $(CFLAGS) -o bin/gen_graph src/gen_graph.cpp

bin/concomp: src/concomp.cpp
	g++ $(CFLAGS) -o bin/concomp src/concomp.cpp

bin/concomp-pointer: src/concomp-pointer.cpp
	g++ $(CFLAGS) -o bin/concomp-pointer src/concomp-pointer.cpp

bin/cycledet0: src/cycledet0.cpp
	g++ $(CFLAGS) -o bin/cycledet0 src/cycledet0.cpp

bin/cycledet1: src/cycledet1.cpp
	g++ $(CFLAGS) -o bin/cycledet1 src/cycledet1.cpp

bin/cycledet2: src/cycledet2.cpp
	g++ $(CFLAGS) -o bin/cycledet2 src/cycledet2.cpp

bin/cycledet3: src/cycledet3.cpp
	g++ $(CFLAGS) -o bin/cycledet3 src/cycledet3.cpp

