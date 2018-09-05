#include "SRM-351-D1-250.cpp"

int main(int argc, char **argv)
{
  int i;
  class CoinsExchange TheClass;
  int retval;
  int G1;
  int S1;
  int B1;
  int G2;
  int S2;
  int B2;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  G1 = ;
  S1 = ;
  B1 = ;
  G2 = ;
  S2 = ;
  B2 = ;
*/


 if (atoi(argv[1]) == 0) {
    G1 = 1;
    S1 = 0;
    B1 = 0;
    G2 = 0;
    S2 = 0;
    B2 = 81;
  }

 if (atoi(argv[1]) == 1) {
    G1 = 1;
    S1 = 100;
    B1 = 12;
    G2 = 5;
    S2 = 53;
    B2 = 33;
  }

 if (atoi(argv[1]) == 2) {
    G1 = 1;
    S1 = 100;
    B1 = 12;
    G2 = 5;
    S2 = 63;
    B2 = 33;
  }

 if (atoi(argv[1]) == 3) {
    G1 = 5;
    S1 = 10;
    B1 = 12;
    G2 = 3;
    S2 = 7;
    B2 = 9;
  }

  retval = TheClass.countExchanges(G1, S1, B1, G2, S2, B2);
  cout << retval << endl;

  exit(0);
}
