#include "ThreeTeleports.cpp"

int main(int argc, char **argv)
{
  int i;
  class ThreeTeleports TheClass;
  int retval;
  int xMe;
  int yMe;
  int xHome;
  int yHome;
  vector <string> teleports;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  xMe = ;
  yMe = ;
  xHome = ;
  yHome = ;
  teleports = ;
*/


 if (atoi(argv[1]) == 0) {
    xMe = 3;
    yMe = 3;
    xHome = 4;
    yHome = 5;
    teleports.push_back("1000 1001 1000 1002");
    teleports.push_back( "1000 1003 1000 1004");
    teleports.push_back( "1000 1005 1000 1006");
  }

 if (atoi(argv[1]) == 1) {
    xMe = 0;
    yMe = 0;
    xHome = 20;
    yHome = 20;
    teleports.push_back("1 1 18 20");
    teleports.push_back( "1000 1003 1000 1004");
    teleports.push_back( "1000 1005 1000 1006");
  }

 if (atoi(argv[1]) == 2) {
    xMe = 0;
    yMe = 0;
    xHome = 20;
    yHome = 20;
    teleports.push_back("1000 1003 1000 1004");
    teleports.push_back( "18 20 1 1");
    teleports.push_back( "1000 1005 1000 1006");
  }

 if (atoi(argv[1]) == 3) {
    xMe = 10;
    yMe = 10;
    xHome = 10000;
    yHome = 20000;
    teleports.push_back("1000 1003 1000 1004");
    teleports.push_back( "3 3 10004 20002");
    teleports.push_back( "1000 1005 1000 1006");
  }

 if (atoi(argv[1]) == 4) {
    xMe = 3;
    yMe = 7;
    xHome = 10000;
    yHome = 30000;
    teleports.push_back("3 10 5200 4900");
    teleports.push_back( "12212 8699 9999 30011");
    teleports.push_back( "12200 8701 5203 4845");
  }

 if (atoi(argv[1]) == 5) {
    xMe = 0;
    yMe = 0;
    xHome = 1000000000;
    yHome = 1000000000;
    teleports.push_back("0 1 0 999999999");
    teleports.push_back( "1 1000000000 999999999 0");
    teleports.push_back( "1000000000 1 1000000000 999999999");
  }

  retval = TheClass.shortestDistance(xMe, yMe, xHome, yHome, teleports);
  cout << retval << endl;

  exit(0);
}
