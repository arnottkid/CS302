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
  string s;
  stringstream ss;
  int n, m;
  string curvestring;
  char buf[200];
  
  printf("newgraph\n");
  printf("xaxis min 0 max 6 size 7 nodraw\n");
  printf("yaxis min 0 max 10 size 1.5 nodraw\n");

  while (getline(cin, s)) {
    ss.clear();
    ss.str(s);
    ss >> n;
    sprintf(buf, "%d %d\n", (n+9)/10, (n+9)%10);
    curvestring += buf;
    while (ss >> m) {
      printf("newline gray .6 pts %d %d %d %d\n", 
          (n+9)/10, (n+9)%10,
          (m+9)/10, (m+9)%10);
    }
  }
  printf("newcurve marktype circle pts \n");
  printf("%s", curvestring.c_str());
}
