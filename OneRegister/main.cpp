#include "OneRegister.cpp"

int main(int argc, char **argv)
{
  int i;
  class OneRegister TheClass;
  string retval;
  int s;
  int t;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  s = ;
  t = ;
*/


 if (atoi(argv[1]) == 0) {
    s = 7;
    t = 392;
  }

 if (atoi(argv[1]) == 1) {
    s = 7;
    t = 256;
  }

 if (atoi(argv[1]) == 2) {
    s = 4;
    t = 256;
  }

 if (atoi(argv[1]) == 3) {
    s = 7;
    t = 7;
  }

 if (atoi(argv[1]) == 4) {
    s = 7;
    t = 9;
  }

 if (atoi(argv[1]) == 5) {
    s = 10;
    t = 1;
  }

  retval = TheClass.getProgram(s, t);
  cout << retval << endl;

  exit(0);
}
