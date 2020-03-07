#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* This program demonstrates that as you call push_back(), the string class' 
   underlying string buffer will change.  This is because the buffer "fills up",
   and then the string implementation allocates a bigger buffer and copies
   the string over to it.  If you try to maintain a pointer to this old
   buffer, the pointer will become "stale" when the buffer changes. */

int main()
{
  string s;
  const char *cs;
  int i;

  cs = s.c_str();                // Store the pointer to the buffter in cs

  for (i = 1; i <= 10000; i++) {
    s.push_back('A');
    if (s.c_str() != cs) {       // Print when the pointer changes.
      printf("The underlying buffer changed at size: %d\n", i);
      cs = s.c_str();
    }
  }
  return 0;
}
