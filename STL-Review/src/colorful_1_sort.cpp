/* ColorfulBricks solution #1: Sort the bricks, and determine how
   many adjacent characters differ. */ 

#include "colorful_bricks.hpp"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int ColorfulBricks::countLayouts(const string &bricks)
{
  size_t i;
  int nc;
  string sorted_bricks; // Since bricks is const, I have to make a copy to sort.

  /* Sort the bricks using sort() from the C++ algorithms library. */

  sorted_bricks = bricks;
  sort(sorted_bricks.begin(), sorted_bricks.end());

  /* Determine how many different characters there are by
     examining adjacent characters in the sorted string. */

  nc =  1;
  for (i = 1; i < sorted_bricks.size(); i++) {
    if (sorted_bricks[i] != sorted_bricks[i-1]) nc++;
  }

  /* There are three outcomes: 
      - One character = one nice string.
      - Two characters = two nice strings.
      - More than two characters = zero nice strings. */

  if (nc == 1) return 1;
  if (nc == 2) return 2;
  return 0;
}
