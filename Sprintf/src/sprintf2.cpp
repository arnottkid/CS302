#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* This program makes a big mistake, and does not allocate enough 
   memory for the sprintf() call.  In particular, buf2 is only
   eight bytes, and the sprintf() call writes at least 10 bytes,
   and maybe more. */

int main()
{
  char buf1[8];
  char buf2[8];
  char buf3[8];
  int i;

  buf1[0] = '\0';
  buf2[0] = '\0';
  buf3[0] = '\0';

  cin >> i;

  printf("Before:\n");
  printf("buf1: %s\n", buf1);
  printf("buf2: %s\n", buf2);
  printf("buf3: %s\n", buf3);

  /* Here is where sprintf() overruns the bytes allocated for buf2. */

  sprintf(buf2, "%d %d %d %d %d", i, i+1, i+2, i+3, i+4);

  printf("After:\n");
  printf("buf1: %s\n", buf1);
  printf("buf2: %s\n", buf2);
  printf("buf3: %s\n", buf3);

  return 0;
}
