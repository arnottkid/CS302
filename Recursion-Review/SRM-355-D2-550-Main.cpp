#include "SRM-355-D2-550.cpp"

int main(int argc, char **argv)
{
  int i;
  class NoEights TheClass;
  int retval;
  int low;
  int high;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  low = ;
  high = ;
*/


 if (atoi(argv[1]) == 0) {
    low = 1;
    high = 10;
  }

 if (atoi(argv[1]) == 1) {
    low = 88;
    high = 88;
  }

 if (atoi(argv[1]) == 2) {
    low = 800;
    high = 899;
  }

 if (atoi(argv[1]) == 3) {
    low = 8808;
    high = 8880;
  }

  retval = TheClass.smallestAmount(low, high);
  cout << retval << endl;

  exit(0);
}

