#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class ColorfulBricks {
  public:
    int countLayouts(string bricks);
};

int ColorfulBricks::countLayouts(string bricks)
{
  int i;
  int nc;

  sort(bricks.begin(), bricks.end());

  nc =  1;
  for (i = 1; i < bricks.size(); i++) if (bricks[i] != bricks[i-1]) nc++;
  if (nc == 1) return 1;
  if (nc == 2) return 2;
  return 0;
}
