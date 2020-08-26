#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s1, s2;
  const char *s;

  s2 = "Fred";
  s = s2.c_str();
  s1 = s;

  s1[1] = 'y';
  s2[1] = 'z';
 
  cout << s << " "
       << s1 << " "
       << s2 << endl;
  return 0;
}
