/* Solution to Topcoder SRM 351, D1, 250-Pointer: CoinsExchange.
   James S. Plank
   September, 2011
   Please see lecture notes in http://web.eecs.utk.edu/~plank/plank/classes/cs302/Notes/Recursion-Review/index.html for explanation.
 */

#include "coins_exchange.hpp"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int CoinsExchange::countExchanges(int G1, int S1, int B1, int G2, int S2, int B2)
{
  int s;
  int x;
  int fromgold;
  int needsilver;

  printf("%s We have:  G1: %3d   S1: %3d   B1: %3d\n", nest.c_str(), G1, S1, B1);
  printf("%s We want:  G2: %3d   S2: %3d   B2: %3d\n", nest.c_str(), G2, S2, B2);

  /* Case #1 - We need gold */

  if (G2 > G1) {
    printf("%s Recursively trying to get %d gold from %d silver\n\n", 
       nest.c_str(), (G2-G1), (G2-G1)*11);
    nest += "****";
    s = countExchanges(0, S1, B1, 0, S2 + 11*(G2-G1), B2);
    nest.resize(nest.size()-4);
    if (s >= 0) s += (G2-G1);
    printf("%s After recursively trying to get gold, returning %d\n\n", nest.c_str(), s);
    return s;
  }

  /* Case #2 - We need bronze */

  if (B2 > B1) {
    x = (B2 - B1 + 8) / 9;   // This is how many silver we need.
    printf("%s Recursively trying to get %d bronze from %d silver\n\n", 
      nest.c_str(), (B2-B1), x);
    nest += "****";
    s = countExchanges(G1, S1, 0, G2, S2 + x, 0);
    nest.resize(nest.size()-4);
    if (s >= 0) s += x;
    printf("%s After recursively trying to get bronze, returning %d\n\n", nest.c_str(), s);
    return s;
  }

  /* Case #3 - We have enough silver -- we're done */

  if (S2 <= S1) {
    printf("%s We have enough silver, returning %d\n\n", nest.c_str(), 0);
    return 0;
  }

  /* Case #4 - Calculate how much gold we need.  If we have enough, we're done: */

  needsilver = S2 - S1;
  x = (needsilver + 8) / 9;
  if (G1-G2 >= x) {
    printf("%s We can satisfy silver from gold, returning %d\n\n", nest.c_str(), x);
    return x;
  }

  /* If we don't then take what gold we can, and get the rest from bronze. */

  fromgold = (G1 > G2) ? (G1 - G2) : 0;
  needsilver -= fromgold*9;
  
  if (B1-B2 >= 11*needsilver) {
    x = needsilver + fromgold;
    printf("%s We can satisfy silver from %d gold and %d bronze: returning %d\n\n", 
           nest.c_str(), fromgold, needsilver*11, x);
    return x;
  }
  printf("%s We don't have enough gold and bronze to get silver: returning %d\n\n", 
           nest.c_str(), -1);
  return -1;
}
