ALL = bin/add_5 \
      bin/pq_sort \
      bin/massive_create \
      bin/formula \
      bin/genrandom

OBJS = obj/pqueue_set.o obj/pqueue_heap.o
CFLAGS = -Iinclude -Wall -Wextra -std=c++98

all: $(ALL)

clean:
	rm -f a.out bin/* obj/*

# Object files

obj/pqueue_set.o: include/pqueue.hpp src/pqueue_set.cpp
	g++ $(CFLAGS) -O -c -o obj/pqueue_set.o src/pqueue_set.cpp

obj/pqueue_heap.o: include/pqueue.hpp src/pqueue_heap.cpp
	g++ $(CFLAGS) -O -c -o obj/pqueue_heap.o src/pqueue_heap.cpp

# Executables 

bin/add_5: include/pqueue.hpp src/add_5.cpp $(OBJS)
	g++ $(CFLAGS) -O -o bin/add_5 src/add_5.cpp $(OBJS)

bin/pq_sort: include/pqueue.hpp src/pq_sort.cpp $(OBJS)
	g++ $(CFLAGS) -O -o bin/pq_sort src/pq_sort.cpp $(OBJS)

bin/massive_create: include/pqueue.hpp src/massive_create.cpp $(OBJS)
	g++ $(CFLAGS) -O -o bin/massive_create src/massive_create.cpp $(OBJS)

bin/formula: src/formula.cpp
	g++ $(CFLAGS) -o bin/formula src/formula.cpp

bin/genrandom: src/genrandom.cpp
	g++ $(CFLAGS) -o bin/genrandom src/genrandom.cpp

