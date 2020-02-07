#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* This is a program where you have sprintf() write bytes into
   a buffer that may or may not have been allocated.  The
   typecast statement is a good sign that you're doing something
   wrong here.  Without the typecast statement, the compiler won't
   compile this code, because you shouldn't be attempting to write
   into the bytes pointed to by c_str(). */

int main()
{
  string s;

  sprintf((char *) s.c_str(), "%d", 5);
  cout << s << endl;
  return 0;
}
