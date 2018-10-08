#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
using namespace std;

#include "sorting.h"

void usage(const char *s)
{
  cerr << "usage: sort_driver size iterations seed double-check(yes|no) print(yes|no)\n";
  if (s != NULL) cerr << s << endl;
  exit(1);
}

main(int argc, const char **argv)
{
  int size;
  int iterations, it;
  int seed;
  int dc;
  int i;
  int j;
  int print;
  vector <double> v;
  double d;

  while (cin >> d) v.push_back(d);
  sort_doubles(v, 1);
}
