#include <vector>
#include <cstdlib>
#include <cstdio>
#include <map>
#include "disjoint.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  int r, c, row, column, c1, c2, ncomp, s1, s2, hov;
  DisjointSet *d;
  map <double, int> walls;
  map <double, int>::iterator wit;
  map <double, int>::iterator tmp;

  /* Parse the command line and create the instance of the disjoint set. */

  if (argc != 4) { 
    fprintf(stderr, "usage mazegen rows cols size|height|rank\n"); exit(1); }
  
  r = atoi(argv[1]);
  c = atoi(argv[2]);

  switch(argv[3][0]) {
    case 's': d = new DisjointSetBySize(r*c); break;
    case 'h': d = new DisjointSetByHeight(r*c); break;
    case 'r': d = new DisjointSetByRankWPC(r*c); break;
    default: fprintf(stderr, "Bad last argument.  Should be s|h|r.\n"); exit(1);
  }

  /* Generate walls that separate vertical cells. */

  for (row = 0; row < r-1; row++) {
    for (column = 0; column < c; column++) {
      c1 = row*c + column;
      walls.insert(make_pair(drand48(), c1));
    }
  }

  /* Generate walls that separate horizontal cells. */

  for (row = 0; row < r; row++) {
    for (column = 0; column < c-1; column++) {
      c1 = (row*c + column) + r*c;
      walls.insert(make_pair(drand48(), c1));
    }
  }

  /* Run through the walls map, deleting walls when they
     separate cells in different disjoint sets. */

  ncomp = r*c;
  wit = walls.begin();
  while (ncomp > 1) {
    c1 = wit->second;
    if (c1 < r*c) {    // This is a wall separating vertical cells.
      c2 = c1 + c;
    } else {           // This is a wall separating horizontal cells.
      c1 -= r*c;
      c2 = c1+1;
    }
    s1 = d->Find(c1);
    s2 = d->Find(c2);
    if (s1 != s2) {     // Test for different connected components.
      d->Union(s1, s2);
      tmp = wit;
      wit++;
      walls.erase(tmp);
      ncomp--;
    } else {
      wit++;
    }
  }

  /* Print out the remaining walls. */

  printf("ROWS %d COLS %d\n", r, c);

  for (wit = walls.begin(); wit != walls.end(); wit++) {
    c1 = wit->second;
    if (c1 < r*c) {
      c2 = c1 + c;
    } else {
      c1 -= r*c;
      c2 = c1+1;
    }
    printf("WALL %d %d\n", c1, c2);
  }
  return 0;
}
