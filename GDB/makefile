ALL = bin/sf1 \
      bin/sf2 \
      bin/sudoku5

all: $(ALL)

clean:
	rm -f a.out bin/*

bin/sf1: src/sf1.cpp
	g++ -g -o bin/sf1 src/sf1.cpp

bin/sf2: src/sf2.cpp
	g++ -g -o bin/sf2 src/sf2.cpp

bin/sudoku5: src/sudoku5.cpp
	g++ -g -o bin/sudoku5 src/sudoku5.cpp
