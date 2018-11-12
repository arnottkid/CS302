/* This one is even faster than alien-5.
   It's uncommented though -- ha ha.
   I'll comment it sometime when I'm bored. */

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class AlienAndSetDiv2 {
  public:
    vector < vector <int> > Cache;
    int N, K;
    int DP(int next, int m);
    int getNumber(int n, int k);
};

int AlienAndSetDiv2::DP(int next, int m)
{
  long long total;
  int i;
  int bigdiff;

  if (next == 2*N+1) {
    if (m == 0) return 1;
    return 0;
  }

  if (Cache[next][m] != -1) return Cache[next][m];

  if (m == 0) {
    total = 2*DP(next+1, 1);
    total %= 1000000007;
    Cache[next][m] = total;
    // printf("%d - %d = %lld\n", next, m, total);
    return total;
  }
    
  total = 0;
  bigdiff = 0;
  for (i = m; i != 0; i >>= 1) bigdiff++;
  if (bigdiff < K) total += DP(next+1, (m << 1) | 1);
    
  total += DP(next+1, (m << 1) & ((1 << bigdiff)-1));
  
  // printf("%d - %d = %lld\n", next, m, total);
  Cache[next][m] = total % 1000000007;
  return (total % 1000000007);
}

int AlienAndSetDiv2::getNumber(int n, int k)
{
  int i;

  N = n;
  K = k;
  
  Cache.resize(2*N+1);
  for (i = 0; i < Cache.size(); i++) Cache[i].resize(1024, -1);

  return DP(1, 0);
}


int main(int argc, char **argv)
{
  class AlienAndSetDiv2 TheClass;
  int retval;
  int N;
  int K;

  if (argc != 3) { fprintf(stderr, "usage: alien-x N K\n"); exit(1); }

  N = atoi(argv[1]);
  K = atoi(argv[2]);

  retval = TheClass.getNumber(N, K);
  cout << retval << endl;

  exit(0);
}
