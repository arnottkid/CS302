#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class AlienAndSetDiv2 {
  public:
    int N, K;
    int DP(int next, int A);  /* Since A is an integer, I simply pass it to DP. */
    int getNumber(int n, int k);
    map <int, int> Cache;     /* Our memoization key is an integer, now. */
};

int AlienAndSetDiv2::DP(int next, int A)
{
  long long total;
  int i;
  int newa;
  int a_size;
  int key;
  int highval;

  /* Base case -- if we have inserted all numbers from 1 to 2n, 
     then we're done.  Return 1. */

  if (next == 2*N+1) return 1;
  
  /* Create a memoization key from next and A, and check the cache.
     The key is ((next << 12) | A).  We can do this, because A will never
     be greater than or equal to (1 << 12). */

  key = ((next << 12) | A);
  if (Cache.find(key) != Cache.end()) return Cache[key];
  
  /* Otherwise, we're going to count solutions with recursion. 
     First, calculate the size of A, and the highest bit that is set in A. */

  total = 0;
  a_size = 0;
  for (i = 0; i < 11; i++) if (A & (1 << i)) {
    a_size++;
    highval = (1 << i);
  }

  /* If the sets are the same size, that means that A is empty.
     Push the value onto A and multiply the answer by two. */

  if (a_size == 0) {
    newa = 1;
    total += 2*DP(next+1, (newa << 1));
  }

  /* Otherwise, if there's room on A, and next is not too big, try the value on A. 
     The calculation of whether "next is not too big" requires bit arithmetic.  */

  if (a_size > 0 && (1 << K) > A && (N*2+1 - next) > a_size) {
    newa = (A | 1);
    total += DP(next+1, (newa << 1));
  }

  /* Now, instead of pushing the value on B, we'll remove the 
     first value from A, and put it back when the recursion is done. 
     We "remove the first value from A" using bit arithmetic. */

  if (a_size > 0) {
    newa = (A & (~highval));
    total += DP(next+1, (newa << 1));
  }

  /* Return the total, mod 1,000,000,007. */

  Cache[key] = total % 1000000007;
  return Cache[key];
}

/* getNumber() sets N and K in the class.  It clears the vectors A and B
   (which will probabaly be empty anyway), and then calls DP(1) to start
   inserting numbers with 1. */

int AlienAndSetDiv2::getNumber(int n, int k)
{
  int rv, i;
  int next;
  int A;

  N = n;
  K = k;
  
  map <int, int>::iterator cit;

  rv = DP(1, 0);
  
  /* Printing the cache is fun.  Below, I turn the memoization key into
     next and A. */

/*
  for (cit = Cache.begin(); cit != Cache.end(); cit++) {
    next = (cit->first >> 12);
    A = (cit->first & ((1 << 12)-1));
    printf("Key: 0x%06x.  Next: %d. A:", cit->first, next);
    for (i = 0; i < 12; i++) {
      if (A & (1 << i)) printf(" %d", next-i);
    }
    printf("  -- %d\n", cit->second);
  }
 */

  return rv;
}

/* The main program reads N and K from the command line. */

int main(int argc, char **argv)
{
  class AlienAndSetDiv2 TheClass;
  int retval;
  int N;
  int K;

  if (argc != 3) { fprintf(stderr, "usage: alien-x N K\n"); exit(1); }

  N = atoi(argv[1]);
  K = atoi(argv[2]);

  retval = TheClass.getNumber(N, K);
  cout << retval << endl;

  exit(0);
}

