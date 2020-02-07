#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* Read the integer 100 from the string "100" using sscanf(). */

int main()
{
  string s;
  int i;

  s = "100";
  sscanf(s.c_str(), "%d", &i);
  printf("i = %d\n", i);

  return 0;
}
