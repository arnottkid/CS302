#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
  vector <double> h;
  double d;
  size_t i;

  while (cin >> d) h.push_back(d);

  printf("newgraph xaxis min 0 max %lg nodraw size %lg\n", 
         (double) h.size(), (double) h.size() * 0.17);
  printf("yaxis min 0 max 1 size .25 nodraw\n");

  printf("newcurve marktype box fill 1 marksize 1 1 pts\n");
  for (i = 0; i < h.size(); i++) {
    printf(" %lg %lg\n", (double) i + 0.5, 0.5);
  }
  for (i = 0; i < h.size(); i++) {
    printf("newstring fontsize 10 hjc vjc x %lg y %lg : %lg\n", (double) i + 0.5, .5, h[i]);
    printf("newstring fontsize 9 hjc vjb x %lg y %lg : %lu\n", (double) i + 0.5, 1.2, i);
  }
}
