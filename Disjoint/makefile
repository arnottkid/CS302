ALL = example maze-gen maze_ppm example-exam

all: $(ALL)

clean: 
	rm -f *.o a.out $(ALL)

OBJS = disjoint-height.o disjoint-rank.o disjoint-size.o

example.o: disjoint.h
maze-gen.o: disjoint.h
disjoint-height.o: disjoint.h
disjoint-rank.o: disjoint.h
disjoint-size.o: disjoint.h

.SUFFIXES: .cpp .o 

.cpp.o: 
	g++ -c -O $*.cpp

example: example.o $(OBJS)
	g++ -O -o example example.o $(OBJS)

example-exam: example-exam.o $(OBJS)
	g++ -O -o example-exam example-exam.o $(OBJS)

maze-gen: maze-gen.o $(OBJS)
	g++ -O -o maze-gen maze-gen.o $(OBJS)

maze_ppm: maze_ppm.cpp 
	g++ -O -o maze_ppm maze_ppm.cpp

