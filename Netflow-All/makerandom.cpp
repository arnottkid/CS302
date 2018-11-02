#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
  int nnodes;
  int i, j;
  int cap;

  if (argc != 2 && argc != 3) {
    fprintf(stderr, "makerandom nnodes [seed]\n");
    exit(1);
  }

  nnodes = atoi(argv[1]);
  if (argc == 2) {
    srand48(time(0));
  } else {
    srand48(atoi(argv[2]));
  }

  printf("SOURCE s\n");
  printf("SINK t\n");

  for (i = 0; i < nnodes; i++) {
    j = lrand48()%10;
    cap = lrand48()%10000+1;
    if (j < 4) {
      printf("EDGE s n%02d %d\n", i, cap);
    } else if (j < 8) {
      printf("EDGE n%02d t %d\n", i, cap);
    }

    for (j = i+1; j < nnodes; j++) {
      cap = lrand48()%10000+1;
      
      if (drand48() < .5) {
        printf("EDGE n%02d n%02d %d\n", i, j, cap);
      } else {
        printf("EDGE n%02d n%02d %d\n", j, i, cap);
      }
    }
  }
  exit(0);
}
