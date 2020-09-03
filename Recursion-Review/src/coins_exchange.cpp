/* Solution to Topcoder SRM 351, D1, 250-Pointer: CoinsExchange.
   James S. Plank
   September, 2020
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
  int gold_excess, silver_excess, bronze_excess;      // Excess coins
  int gold_deficit, silver_deficit, bronze_deficit;   // Coins where I have a deficit

  int rv;                                         // Return value from recursive calls
  int need_silver, need_gold, need_bronze;        // How many coins to I need to get recursively

  /* Determine our deficit coins and our excess coins. */

  gold_deficit = (G2 - G1 > 0) ? G2 - G1 : 0;
  gold_excess  = (G1 - G2 > 0) ? G1 - G2 : 0;

  silver_deficit = (S2 - S1 > 0) ? S2 - S1 : 0;
  silver_excess  = (S1 - S2 > 0) ? S1 - S2 : 0;
  (void) silver_excess;   // We actually never use this, so this silences the compiler

  bronze_deficit = (B2 - B1 > 0) ? B2 - B1 : 0;
  bronze_excess  = (B1 - B2 > 0) ? B1 - B2 : 0;

  /* Base case -- if there are no deficits, then return 0. */

  if (gold_deficit == 0 && silver_deficit == 0 && bronze_deficit == 0) {
    return 0;
  }

  /* First issue -- if we need gold, we have to get it from silver.
     So, calculate how much silver we need, and make a recursive call to
     see how many transactions are needed to get it.  If it's possible,
     then add the number of transactions for the gold (which is the number of
     gold we need) and return it.  */

  if (gold_deficit > 0) {
    need_silver = 11 * gold_deficit;
    rv = countExchanges(0, S1, B1, 0, S2+need_silver, B2);
    if (rv == -1) return -1;
    return rv+gold_deficit;
  }

  /* Second issue -- if we need bronze, then we also have to get it from silver.
     So, calculate how much silver we need, and make a recursive call to
     see how many transactions are needed to get it.  If it's possible,
     then add the number of transactions for the bronze (which is the number of
     silver that we exchanged) and return it.  */

  if (bronze_deficit > 0) {
    need_silver = (bronze_deficit + 8) / 9;
    rv = countExchanges(G1, S1, 0, G2, S2+need_silver, 0);
    if (rv == -1) return -1;
    return rv+need_silver;
  }

  /* If we have reached this point, we need silver.  If we have excess gold,
     let's get as much silver as we can from gold.  If that solves the problem,
     then we return.  If it doesn't then we recursively solve it, taking gold
     out of the equation. */

  if (gold_excess > 0) {
    need_gold = (silver_deficit + 8) / 9;
    if (need_gold <= gold_excess) return need_gold;
    rv = countExchanges(0, S1, B1, 0, S2-gold_excess*9, B2);
    if (rv == -1) return -1;
    return gold_excess+rv;
  }

  /* Now, if we have reached this point, we need silver and we have no gold.  We have
     to get it from bronze. */

  need_bronze = silver_deficit * 11;
  if (need_bronze <= bronze_excess) return silver_deficit;

  /* If we have reached this point, then it's impossible. */
  return -1;
}
