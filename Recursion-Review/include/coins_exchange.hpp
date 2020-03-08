/* Header file for Topcoder SRM 351, D1, 250-Pointer: CoinsExchange */

#include <string>

class CoinsExchange {
  public:
    int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2);

  protected:               /* I've added this variable to help print out the state. */
    std::string nest;
};
