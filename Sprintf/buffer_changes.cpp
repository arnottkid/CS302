#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  string s;
  const char *cs;
  int i;

  cs = s.c_str();

  for (i = 1; i <= 10000; i++) {
    s.push_back('A');
    if (s.c_str() != cs) {
      printf("The underlying buffer changed at size: %d\n", i);
      cs = s.c_str();
    }
  }
  return 0;
}
