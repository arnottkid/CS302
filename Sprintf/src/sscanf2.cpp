#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* This program reads a line of text with getline(), and then
   uses sscanf() which attempts to read the string as a double,
   followed by a space, and an integer.  The number of correct
   "matches" is returned from sscanf().  This program prints the
   number of matches, and then the double and integer.   If sscanf()
   was unseccessful with a conversion, then the double and/or 
   integer will remain as uninitialized variables. */

int main()
{
  string s;
  int i, n;
  double d;
  

  getline(cin, s);
  n = sscanf(s.c_str(), "%lf %d", &d, &i);
  printf("n = %d.  d = %lf.  i = %d\n\n", n, d, i);
  return 0;
}
