/* This is the simplest implementation, data-structure wise -- we just
   keep track of two characters -- the first one that we encounter, and
   the second one that we encounter that is different from the first.
   If we see a third character, we're done and return zero.  Otherwise, 
   we return 1 or 2 depending on whether or not we saw a second character. */

#include "colorful_bricks.hpp"
#include <string>
#include <iostream>
using namespace std;

int ColorfulBricks::countLayouts(const string &bricks)
{
  size_t i;
  int n_distinct;
  char c1, c2;

  /* c1 is the first character.
     c2 is the second character.
     n_distinct is the number of distinct characters we have seen so far. */

  c1 = bricks[0];
  n_distinct = 1;
  
  for (i = 1; i < bricks.size(); i++) {
    if (n_distinct == 1 && bricks[i] != c1) {
      n_distinct = 2;
      c2 = bricks[i];
    } else if (n_distinct == 2 && bricks[i] != c1 && bricks[i] != c2) return 0;
  }

  if (n_distinct == 1) return 1;
  if (n_distinct == 2) return 2;
  return 0;
}
