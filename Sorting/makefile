all: null_sort set_sort bubble_sort selection_sort insertion_1_sort insertion_2_sort \
     insertion_3_sort insertion_1_sorted heap_sort heap_fast_sort \
     stl_sort qsort_sort \
     bucket_1_sort bucket_2_sort 

lab: merge_1_lab_sort quick_2_lab_sort

private: quick_1_sort quick_2_sort quick_2_sorted  quick_1_sorted marge_1_sort merge_2_sort quick_3_sort quick_1_lab_sort 

clean: 
	rm -f *.o null_sort set_sort bubble_sort selection_sort insertion_1_sort insertion_2_sort \
                  insertion_3_sort insertion_1_sorted heap_sort \
                  quick_1_sort quick_1_sorted quick_2_sort merge_1_sort merge_2_sort qsort_sort \
                  bucket_1_sort bucket_2_sort quick_2_sorted quick_3_sort \
                  quick_1_lab_sort quick_2_lab_sort merge_1_lab_sort \
                  stl_sort heap_fast_sort

CFLAGS = -O3

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp

heap_fast_sort: heap_fast_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o heap_fast_sort heap_fast_sort.cpp sort_driver.o

null_sort: null_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o null_sort null_sort.cpp sort_driver.o

stl_sort: stl_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o stl_sort stl_sort.cpp sort_driver.o

set_sort: set_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o set_sort set_sort.cpp sort_driver.o

bubble_sort: bubble_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o bubble_sort bubble_sort.cpp sort_driver.o

heap_sort: heap_sort.cpp sort_driver.o pqueue.h pqueue_heap.cpp
	g++ $(CFLAGS) -o heap_sort heap_sort.cpp sort_driver.o pqueue_heap.cpp

pqueue_heap.cpp: pqueue.h

selection_sort: selection_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o selection_sort selection_sort.cpp sort_driver.o

insertion_1_sort: insertion_1_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o insertion_1_sort insertion_1_sort.cpp sort_driver.o

quick_2_sorted: quick_2_sort.cpp sort_sorted.cpp
	g++ $(CFLAGS) -o quick_2_sorted quick_2_sort.cpp sort_sorted.cpp

quick_1_sorted: quick_1_sort.cpp sort_sorted.cpp
	g++ $(CFLAGS) -o quick_1_sorted quick_1_sort.cpp sort_sorted.cpp

insertion_1_sorted: insertion_1_sort.cpp sort_sorted.cpp
	g++ $(CFLAGS) -o insertion_1_sorted insertion_1_sort.cpp sort_sorted.cpp

insertion_2_sort: insertion_2_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o insertion_2_sort insertion_2_sort.cpp sort_driver.o

insertion_3_sort: insertion_3_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o insertion_3_sort insertion_3_sort.cpp sort_driver.o

quick_3_sort: quick_3_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o quick_3_sort quick_3_sort.cpp sort_driver.o

quick_1_sort: quick_1_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o quick_1_sort quick_1_sort.cpp sort_driver.o

merge_1_lab_sort: merge_1_sort.cpp sort_driver_lab.cpp
	g++ $(CFLAGS) -o merge_1_lab_sort merge_1_sort.cpp sort_driver_lab.cpp

quick_2_lab_sort: quick_2_sort.cpp sort_driver_lab.cpp
	g++ $(CFLAGS) -o quick_2_lab_sort quick_2_sort.cpp sort_driver_lab.cpp

quick_1_lab_sort: quick_1_sort.cpp sort_driver_lab.cpp
	g++ $(CFLAGS) -o quick_1_lab_sort quick_1_sort.cpp sort_driver_lab.cpp

quick_4_sort: quick_4_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o quick_4_sort quick_4_sort.cpp sort_driver.o

quick_2_sort: quick_2_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o quick_2_sort quick_2_sort.cpp sort_driver.o

merge_1_sort: merge_1_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o merge_1_sort merge_1_sort.cpp sort_driver.o

merge_2_sort: merge_2_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o merge_2_sort merge_2_sort.cpp sort_driver.o

qsort_sort: qsort_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o qsort_sort qsort_sort.cpp sort_driver.o

bucket_0_sort: bucket_0_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o bucket_0_sort bucket_0_sort.cpp sort_driver.o

bucket_1_sort: bucket_1_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o bucket_1_sort bucket_1_sort.cpp sort_driver.o

bucket_2_sort: bucket_2_sort.cpp sort_driver.o
	g++ $(CFLAGS) -o bucket_2_sort bucket_2_sort.cpp sort_driver.o

