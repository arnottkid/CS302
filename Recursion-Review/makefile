ALL = bin/no_eights \
      bin/coins_exchange \
      bin/coins_exchange_print \
      bin/sudoku1 \
      bin/sudoku2 \
      bin/sudoku3 \
      bin/sudoku4 \
      bin/sudoku5 \
      bin/sudoku6 \
      bin/sudoku7 \
      bin/sudoku8 

all: $(ALL)

clean:
	rm -f a.out obj/* bin/*

CFLAGS = -std=c++98 -O3 -Wall -Wextra -Iinclude

# ------ Object files

obj/no_eights_main.o: src/no_eights_main.cpp include/no_eights.hpp
	g++ $(CFLAGS) -c -o obj/no_eights_main.o src/no_eights_main.cpp

obj/no_eights.o: src/no_eights.cpp include/no_eights.hpp
	g++ $(CFLAGS) -c -o obj/no_eights.o src/no_eights.cpp

obj/coins_exchange_main.o: src/coins_exchange_main.cpp include/coins_exchange.hpp
	g++ $(CFLAGS) -c -o obj/coins_exchange_main.o src/coins_exchange_main.cpp

obj/coins_exchange.o: src/coins_exchange.cpp include/coins_exchange.hpp
	g++ $(CFLAGS) -c -o obj/coins_exchange.o src/coins_exchange.cpp

obj/coins_exchange_print.o: src/coins_exchange_print.cpp include/coins_exchange.hpp
	g++ $(CFLAGS) -c -o obj/coins_exchange_print.o src/coins_exchange_print.cpp

# ------ Executables

bin/sudoku1: src/sudoku1.cpp
	g++ $(CFLAGS) -o bin/sudoku1 src/sudoku1.cpp 

bin/sudoku2: src/sudoku2.cpp
	g++ $(CFLAGS) -o bin/sudoku2 src/sudoku2.cpp 

bin/sudoku3: src/sudoku3.cpp
	g++ $(CFLAGS) -o bin/sudoku3 src/sudoku3.cpp 

bin/sudoku4: src/sudoku4.cpp
	g++ $(CFLAGS) -o bin/sudoku4 src/sudoku4.cpp 

bin/sudoku5: src/sudoku5.cpp
	g++ $(CFLAGS) -o bin/sudoku5 src/sudoku5.cpp 

bin/sudoku6: src/sudoku6.cpp
	g++ $(CFLAGS) -o bin/sudoku6 src/sudoku6.cpp 

bin/sudoku7: src/sudoku7.cpp
	g++ $(CFLAGS) -o bin/sudoku7 src/sudoku7.cpp 

bin/sudoku8: src/sudoku8.cpp
	g++ $(CFLAGS) -o bin/sudoku8 src/sudoku8.cpp 

bin/no_eights: obj/no_eights_main.o obj/no_eights.o
	g++ $(CFLAGS) -o bin/no_eights obj/no_eights_main.o obj/no_eights.o

bin/coins_exchange: obj/coins_exchange_main.o obj/coins_exchange.o
	g++ $(CFLAGS) -o bin/coins_exchange obj/coins_exchange_main.o obj/coins_exchange.o

bin/coins_exchange_print: obj/coins_exchange_main.o obj/coins_exchange_print.o
	g++ $(CFLAGS) -o bin/coins_exchange_print obj/coins_exchange_main.o obj/coins_exchange_print.o
