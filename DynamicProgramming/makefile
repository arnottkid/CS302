ALL = \
     fib1 fib2 fib3 fib4 \
     coins1 coins2 coins3 \
     subseq1 subseq2 subseq3 subseq4 subseq5 subseq6 \
     ConvertibleStrings \
     page-numbers-1 page-numbers-2 page-numbers-3 page-numbers-4 page-numbers-5 \
     alien-1 alien-2 alien-3 alien-4 alien-5 alien-6 \
     apples1 apples2 apples3 

all: $(ALL)

clean:
	rm -f *.o $(ALL)

.SUFFIXES: .cpp .o 

.cpp.o: 
	g++ -O3 -c $*.cpp

.cpp:
	g++ -o $* $*.cpp 
