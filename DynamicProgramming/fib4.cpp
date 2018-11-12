#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Fib {
  public:
    int find_fib(int n);
};

int Fib::find_fib(int n)
{
  int v[3];
  int i;

  if (n == 0 || n == 1) return 1;

  v[0] = 1;
  v[1] = 1;
  for (i = 2; i <= n; i++) {
    v[2] = v[0] + v[1];
    v[0] = v[1];
    v[1] = v[2];
  }

  return v[2];
}

int main(int argc, char **argv)
{
  Fib f;

  if (argc != 2) {
    cerr << "usage: fib n\n";
    exit(1);
  }

  cout << f.find_fib(atoi(argv[1])) << endl;
}

