#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Coins {
  public:
    vector <int> v;
    int M(int i);
};

int Coins::M(int s)
{
  int i, j, val, min, sv;
  vector <int> cache;

  cache.resize(s+1);

  cache[0] = 0;
  
  for (j = 1; j <= s; j++) {
    min = s+1;

    for (i = 0; i < v.size(); i++) {
      if (j >= v[i]) {
        val = cache[j-v[i]] + 1;
        if (val != 0 && val < min) min = val;
      }
    }
    if (min == s+1) min = -1;
    cache[j] = min;
  }
  return cache[s];
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
