CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/car_buyer_skeleton \
      bin/car_buyer_stringstream \
      bin/car_buyer_sscanf \
      bin/colorful_bricks_skeleton \
      bin/colorful_1_sort \
      bin/colorful_2_set \
      bin/colorful_3_map \
      bin/colorful_4_vec \
      bin/colorful_5_vec \
      bin/colorful_6_two_chars \
      bin/car_buyer_mine \
      bin/glossary_skeleton \
      bin/glossary_1_sort \
      bin/glossary_2_keymap \
      bin/glossary_3_makestrings \
      bin/glossary_4_finish \
      bin/glossary_mine \

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Object files

obj/car_buyer_skeleton.o: src/car_buyer_skeleton.cpp include/car_buyer.hpp
	g++ $(CFLAGS) -c -o obj/car_buyer_skeleton.o src/car_buyer_skeleton.cpp

obj/car_buyer_stringstream.o: src/car_buyer_stringstream.cpp include/car_buyer.hpp
	g++ $(CFLAGS) -c -o obj/car_buyer_stringstream.o src/car_buyer_stringstream.cpp

obj/car_buyer_sscanf.o: src/car_buyer_sscanf.cpp include/car_buyer.hpp
	g++ $(CFLAGS) -c -o obj/car_buyer_sscanf.o src/car_buyer_sscanf.cpp

obj/car_buyer_mine.o: src/car_buyer_mine.cpp include/car_buyer.hpp
	g++ $(CFLAGS) -c -o obj/car_buyer_mine.o src/car_buyer_mine.cpp

obj/car_buyer_main.o: src/car_buyer_main.cpp include/car_buyer.hpp
	g++ $(CFLAGS) -c -o obj/car_buyer_main.o src/car_buyer_main.cpp

obj/colorful_bricks_skeleton.o: src/colorful_bricks_skeleton.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_bricks_skeleton.o src/colorful_bricks_skeleton.cpp

obj/colorful_1_sort.o: src/colorful_1_sort.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_1_sort.o src/colorful_1_sort.cpp

obj/colorful_2_set.o: src/colorful_2_set.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_2_set.o src/colorful_2_set.cpp

obj/colorful_3_map.o: src/colorful_3_map.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_3_map.o src/colorful_3_map.cpp

obj/colorful_4_vec.o: src/colorful_4_vec.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_4_vec.o src/colorful_4_vec.cpp

obj/colorful_5_vec.o: src/colorful_5_vec.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_5_vec.o src/colorful_5_vec.cpp

obj/colorful_6_two_chars.o: src/colorful_6_two_chars.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_6_two_chars.o src/colorful_6_two_chars.cpp

obj/colorful_bricks_main.o: src/colorful_bricks_main.cpp include/colorful_bricks.hpp
	g++ $(CFLAGS) -c -o obj/colorful_bricks_main.o src/colorful_bricks_main.cpp

obj/glossary_skeleton.o: src/glossary_skeleton.cpp include/glossary.hpp
	g++ $(CFLAGS) -c -o obj/glossary_skeleton.o src/glossary_skeleton.cpp

obj/glossary_main.o: src/glossary_main.cpp include/glossary.hpp
	g++ $(CFLAGS) -c -o obj/glossary_main.o src/glossary_main.cpp

obj/glossary_1_sort.o: src/glossary_1_sort.cpp include/glossary.hpp
	g++ $(CFLAGS) -c -o obj/glossary_1_sort.o src/glossary_1_sort.cpp

obj/glossary_2_keymap.o: src/glossary_2_keymap.cpp include/glossary.hpp
	g++ $(CFLAGS) -c -o obj/glossary_2_keymap.o src/glossary_2_keymap.cpp

obj/glossary_3_makestrings.o: src/glossary_3_makestrings.cpp include/glossary.hpp
	g++ $(CFLAGS) -c -o obj/glossary_3_makestrings.o src/glossary_3_makestrings.cpp

