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
 
  /* Convert N to a string using sprintf(). */

  sprintf(buf, "%d", N);
  n_str = buf;

  /* Now calculate first_digit, digits, middle_number and remainder. */

  first_digit = n_str[0] - '0';
  digits = n_str.size();
  for (i = 1; i < digits; i++) n_str[i] = '0';
  middle_number = atoi(n_str.c_str());
  remainder = N - middle_number;

  /* Print them out and exit. */

  printf("First digit   = %10d\n", first_digit);
  printf("Digits        = %10d\n", digits);
  printf("Middle number = %10d\n", middle_number);
  printf("Remainder     = %10d\n", remainder);

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
