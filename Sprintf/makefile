ALL = bin/c_str \
      bin/buffer_changes \
      bin/bad_c_str \
      bin/good_c_str_2 \
      bin/bad_c_str_2 \
      bin/sprintf1 \
      bin/sprintf2 \
      bin/sscanf1 \
      bin/sscanf2 \
      bin/sscanf3

CFLAGS ?= -std=c++98 -Wall -Wextra 

all: $(ALL)

clean:
	rm -f a.out bin/*

bin/bad_c_str: src/bad_c_str.cpp
	g++ $(CFLAGS)-o bin/bad_c_str src/bad_c_str.cpp

bin/bad_c_str_2: src/bad_c_str_2.cpp
	g++ $(CFLAGS)-o bin/bad_c_str_2 src/bad_c_str_2.cpp

bin/buffer_changes: src/buffer_changes.cpp
	g++ $(CFLAGS)-o bin/buffer_changes src/buffer_changes.cpp

bin/c_str: src/c_str.cpp
	g++ $(CFLAGS)-o bin/c_str src/c_str.cpp

bin/good_c_str_2: src/good_c_str_2.cpp
	g++ $(CFLAGS)-o bin/good_c_str_2 src/good_c_str_2.cpp

bin/sprintf1: src/sprintf1.cpp
	g++ $(CFLAGS)-o bin/sprintf1 src/sprintf1.cpp

bin/sprintf2: src/sprintf2.cpp
	g++ $(CFLAGS)-o bin/sprintf2 src/sprintf2.cpp

bin/sscanf1: src/sscanf1.cpp
	g++ $(CFLAGS)-o bin/sscanf1 src/sscanf1.cpp

bin/sscanf2: src/sscanf2.cpp
	g++ $(CFLAGS)-o bin/sscanf2 src/sscanf2.cpp

bin/sscanf3: src/sscanf3.cpp
	g++ $(CFLAGS)-o bin/sscanf3 src/sscanf3.cpp