obj/glossary_4_finish.o: src/glossary_4_finish.cpp include/glossary.hpp
	g++ $(CFLAGS) -c -o obj/glossary_4_finish.o src/glossary_4_finish.cpp

obj/glossary_mine.o: src/glossary_mine.cpp include/glossary.hpp
	g++ $(CFLAGS) -c -o obj/glossary_mine.o src/glossary_mine.cpp

# -------------------------
# Executables

bin/car_buyer_skeleton: obj/car_buyer_skeleton.o obj/car_buyer_main.o
	g++ $(CFLAGS) -o bin/car_buyer_skeleton obj/car_buyer_skeleton.o obj/car_buyer_main.o

bin/car_buyer_stringstream: obj/car_buyer_stringstream.o obj/car_buyer_main.o
	g++ $(CFLAGS) -o bin/car_buyer_stringstream obj/car_buyer_stringstream.o obj/car_buyer_main.o

bin/car_buyer_sscanf: obj/car_buyer_sscanf.o obj/car_buyer_main.o
	g++ $(CFLAGS) -o bin/car_buyer_sscanf obj/car_buyer_sscanf.o obj/car_buyer_main.o

bin/car_buyer_mine: obj/car_buyer_mine.o obj/car_buyer_main.o
	g++ $(CFLAGS) -o bin/car_buyer_mine obj/car_buyer_mine.o obj/car_buyer_main.o

bin/colorful_bricks_skeleton: obj/colorful_bricks_skeleton.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_bricks_skeleton obj/colorful_bricks_skeleton.o obj/colorful_bricks_main.o

bin/colorful_1_sort: obj/colorful_1_sort.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_1_sort obj/colorful_1_sort.o obj/colorful_bricks_main.o

bin/colorful_2_set: obj/colorful_2_set.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_2_set obj/colorful_2_set.o obj/colorful_bricks_main.o

bin/colorful_3_map: obj/colorful_3_map.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_3_map obj/colorful_3_map.o obj/colorful_bricks_main.o

bin/colorful_4_vec: obj/colorful_4_vec.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_4_vec obj/colorful_4_vec.o obj/colorful_bricks_main.o

bin/colorful_5_vec: obj/colorful_5_vec.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_5_vec obj/colorful_5_vec.o obj/colorful_bricks_main.o

bin/colorful_6_two_chars: obj/colorful_6_two_chars.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_6_two_chars obj/colorful_6_two_chars.o obj/colorful_bricks_main.o

bin/colorful_bricks_mine: obj/colorful_bricks_mine.o obj/colorful_bricks_main.o
	g++ $(CFLAGS) -o bin/colorful_bricks_mine obj/colorful_bricks_mine.o obj/colorful_bricks_main.o

bin/glossary_skeleton: obj/glossary_skeleton.o obj/glossary_main.o
	g++ $(CFLAGS) -o bin/glossary_skeleton obj/glossary_skeleton.o obj/glossary_main.o

bin/glossary_1_sort: obj/glossary_1_sort.o obj/glossary_main.o
	g++ $(CFLAGS) -o bin/glossary_1_sort obj/glossary_1_sort.o obj/glossary_main.o

bin/glossary_2_keymap: obj/glossary_2_keymap.o obj/glossary_main.o
	g++ $(CFLAGS) -o bin/glossary_2_keymap obj/glossary_2_keymap.o obj/glossary_main.o

bin/glossary_3_makestrings: obj/glossary_3_makestrings.o obj/glossary_main.o
	g++ $(CFLAGS) -o bin/glossary_3_makestrings obj/glossary_3_makestrings.o obj/glossary_main.o

bin/glossary_4_finish: obj/glossary_4_finish.o obj/glossary_main.o
	g++ $(CFLAGS) -o bin/glossary_4_finish obj/glossary_4_finish.o obj/glossary_main.o

bin/glossary_mine: obj/glossary_mine.o obj/glossary_main.o
	g++ $(CFLAGS) -o bin/glossary_mine obj/glossary_mine.o obj/glossary_main.o

