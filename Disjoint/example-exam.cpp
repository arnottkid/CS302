#include <vector>
#include <cstdlib>
#include <cstdio>
#include "disjoint.h"
#include <iostream>
using namespace std;

int main()
{
  DisjointSet *d;
  int s01, s23, s45, s67;

  d = new DisjointSetByRankWPC(8);

  s01 = d->Union(0, 1); 
  s23 = d->Union(2, 3); 
  s45 = d->Union(4, 5); 
  s67 = d->Union(6, 7); 

  s01 = d->Union(s01, s23);
  s45 = d->Union(s45, s67);

  s01 = d->Union(s01, s45);

  d->Print();

  printf("\n");

  d->Find(0);
  
  d->Print();
  exit(0);
}
