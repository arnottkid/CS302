#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  string s;
  int i;

  s = "100";
  sscanf(s.c_str(), "%d", &i);
  printf("i = %d\n", i);

  return 0;
}
