#include <string>
#include <vector>
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
  int i, l1, l2, n;
  vector <int> s;

  l1 = bricks[0];
  n = 1;
  
  for (i = 1; i < bricks.size(); i++) {
    if (n == 1 && bricks[i] != l1) {
      n = 2;
      l2 = bricks[i];
    } else if (n == 2 && bricks[i] != l1 && bricks[i] != l2) return 0;
  }

  if (n == 1) return 1;
  if (n == 2) return 2;
  return 0;
}
