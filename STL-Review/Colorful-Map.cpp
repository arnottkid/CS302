#include <string>
#include <vector>
#include <map>
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
  map <char, int> s;

  for (i = 0; i < bricks.size(); i++) s[bricks[i]]++;
  if (s.size() == 1) return 1;
  if (s.size() == 2) return 2;
  return 0;
}
