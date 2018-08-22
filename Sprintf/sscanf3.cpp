#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  string l;
  int h, m, s, n;
  double d;
  
  getline(cin, l);
  n = sscanf(l.c_str(), "%d:%d:%d", &h, &m, &s);
  printf("n = %d.  h = %d.  m = %d.  s = %d.\n", n, h, m, s);
  return 0;
}
