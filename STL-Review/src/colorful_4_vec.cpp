/* In this implementation, we maintain an array indexed by characters,
   and set a character's value to 1 when we see it.  At the end, we count
   up the characters that have ones to determine the answer. */

#include "colorful_bricks.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ColorfulBricks::countLayouts(const string &bricks)
{
  size_t i;
  int nc;
  vector <int> s;

  s.resize(26, 0);
  nc = 0;
  for (i = 0; i < bricks.size(); i++) s[bricks[i]-'A'] = 1;
  for (i = 0; i < 26; i++) if (s[i] != 0) nc++;
  if (nc == 1) return 1;
  if (nc == 2) return 2;
  return 0;
}
