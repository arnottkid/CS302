all: gen_graph concomp cycledet0 cycledet1 cycledet2 cycledet3 concomp-pointer

clean:
	rm -f *.o gen_graph concomp cycledet0 cycledet1 cycledet2 cycledet3 concomp-pointer

.SUFFIXES: .cpp .o

.cpp.o: 
	g++ -c $*.cpp 

gen_graph: gen_graph.o
	g++ -o gen_graph gen_graph.o

concomp: concomp.o
	g++ -o concomp concomp.o

concomp-pointer: concomp-pointer.o
	g++ -o concomp-pointer concomp-pointer.o

cycledet0: cycledet0.o
	g++ -o cycledet0 cycledet0.o

cycledet1: cycledet1.o
	g++ -o cycledet1 cycledet1.o

cycledet2: cycledet2.o
	g++ -o cycledet2 cycledet2.o

cycledet3: cycledet3.o
	g++ -o cycledet3 cycledet3.o

