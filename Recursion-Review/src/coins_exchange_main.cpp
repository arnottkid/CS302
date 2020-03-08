/* This is a driver program for Topcoder SRM 351, D1, 250-Pointer: CoinsExchange. */

#include "coins_exchange.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  CoinsExchange TheClass;
  int retval;
  int G1;
  int S1;
  int B1;
  int G2;
  int S2;
  int B2;

  if (argc != 2) { fprintf(stderr, "usage: a.out num or -\n"); exit(1); }

  if (strcmp(argv[1], "-") == 0) {
    if (!(cin >> G1 >> S1 >> B1 >> G2 >> S2 >> B2)) exit(0);

  } else if (atoi(argv[1]) == 0) {
    G1 = 1;
    S1 = 0;
    B1 = 0;
    G2 = 0;
    S2 = 0;
    B2 = 81;

  } else if (atoi(argv[1]) == 1) {
    G1 = 1;
    S1 = 100;
    B1 = 12;
    G2 = 5;
    S2 = 53;
    B2 = 33;

  } else if (atoi(argv[1]) == 2) {
    G1 = 1;
    S1 = 100;
    B1 = 12;
    G2 = 5;
    S2 = 63;
    B2 = 33;

  } else if (atoi(argv[1]) == 3) {
    G1 = 5;
    S1 = 10;
    B1 = 12;
    G2 = 3;
    S2 = 7;
    B2 = 9;
  } else {
    exit(0);
  }

  retval = TheClass.countExchanges(G1, S1, B1, G2, S2, B2);
  cout << retval << endl;

  exit(0);
}
