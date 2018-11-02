#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class ThreeTeleports {
  public:
    int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports);
};

int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, 
                                     vector <string> teleports)
{
  vector <long long> X, Y;
  vector < vector <long long> >AM;
  int i, j, x1, x2, y1, y2;
  long long xd, yd;
  vector <int> path;
  long long minimum, d;

  /* Create the vectors X and Y, which hold the x and y coordinates of the eight
     locations that we care about. */

  X.push_back(xMe);
  Y.push_back(yMe);

  for (i = 0; i < teleports.size(); i++) {
    sscanf(teleports[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
    X.push_back(x1);
    Y.push_back(y1);
    X.push_back(x2);
    Y.push_back(y2);
  }

  X.push_back(xHome);
  Y.push_back(yHome);
  
  /* Create the adjacency matrix. */

  AM.resize(X.size());
  for (i = 0; i < X.size(); i++) {
    for (j = 0; j < X.size(); j++) {
      xd = X[j]-X[i];
      if (xd < 0) xd = -xd;
      yd = Y[j]-Y[i];
      if (yd < 0) yd = -yd;
      AM[i].push_back(xd+yd);
    }
  }

  /* Add the teleports to the adjacency matrix. */

  AM[1][2] = 10;
  AM[2][1] = 10;
  AM[3][4] = 10;
  AM[4][3] = 10;
  AM[5][6] = 10;
  AM[6][5] = 10;

  /* Generate and print the permutations of 1-7. 
     We do that with a vector containing the numbers 0 through 7,
     and keep calling next_permutation() until path[0] changes from 0 to 1.
   */
   
  minimum = 0x1000000000LL;   /* This number is 2^36. */
  printf("%lld\n", AM[0][7]);

  for (i = 0; i < 8; i++) path.push_back(i);
  while (path[0] == 0) {
    d = 0;
    for (i = 0; path[i] != 7; i++) {
      d += AM[path[i]][path[i+1]];
    }
    if (d < minimum) minimum = d;
    next_permutation(path.begin(), path.end());
  }
  
  return minimum;
}
