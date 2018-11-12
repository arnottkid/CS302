#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class PageNumbers {
  public:
   vector <int> getCounts(int N);
};

vector <int> PageNumbers::getCounts(int N)
{
  vector <int> rv;
  int i;

  /* We're only solving the base case -- when N is a one-digit number. */

  if (N < 10) {
    rv.resize(10, 0);
    for (i = 1; i <= N; i++) rv[i] = 1;
    return rv;
  }
 
  printf("We haven't solved the problem for N >= 10 yet.\n");
  return rv; 
}

/* Our main() reads N from the command line, and calls getCounts().
   It prints the return vector. */

int main(int argc, char **argv)
{
  int i;
  PageNumbers c;
  int N, d;
  vector <int> retval;

  if (argc != 2) {
    fprintf(stderr, "usage: PageNumbers N\n");
    exit(1);
  }

  N = atoi(argv[1]);

  retval = c.getCounts(N);
  if (retval.size() == 0) exit(0);
  printf("Answer:");
  for (i = 0; i < retval.size(); i++) printf(" %d", retval[i]);
  cout << endl;

  exit(0);
}
