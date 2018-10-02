ALL = add_5 pq_sort massive_create formula genrandom 

all: $(ALL)

clean:
	rm -f $(ALL) *.o a.out

pqueue_set.o: pqueue.h
pqueue_heap.o: pqueue.h

add_5: pqueue.h add_5.cpp pqueue_set.o pqueue_heap.o 
	g++ -O -o add_5 add_5.cpp pqueue_set.o pqueue_heap.o 

pq_sort: pqueue.h pq_sort.cpp pqueue_set.o pqueue_heap.o 
	g++ -O -o pq_sort pq_sort.cpp pqueue_set.o pqueue_heap.o 

massive_create: pqueue.h massive_create.cpp pqueue_set.o pqueue_heap.o 
	g++ -O -o massive_create massive_create.cpp pqueue_set.o pqueue_heap.o 

formula: formula.cpp
	g++ -o formula formula.cpp

genrandom: genrandom.cpp
	g++ -o genrandom genrandom.cpp

.SUFFIXES: .cpp .o

.cpp.o:
	g++ -c -O $*.cpp

