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
  int i, nc;
  vector <int> s;

  s.resize('Z'+1, 0);
  nc = 0;
  for (i = 0; i < bricks.size(); i++) s[bricks[i]] = 1;
  for (i = 'A'; i <= 'Z'; i++) if (s[i] != 0) nc++;
  if (nc == 1) return 1;
  if (nc == 2) return 2;
  return 0;
}
