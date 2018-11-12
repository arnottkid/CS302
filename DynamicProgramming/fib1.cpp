#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Fib {
  public:
    int find_fib(int n);
};

int Fib::find_fib(int n)
{
  if (n == 0 || n == 1) return 1;
  return find_fib(n-1) + find_fib(n-2);
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
