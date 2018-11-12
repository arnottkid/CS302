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
  if (cache.size() == 0) cache.resize(n+1, -1);
  if (cache[n] != -1) return cache[n];
  if (n == 0 || n == 1) {
    cache[n] = 1;
  } else {
    cache[n] = find_fib(n-1) + find_fib(n-2);
  }
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

