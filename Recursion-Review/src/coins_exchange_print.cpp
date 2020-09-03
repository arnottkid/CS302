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
  int rv;

  int gold_deficit;
  int gold_excess;
  int silver_deficit;
  int silver_excess;
  int bronze_deficit;
  int bronze_excess;

  int need_gold;
  int need_silver;
  int need_bronze;

  printf("We have:  G1: %3d   S1: %3d   B1: %3d\n", G1, S1, B1);
  printf("We want:  G2: %3d   S2: %3d   B2: %3d\n", G2, S2, B2);
  printf("\n");

  /* Determine our deficit coins and our excess coins. */

  gold_deficit = (G2 - G1 > 0) ? G2 - G1 : 0;
  gold_excess  = (G1 - G2 > 0) ? G1 - G2 : 0;

  silver_deficit = (S2 - S1 > 0) ? S2 - S1 : 0;
  silver_excess  = (S1 - S2 > 0) ? S1 - S2 : 0;
  (void) silver_excess;        // We actually never use this, so this silences the compiler.

  bronze_deficit = (B2 - B1 > 0) ? B2 - B1 : 0;
  bronze_excess  = (B1 - B2 > 0) ? B1 - B2 : 0;

  /* Base case -- if there are no deficits, then return 0. */

  if (gold_deficit == 0 && silver_deficit == 0 && bronze_deficit == 0) {
    printf("Our needs are met -- returning 0\n\n");
    return 0;
  }

  /* First issue -- if we need gold, we have to get it from silver.
     So, calculate how much silver we need, and make a recursive call to
     see how many transactions are needed to get it.  If it's possible,
     then add the number of transactions for the gold (which is the number of
     gold we need) and return it.  */

  if (gold_deficit > 0) {
    need_silver = 11 * gold_deficit;
    printf("Our gold deficit is %d and we need %d silver.  Making a recursive call.\n\n",
            gold_deficit, need_silver);
    rv = countExchanges(0, S1, B1, 0, S2+need_silver, B2);
    if (rv == -1) return -1;
    printf("We recursively got %d silver to convert to %d gold.  RV=%d.  Returning %d+%d = %d\n\n",
           need_silver, gold_deficit, rv, rv, gold_deficit, (rv+gold_deficit));
    return rv+gold_deficit;
  }

  /* Second issue -- if we need bronze, then we also have to get it from silver.
     So, calculate how much silver we need, and make a recursive call to
     see how many transactions are needed to get it.  If it's possible,
     then add the number of transactions for the bronze (which is the number of
     silver that we exchanged) and return it.  */

  if (bronze_deficit > 0) {
    need_silver = (bronze_deficit + 8) / 9;
    printf("Our bronze deficit is %d and we need %d silver.  Making a recursive call.\n\n",
            bronze_deficit, need_silver);
    rv = countExchanges(G1, S1, 0, G2, S2+need_silver, 0);
    if (rv == -1) return -1;
    printf("We recursively got %d silver to convert to %d gold.  RV=%d.  Returning %d+%d = %d\n\n",
           need_silver, bronze_deficit, rv, rv, need_silver, (rv+need_silver));
    return rv+need_silver;
  }

  /* If we have reached this point, we need silver.  If we have excess gold,
     let's get as much silver as we can from gold.  If that solves the problem, 
     then we return.  If it doesn't then we recursively solve it taking gold
     out of the equation. */

  if (gold_excess > 0) {
    need_gold = (silver_deficit + 8) / 9;
    if (need_gold <= gold_excess) {
      printf("We can satisfy %d silver with %d gold.  Returning %d.\n\n",
             silver_deficit, need_gold, need_gold);
      return need_gold;
    }
    printf("We can satisfy %d silver with %d gold, but need to get more from bronze recursively.\n\n",
             gold_excess*9, gold_excess);
    rv = countExchanges(0, S1, B1, 0, S2-gold_excess*9, B2);
    if (rv == -1) return -1;
    printf("We got %d silver from %d gold and %d bronze transactions.  Returning %d.\n\n",
           silver_deficit, gold_excess, rv, gold_excess+rv);
    return gold_excess+rv;
  }

  /* Now, if we have reached this point, we need silver and we have no gold.  We have
     to get it from bronze. */

  need_bronze = silver_deficit * 11;
  if (need_bronze <= bronze_excess) {
    printf("We can convert %d bronze to %d silver.  Returning %d.\n\n",
           need_bronze, silver_deficit, silver_deficit);
    return silver_deficit;
  }

  /* If we have reached this point, then it's impossible. */

  printf("We need %d silver but only have %d bronze.  Return -1.\n\n",
          silver_deficit, bronze_excess);
  return -1;
}
