/* The only difference here from colorful_4_vec.cpp is that we resize
   the vector to have 'Z'+1 elements, and now we can simply use the 
   character's value as an index to s. */

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

  s.resize('Z'+1, 0);
  nc = 0;
  for (i = 0; i < bricks.size(); i++) s[bricks[i]] = 1;
  for (i = 'A'; i <= 'Z'; i++) if (s[i] != 0) nc++;
  if (nc == 1) return 1;
  if (nc == 2) return 2;
  return 0;
}
