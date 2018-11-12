#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class PageNumbers {
  public:
   vector <int> getCounts(int N);
   map < int, vector <int> > Cache;
};

vector <int> PageNumbers::getCounts(int N)
{
  vector <int> rv, rv2;  /* I've added rv2 for the recursion. */
  int i, d;
  char buf[20];
  string n_str;
  int first_digit;        /* The first digit of N. */
  int digits;             /* The number of digits in N. */
  int middle_number;      /* This number has the same first digit of N, followed by zeros. */
  int remainder;          /* This is (N-middle_number). */

  /* Base case -- when N is a single-digit number. */

  if (N < 10) {
    rv.resize(10, 0);
    for (i = 1; i <= N; i++) rv[i] = 1;
    return rv;
  }

  /* Get the answer from the Cache if it's there. */

  if (Cache.find(N) != Cache.end()) return Cache[N];

  /* Convert N to a string using sprintf(). */

  sprintf(buf, "%d", N);
  n_str = buf;

  /* Now calculate first_digit, digits, middle_number and remainder. */

  first_digit = n_str[0] - '0';
  digits = n_str.size();
  for (i = 1; i < digits; i++) n_str[i] = '0';
  middle_number = atoi(n_str.c_str());
  remainder = N - middle_number;

  /* Print them out. */

  printf("First digit   = %10d\n", first_digit);
  printf("Digits        = %10d\n", digits);
  printf("Middle number = %10d\n", middle_number);
  printf("Remainder     = %10d\n", remainder);

  /* Make the first recursive call to middle_number-1 */

  rv = getCounts(middle_number-1);

  /* Add in the answer for middle_number. */

  rv[first_digit]++;
  for (i = 0; i < digits-1; i++) rv[0]++;

  /* Add the first digit of (middle_number+1) to N: */

  rv[first_digit] += remainder;

  /* Now, call this recursively on remainder, and count up how
     many digits that is.  Subtract this from (digits-1)*remainder to get
     the number of leading zeros that you're missing.  Then 
     add everything to the final return value. */

  rv2 = getCounts(remainder);
  d = 0;
  for (i = 0; i < rv2.size(); i++) d += rv2[i];
  rv[0] += ((digits-1)*remainder - d);
  for (i = 0; i < rv2.size(); i++) rv[i] += rv2[i];

  /* Insert the answer into the cache before returning. */

  Cache[N] = rv;

  return rv;
}

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
  printf("Answer:");
  for (i = 0; i < retval.size(); i++) printf(" %d", retval[i]);
  cout << endl;

  exit(0);
}
