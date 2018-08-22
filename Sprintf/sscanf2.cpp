#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  string s;
  int i, n;
  double d;
  

  getline(cin, s);
  n = sscanf(s.c_str(), "%lf %d", &d, &i);
  printf("n = %d.  d = %lf.  i = %d\n\n", n, d, i);
  return 0;
}
