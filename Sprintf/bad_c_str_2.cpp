#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
  string s;

  sprintf((char *) s.c_str(), "%d", 5);
  cout << s << endl;
}
