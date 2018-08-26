#include "ColorfulBricks.cpp"

int main(int argc, char **argv)
{
  int i;
  class ColorfulBricks TheClass;
  int retval;
  string bricks;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  bricks = ;
*/


 if (atoi(argv[1]) == 0) {
    bricks = "ABAB";
  }

 if (atoi(argv[1]) == 1) {
    bricks = "AAA";
  }

 if (atoi(argv[1]) == 2) {
    bricks = "WXYZ";
  }

  retval = TheClass.countLayouts(bricks);
  cout << retval << endl;

  exit(0);
}
