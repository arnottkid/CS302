#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Coins {
  public:
    vector <int> v;
    vector <int> cache;
    int M(int i);
};

int Coins::M(int s)
{
  int i, j, min, sv;

  if (cache.size() <= s) cache.resize(s+1, -2);
  if (cache[s] != -2) return cache[s];

  if (s == 0) {
    cache[s] = 0;
    return 0;
  }

  min = s+1;

  for (i = 0; i < v.size(); i++) {
    if (s >= v[i]) {
      j = M(s-v[i]) + 1;
      if (j != 0 && j < min) min = j;
    }
  }
  if (min == s+1) min = -1;
  cache[s] = min;
  return min;
}

int main(int argc, char **argv)
{
  Coins c;
  int i;
  int sum;

  if (argc != 2) {
    cerr << "usage: coins s -- values on standard input\n";
    exit(1);
  }
  sum = atoi(argv[1]);
  while (cin >> i) c.v.push_back(i);

  cout << c.M(sum) << endl;
}
