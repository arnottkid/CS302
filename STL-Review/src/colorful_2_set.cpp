/* Here we create a set of the characters in bricks.  Since
   sets do not store duplicate elements, the size of the set
   will equal the number of distinct characters. */

#include "colorful_bricks.hpp"
#include <string>
#include <set>
#include <iostream>
using namespace std;

int ColorfulBricks::countLayouts(const string &bricks)
{
  size_t i;
  set <char> s;

  for (i = 0; i < bricks.size(); i++) s.insert(bricks[i]);
  if (s.size() == 1) return 1;
  if (s.size() == 2) return 2;
  return 0;
}
