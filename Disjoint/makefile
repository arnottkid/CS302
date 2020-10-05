ALL = bin/example bin/maze-gen bin/maze_ppm bin/example-exam bin/dj_tool

all: $(ALL)

CFLAGS = -Iinclude -Wall -Wextra -std=c++98

clean: 
	rm -f a.out obj/* bin/*

# Object files

OBJS = obj/disjoint-height.o obj/disjoint-rank.o obj/disjoint-size.o

obj/disjoint-height.o: src/disjoint-height.cpp include/disjoint.hpp
	g++ $(CFLAGS) -c -o obj/disjoint-height.o src/disjoint-height.cpp

obj/disjoint-rank.o: src/disjoint-rank.cpp include/disjoint.hpp
	g++ $(CFLAGS) -c -o obj/disjoint-rank.o src/disjoint-rank.cpp

obj/disjoint-size.o: src/disjoint-size.cpp include/disjoint.hpp
	g++ $(CFLAGS) -c -o obj/disjoint-size.o src/disjoint-size.cpp

obj/example.o: src/example.cpp include/disjoint.hpp
	g++ $(CFLAGS) -c -o obj/example.o src/example.cpp

obj/example-exam.o: src/example-exam.cpp include/disjoint.hpp
	g++ $(CFLAGS) -c -o obj/example-exam.o src/example-exam.cpp

obj/maze-gen.o: src/maze-gen.cpp include/disjoint.hpp
	g++ $(CFLAGS) -c -o obj/maze-gen.o src/maze-gen.cpp

# Executables

bin/example: obj/example.o $(OBJS)
	g++ -O -o bin/example obj/example.o $(OBJS)

bin/example-exam: obj/example-exam.o $(OBJS)
	g++ -O -o bin/example-exam obj/example-exam.o $(OBJS)

bin/maze-gen: obj/maze-gen.o $(OBJS)
	g++ -O -o bin/maze-gen obj/maze-gen.o $(OBJS)

bin/dj_tool: src/dj_tool.cpp $(OBJS)
	g++ -O $(CFLAGS) -o bin/dj_tool src/dj_tool.cpp $(OBJS)

bin/maze_ppm: src/maze_ppm.cpp 
	g++ -O -o bin/maze_ppm src/maze_ppm.cpp

