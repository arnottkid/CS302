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
  size_t i, j;
  double xaxis_size;
  int levels;
  size_t npl;        // Nodes per level
  vector <double> x, y;
  double width, sx;

  xaxis_size = 6;
  while (cin >> d) h.push_back(d);
  x.resize(h.size(), -1);
  y.resize(h.size(), -1);

  levels = 0;
  i = 0;
  npl = 1;
  while (i < h.size()) {
    levels++;
    i = 2*i + 1;
    npl *= 2;
  }
  npl /= 2;

  if (npl < 32) xaxis_size = npl/16.0*6.0;
  printf("newgraph\n");
  printf("xaxis min 0 max %lu size %lg nodraw\n", npl, xaxis_size);
  printf("yaxis min 0 max %d size %lf nodraw\n", levels, (double) levels * 0.75);

  i /= 2;
  width = 1;
  for (j = i; j < h.size(); j++) {
    x[j] = (double) (j-i) + 0.25;
    y[j] = 0.5;
  }

  while (i != 0) {
    i /= 2;
    npl /= 2;
    sx = x[i*2+1] + width / 2.0;
    width *= 2;
    for (j = 0; j < npl; j++) {
      x[i+j] = sx + (double) j * width;
      y[i+j] = y[i*2+1]+0.75;
    }
  }

  for (i = 0; i < h.size(); i++) {
    if (i*2+1 < h.size()) printf("newline pts %lg %lg %lg %lg\n", x[i],  y[i], x[i*2+1], y[i*2+1]);
    if (i*2+2 < h.size()) printf("newline pts %lg %lg %lg %lg\n", x[i],  y[i], x[i*2+2], y[i*2+2]);
  }

  printf("newcurve marktype circle marksize 0.75 0.75 fill 1 pts\n");

  for (i = 0; i < h.size(); i++) printf("  %lg %lg\n", x[i], y[i]);

  if (h.size() < 64) {
    printf("newstring hjc vjc fontsize 9\n");
    for (i = 0; i < h.size(); i++) printf("copystring x %lg y %lg : %lg\n", x[i], y[i], h[i]);
  }
   
    
  return 0;
  
}
