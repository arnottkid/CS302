/* Recursive solution to Topcoder SRM 355, D2, 550-Pointer: No-Eights
   James S. Plank
   September, 2011
 */

/* This is a classic recursive problem.  First, convert both
   numbers to 10-digit strings such that the strings represent the
   numbers with leading zeros.  Then, process the digits from left
   to right in the recursive procedure NE(l, h, index):

   - if index equals the strings' size, then we're done.  Return 0.
   - if l[index] != r[index], then return 0.  Why?  Suppose l[index] = x,
     and x does not equal 8.  Then x followed by index-1 nines is 
     a number in the set, and it doesn't have any 8's.  If x does equal
     8, then 9 followed by index-1 zeroes is in the set.  In either case,
     you can return 0.
   - if l[index] == r[index] and they equal 8, then you answer is one
     plus NE(l, r, index+1), since that digit has to equal 8.
   - if l[index] == r[index] and they don't equal 8, then your answer
     is NE(l, r, index+1), because that digit cannot equal 8.

   While you can solve this pretty easily without recursion, recursion,
   at least for me, makes the thought process cleaner.
 */

#include "no_eights.hpp"
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int NE(const string &l, const string &h, size_t index)
{
  if (index == l.size()) return 0;
  if (l[index] != h[index]) return 0;

  if (l[index] == '8') return 1 + (NE(l, h, index+1));
  return 0 + (NE(l, h, index+1));
}

int NoEights::smallestAmount(int low, int high)
{
  char b[20];
  string l, h;

  /* Convert each number to 10-digit strings using sprintf(). */

  sprintf(b, "%010d", low);
  l = b;
  sprintf(b, "%010d", high);
  h = b;

  /* Call the recursive procedure NE() on the strings. */

  return NE(l, h, 0);
}
