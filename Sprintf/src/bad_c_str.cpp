#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* This program shows what happens when you mess with
   the pointer returnd by the c_str() method of strings.
   You end up corrupting the string structure. */

int main()
{
  string s;
  char *cs;

  /* Here you set cs to point to the bytes of a string,
     and you set the character at index one to the
     NULL character. */

  s = "ABCDE";
  cs = (char *) s.c_str();
  cs[1] = '\0';
  
  /* You'll note that it still reports that the size 
     is 5, even though when you print it, its size is one. */
     
  cout << "After setting index 1 to the NULL character.\n";
  cout << s.size() << endl;
  cout << s << endl;
  printf("%s\n", s.c_str());

  /* When you call push_back on s, it indeed pushes the character
     'F' on the end of the string -- you'll see that the string
     is still corrupted. */

  s.push_back('F');

  cout << endl << "After calling s.push_back('F'):\n";
  cout << s.size() << endl;
  cout << s << endl;
  printf("%s\n", s.c_str());
  
  return 0;
}
