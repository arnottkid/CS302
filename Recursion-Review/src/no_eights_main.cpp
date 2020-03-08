#include "no_eights.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  int low, high, retval;
  class NoEights TheClass;

  if (argc != 2) {
    fprintf(stderr, "usage: bin/glossary num\n");
    fprintf(stderr, "       if num is '-' then read the numbers from standard input.\n");
    fprintf(stderr, "       if num is 0, 1, 2 and 3, then use Topcoder's examples.\n");
    exit(1);
  }

  if (strcmp(argv[1], "-") == 0) {
    if (!(cin >> low >> high)) exit(0);

  } else if (atoi(argv[1]) == 0) {
    low = 1;
    high = 10;

  } else if (atoi(argv[1]) == 1) {
    low = 88;
    high = 88;

  } else if (atoi(argv[1]) == 2) {
    low = 800;
    high = 899;

  } else if (atoi(argv[1]) == 3) {
    low = 8808;
    high = 8880;

  } else {
    exit(0);
  }

  retval = TheClass.smallestAmount(low, high);
  cout << retval << endl;

  exit(0);
}
