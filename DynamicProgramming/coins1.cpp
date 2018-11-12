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
  int i, j, min, sv;

  /* We initialize the minimum by sentinelizing it to an impossible value. */

  min = s+1;

  /* Loop through all of the coins. */

  for (i = 0; i < v.size(); i++) {

    /* If our sum equals a coin, then we're done -- return one. */

    if (s == v[i]) return 1;

    /* Otherwise, simulate using the coin by calling M() on the
       sum minus the coin's value.   If that's better than 
       our current minimum, update the minimum. */
    if (s > v[i]) {
      j = M(s-v[i]) + 1;
      if (j != 0 && j < min) min = j;
    }
  }

  /* The min equals the sentinel, then it's impossible, return -1. 
     Otherwise, return the minimum. */

  if (min == s+1) return -1;
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
