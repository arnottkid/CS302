#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Fib {
  public:
    int find_fib(int n);
    vector <int> cache;
};

int Fib::find_fib(int n)
{
  int i;
  if (n == 0 || n == 1)  return 1;

  cache.resize(n+1, -1);

  cache[0] = 1;
  cache[1] = 1;
  for (i = 2; i <= n; i++) cache[i] = cache[i-1] + cache[i-2];

  return cache[n];
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

