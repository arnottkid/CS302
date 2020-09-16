All = bin/balls-in-boxes-0 \
      bin/balls-in-boxes-1 \
      bin/balls-in-boxes-2 \
      bin/balls-in-boxes-3 \
      bin/balls-in-boxes-4 \
      bin/balls-in-boxes-5 \
      bin/gen-3-teams \
      bin/divmod \
      bin/gen-permutations \
      bin/gen-teams \

all: $(All)

CFLAGS = -Wall -Wextra
clean:
	rm -f $(All)

bin/balls-in-boxes-0: src/balls-in-boxes-0.cpp
	g++ $(CFLAGS) -o bin/balls-in-boxes-0 src/balls-in-boxes-0.cpp

bin/balls-in-boxes-1: src/balls-in-boxes-1.cpp
	g++ $(CFLAGS) -o bin/balls-in-boxes-1 src/balls-in-boxes-1.cpp

bin/balls-in-boxes-2: src/balls-in-boxes-2.cpp
	g++ $(CFLAGS) -o bin/balls-in-boxes-2 src/balls-in-boxes-2.cpp

bin/balls-in-boxes-3: src/balls-in-boxes-3.cpp
	g++ $(CFLAGS) -o bin/balls-in-boxes-3 src/balls-in-boxes-3.cpp

bin/balls-in-boxes-4: src/balls-in-boxes-4.cpp
	g++ $(CFLAGS) -o bin/balls-in-boxes-4 src/balls-in-boxes-4.cpp

bin/balls-in-boxes-5: src/balls-in-boxes-5.cpp
	g++ $(CFLAGS) -o bin/balls-in-boxes-5 src/balls-in-boxes-5.cpp

bin/gen-3-teams: src/gen-3-teams.cpp
	g++ $(CFLAGS) -o bin/gen-3-teams src/gen-3-teams.cpp

bin/divmod: src/divmod.cpp
	g++ $(CFLAGS) -o bin/divmod src/divmod.cpp

bin/gen-permutations: src/gen-permutations.cpp
	g++ $(CFLAGS) -o bin/gen-permutations src/gen-permutations.cpp

bin/gen-teams: src/gen-teams.cpp
	g++ $(CFLAGS) -o bin/gen-teams src/gen-teams.cpp

