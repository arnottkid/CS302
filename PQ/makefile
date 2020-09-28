ALL = bin/add_5 \
      bin/pq_sort \
      bin/pq_print \
      bin/pq_jgraph \
      bin/massive_create \
      bin/formula \
      bin/genrandom \
      img/vector-1.jpg \
      img/vector-2.jpg \
      img/vector-3.jpg \
      img/vector-4.jpg \
      img/vector-5.jpg \
      img/vector-6.jpg \
      img/vector-7.jpg \
      img/vector-8.jpg \
      img/vector-9.jpg \
      img/vector.gif

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

bin/pq_print: include/pqueue.hpp src/pq_print.cpp $(OBJS)
	g++ $(CFLAGS) -O -o bin/pq_print src/pq_print.cpp $(OBJS)

bin/pq_jgraph: src/pq_jgraph.cpp
	g++ $(CFLAGS) -O -o bin/pq_jgraph src/pq_jgraph.cpp

bin/massive_create: include/pqueue.hpp src/massive_create.cpp $(OBJS)
	g++ $(CFLAGS) -O -o bin/massive_create src/massive_create.cpp $(OBJS)

bin/formula: src/formula.cpp
	g++ $(CFLAGS) -o bin/formula src/formula.cpp

bin/genrandom: src/genrandom.cpp
	g++ $(CFLAGS) -o bin/genrandom src/genrandom.cpp

# Pictures:

img/vector-1.jpg: scripts/vector-1.jgr
	jgraph -P scripts/vector-1.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-1.jpg

img/vector-2.jpg: scripts/vector-2.jgr
	jgraph -P scripts/vector-2.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-2.jpg

img/vector-3.jpg: scripts/vector-3.jgr
	jgraph -P scripts/vector-3.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-3.jpg

img/vector-4.jpg: scripts/vector-4.jgr
	jgraph -P scripts/vector-4.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-4.jpg

img/vector-5.jpg: scripts/vector-5.jgr
	jgraph -P scripts/vector-5.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-5.jpg

img/vector-6.jpg: scripts/vector-6.jgr
	jgraph -P scripts/vector-6.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-6.jpg

img/vector-7.jpg: scripts/vector-7.jgr
	jgraph -P scripts/vector-7.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-7.jpg

img/vector-8.jpg: scripts/vector-8.jgr
	jgraph -P scripts/vector-8.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-8.jpg

img/vector-9.jpg: scripts/vector-9.jgr
	jgraph -P scripts/vector-9.jgr | ps2pdf - | convert -density 300 - -quality 100 -crop 2000x2300+267+800 img/vector-9.jpg

img/vector.gif: img/vector-1.jpg img/vector-2.jpg img/vector-3.jpg \
                img/vector-4.jpg img/vector-5.jpg img/vector-6.jpg \
                img/vector-7.jpg img/vector-8.jpg img/vector-9.jpg 
	convert -delay 70 -loop 0 img/vector-?.jpg img/vector.gif
