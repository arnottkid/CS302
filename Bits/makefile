EXECUTABLES = bin/ba_helper

all: $(EXECUTABLES)

CFLAGS ?= -Wall -Wextra -std=c++98 -Iinclude

clean:
	rm -f a.out bin/*

bin/ba_helper: src/ba_helper.cpp
	g++ $(CFLAGS) -o bin/ba_helper src/ba_helper.cpp

