ALL = c_str \
      buffer_changes \
      bad_c_str \
      good_c_str_2 \
      bad_c_str_2 \
      sprintf1 \
      sprintf2 \
      sscanf1 \
      sscanf2 \
      sscanf3

all: $(ALL)

clean:
	rm -f a.out *.o $(ALL)

bad_c_str: bad_c_str.cpp
	g++ -std=c++98 -o bad_c_str bad_c_str.cpp

bad_c_str_2: bad_c_str_2.cpp
	g++ -std=c++98 -o bad_c_str_2 bad_c_str_2.cpp

buffer_changes: buffer_changes.cpp
	g++ -std=c++98 -o buffer_changes buffer_changes.cpp

c_str: c_str.cpp
	g++ -std=c++98 -o c_str c_str.cpp

good_c_str_2: good_c_str_2.cpp
	g++ -std=c++98 -o good_c_str_2 good_c_str_2.cpp

sprintf1: sprintf1.cpp
	g++ -std=c++98 -o sprintf1 sprintf1.cpp

sprintf2: sprintf2.cpp
	g++ -std=c++98 -o sprintf2 sprintf2.cpp

sscanf1: sscanf1.cpp
	g++ -std=c++98 -o sscanf1 sscanf1.cpp

sscanf2: sscanf2.cpp
	g++ -std=c++98 -o sscanf2 sscanf2.cpp

sscanf3: sscanf3.cpp
	g++ -std=c++98 -o sscanf3 sscanf3.cpp

