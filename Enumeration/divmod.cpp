/* Divmod.cpp -- Program to do a "div/mod" enumeration.
 * James S. Plank
 * CS302
 * Thu Sep 13 16:22:33 EDT 2018
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

/* Takes two command line arguments -- n and l -- and enumerates all strings
   of length l that are composed of the first n letters of the alphabet. */

int main(int argc, char **argv)
{
  int n, l, i, top, j, k, digit;

  if (argc != 3) {
    fprintf(stderr, "usage: divmod l n\n");
    exit(1);
  }
  l = atoi(argv[1]);
  n = atoi(argv[2]);

  if (l <= 0 || n <= 0) {
    fprintf(stderr, "usage: divmod l n\n");
    fprintf(stderr, "       l and n need to be > 0\n");
    exit(1);
  }
  
  /* Calculate n^l.  This is inefficient, but since l is small, 
     it's ok. */

  top = 1;
  for (i = 0; i < l; i++) top *= n;

  /* Enumerate the numbers from 0 to n^l-1, and for each of these
     numbers extract each digit when the number is considered in 
     base n.  We do that by taking the number mod n, and then 
     dividing the number by n. */

  for (i = 0; i < top; i++) {
    j = i;
    for (k = 0; k < l; k++) {
      digit = j % n;
      j /= n; 
      printf("%c", 'a'+digit);
    }
    printf("\n");
  }
  return 0;
}
