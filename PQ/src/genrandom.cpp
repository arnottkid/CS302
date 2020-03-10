/* This program generates n random doubles. */

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  int i;
  int n;

  if (argc != 2) {
    cerr << "usage: genrandom n\n";
    exit(1);
  }

  srand48(time(0));
  n = atoi(argv[1]);

  for (i = 0 ; i < n; i++) cout << drand48() << endl;

  return 0;
}
