#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class AlienAndSetDiv2 {
  public:
    int N, K;
    vector <int> A; 
    vector <int> B;
    int DP(int next);
    int getNumber(int n, int k);
};

/* DP is a very simple procedure, which is like the Sudoku problem
   from CS140, (and CS302). It tests to see if it can insert the
   number onto A, and if so, it does so and makes a recursive call to
   DP(next+1) to count how many solutions start this way.  It does
   the same thing with B. Its base case is when we are at 2N+1. In
   that case, we've come up with an answer, and we'll return one.  */

int AlienAndSetDiv2::DP(int next)
{
  int total;
  int i;


  /* Base case -- if we have inserted all numbers from 1 to 2n, 
     then we're done, and can return 1. */

  if (next == 2*N+1) return 1;

  /* Otherwise, we're going to count solutions with recursion. */

  total = 0;

  /* First, we test to see if we can insert the number onto A.  
     If so, we do so, make a recursive call, and then remove the
     number from A. */

  if ((A.size() >= B.size() && A.size() < N) ||
      (A.size() < B.size() && next - B[A.size()] <= K)) {
    A.push_back(next);
    total += DP(next+1);
    A.pop_back();
  }

  /* We do the same thing with B. */

  if ((B.size() >= A.size() && B.size() < N) ||
      (B.size() < A.size() && next - A[B.size()] <= K)) {
    B.push_back(next);
    total += DP(next+1);
    B.pop_back();
  }

  /* When we're done, we print next, A and B, and the total. */

  printf("Next:%d A:{", next);
  for (i = 0; i < A.size(); i++) printf("%s%d", (i == 0) ? "" : ",", A[i]);
  printf("} B:{");
  for (i = 0; i < B.size(); i++) printf("%s%d", (i == 0) ? "" : ",", B[i]);
  printf("}  -- %d\n", total);

  /* And return the total. */

  return total;
}

/* getNumber() sets N and K in the class.  It clears the vectors A and B
   (which will probabaly be empty anyway), and then calls DP(1) to start
   inserting numbers with 1. */

int AlienAndSetDiv2::getNumber(int n, int k)
{
  N = n;
  K = k;

  A.clear();
  B.clear();
  
  return DP(1);
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

