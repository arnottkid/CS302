#include "colorful_bricks.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(int argc, char **argv)
{
  int ssize, nchars, i;
  string chars;
  double rn;
  class ColorfulBricks TheClass;
  int retval;
  string bricks;

  if (argc != 2) {
    fprintf(stderr, "usage: bin/colorful_bricks num\n");
    fprintf(stderr, "       if num is '-' then read the string from standard input.\n");
    fprintf(stderr, "       if num is 0, 1 or 2, then use Topcoder's examples.\n");
    fprintf(stderr, "       otherwise use num as an RNG seed and generate random input.\n");
    exit(1);
  }

  if (strcmp(argv[1], "-") == 0) {
    if (!(cin >> bricks)) exit(0);

  } else if (atoi(argv[1]) == 0) {
    bricks = "ABAB";

  } else if (atoi(argv[1]) == 1) {
    bricks = "AAA";

  } else if (atoi(argv[1]) == 2) {
    bricks = "WXYZ";

  } else {
    srand48(atoi(argv[1]));
    nchars = drand48()*4+1;
    for (i = 0; i < nchars; i++) chars.push_back('A'+drand48()*26);
    rn = drand48();
    if (rn < .5) {
      ssize = drand48() * 10 + 2;
    } else if (rn < .9) {
      ssize = drand48() * 100 + 2;
    } else if (rn < .95) {
      ssize = drand48() * 1000 + 2;
    } else {
      ssize = drand48() * 1000000 + 1;
    }
    for (i = 0; i < ssize; i++) {
      bricks.push_back(chars[drand48()*chars.size()]);
    }
  }

  retval = TheClass.countLayouts(bricks);
  cout << retval << endl;

  exit(0);
}
