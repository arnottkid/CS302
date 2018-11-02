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
  int i, x1, x2, y1, y2;

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
  
  /* We use %lld to print out long long's using printf(). */

  for (i = 0; i < X.size(); i++) printf("[%lld,%lld]\n", X[i], Y[i]);

  return 0;
}
