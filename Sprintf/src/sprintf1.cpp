#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* This program uses sprintf() to put five numbers into a string. */

int main()
{
  char buf[100];
  string s;
  int i;

  cin >> i;

  sprintf(buf, "%d %d %d %d %d", i, i+1, i+2, i+3, i+4);
  s = buf;

  cout << s << endl;

  return 0;
}
