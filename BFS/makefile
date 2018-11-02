all: gen_graph cc-count cccycle-wrong cccycle 

clean:
	rm -f *.o gen_graph cc-count cccycle-wrong cccycle 

.SUFFIXES: .cpp .o

.cpp.o: g++ -c $*.cpp 

gen_graph: gen_graph.o
	g++ -o gen_graph gen_graph.o

cc-count: cc-count.o
	g++ -o cc-count cc-count.o

cccycle-wrong: cccycle-wrong.o
	g++ -o cccycle-wrong cccycle-wrong.o

cccycle: cccycle.o
	g++ -o cccycle cccycle.o

