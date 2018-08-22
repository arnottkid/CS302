#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  string s;
  char *cs;

  s = "ABCDE";
  cs = (char *) s.c_str();
  cs[1] = '\0';
  
  cout << s.size() << endl;
  cout << s << endl;
  printf("%s\n", s.c_str());

  s.push_back('F');

  cout << s.size() << endl;
  cout << s << endl;
  printf("%s\n", s.c_str());
  
  return 0;
}
