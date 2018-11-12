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
    deque <int> A; 
    int DP(int next);
    int getNumber(int n, int k);
    map < string, int > Cache;
};

/* See the lecture notes for an explanation. */

int AlienAndSetDiv2::DP(int next)
{
  long long total;
  int i ;
  int saved;
  string key;
  char buf[8];

  /* Base case -- if we have inserted all numbers from 1 to 2n, 
     then we're done.  Return 1. */

  if (next == 2*N+1) return 1;
  
  /* Create a memoization key from next and A, and check the cache. */

  sprintf(buf, "%d", next);
  key = buf;
  for (i = 0; i < A.size(); i++) {
    sprintf(buf, "-%d", A[i]);
    key += buf;
  }
  if (Cache.find(key) != Cache.end()) return Cache[key];
  
  /* Otherwise, we're going to count solutions with recursion. */

  total = 0;

  /* If the sets are the same size, that means that A is empty.
     Push the value onto A and multiply the answer by two. */

  if (A.size() == 0) {
    A.push_back(next);
    total += 2*DP(next+1);
    A.pop_back();
  }

  /* Otherwise, if there's room on A, and next is not too big, try the value on A. 
     We have to calcluate "room on A" differently, since we are not
     keeping matches.  */

  if (A.size() > 0 && next-A[0] < K && (N*2+1 - next) > A.size()) {
    A.push_back(next);
    total += DP(next+1);
    A.pop_back();
  }

  /* Now, instead of pushing the value on B, we'll remove the 
     first value from A, and put it back when the recursion is done. 
     We don't need to check whether the value is ok to put on B.  */

  if (A.size() > 0) {
    saved = A[0];
    A.pop_front();
    total += DP(next+1);
    A.push_front(saved);
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
  int rv;
  N = n;
  K = k;
  
  map <string, int>::iterator cit;

  A.clear();
  rv = DP(1);
  
/*
  for (cit = Cache.begin(); cit != Cache.end(); cit++) {
    printf("%-30s : %10d\n", cit->first.c_str(), cit->second);
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

