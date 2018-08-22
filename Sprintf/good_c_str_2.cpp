#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  string s;
  char buf[10];

  sprintf(buf, "%d", 5);
  s = buf;
  cout << s << endl;
}
