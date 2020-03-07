/* This solution is like the set, but uses a map because the
   syntax is easier.  The map counts occurrences of each 
   character, but that's not used to solve the problem. */

#include "colorful_bricks.hpp"
#include <string>
#include <map>
#include <iostream>
using namespace std;

int ColorfulBricks::countLayouts(const string &bricks)
{
  size_t i;
  map <char, int> s;

  for (i = 0; i < bricks.size(); i++) s[bricks[i]]++;
  if (s.size() == 1) return 1;
  if (s.size() == 2) return 2;
  return 0;
}
