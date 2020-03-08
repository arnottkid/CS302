/* ba_helper.cpp -- a program to help you understand binary arithmetic.
   James S. Plank
   January, 2017
 */

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "MOA.hpp"
using namespace std;

MOA RNG; /* Global variable for rng -- sorry. */

/* This is how we're holding a number.  It facilitates printing out the number. */

class Number {
  public:
    unsigned long long d;      /* The number. */
    string hex;                /* Its representation in hex (16 hex digits with a 0x in front). */
    string binary;             /* Its representation in binary */
    string To_String();        /* This creates a bigger string, which is kind of formatted. */
};

/* This returns a "formatted" string for a number. */

string Number::To_String()
{
  char buf[200];
  string s;

  sprintf(buf, "%21llu   %s  %s", d, hex.c_str(), binary.c_str());
  s = buf;
  return s;
  
}

Number *number_from_ull(unsigned long long v)
{
  Number *n;
  int i;
  char buf[200];
 
  /* Create the Number class instance, and set the strings. */

  n = new Number;
  n->d = v;

  /* Set the hexadecimal using sprintf. */

  sprintf(buf, "0x%016llx", v);
  n->hex = buf;

  /* For the binary, examine each bit by doing AND with one 
     left-shifted the proper number of bits. "1ULL" forces
     the compiler to treat one as an unsigned long long.  
     Otherwise, if you shift it more than 31 bits, it will
     treat one as an integer, and turn it into zero.  */

  n->binary.resize(64, '0');
  for (i = 0; i < 64; i++) if (v & (1ULL << i)) n->binary[64-i-1] = '1';

  return n;
}

Number *random_number(int bits)
{
  unsigned long long ull;
  if (bits < 32) ull = RNG.Random_W(bits, true);
  else if (bits == 32) ull = RNG.Random_32();
  else if (bits == 64) ull = RNG.Random_64();
  else return NULL;
  return number_from_ull(ull);
}

/* This creates a number from a string, which is either decimal,
   hexadecimal (starting with 0x), or binary (starting with B). 
   It creates all of the string representations. */

Number *number_from_string(string &s)
{
  unsigned long long v;
  unsigned long long i;
  int b;

  v = 0;

  if (s.size() == 0) return NULL;

  /* Convert from binary if the string begins with 'B' */

  if (s[0] == 'B') {
    if (s.size() == 1) return NULL;
    if (s.size() > 65) return NULL;
    for (i = 0; i < s.size()-1; i++) {
      b = s[s.size()-i-1];
      if (b != '0' && b != '1') return NULL;
      if (b == '1') v |= (1ULL << i);
    }

  /* Convert from hex if the string begins with "0x" */

  } else if (s.substr(0, 2) == "0x") {
    if (s.size() == 2 || s.size() > 18) return NULL;
    if (sscanf(s.c_str(), "0x%llx", &v) != 1) return NULL;

  /* Attept to convert from decimal. */

  } else {
    if (sscanf(s.c_str(), "%llu", &v) != 1) return NULL;
  }

  return number_from_ull(v);
}

/* Number_from_ull just converts the number to a string and
   then calls "number_from_string." */

string random_op()
{
  int i;

  i = RNG.Random_Integer()%6;
  switch (i) {
    case 0: return "AND";
    case 1: return "OR";
    case 2: return "XOR";
    case 3: return "LS";
    case 4: return "RS";
    case 5: return "ANDNOT";
    default: return "";
  }
}

int main()
{
  Number *A, *B, *C;
  string sa, sb, sop, s;
  int error;
  int w;

  RNG.Seed(time(0));

  printf("When entering numbers, you can enter:\n");
  printf("  A normal decimal number as big as 2^{64}-1.\n");
  printf("  A number in hex up to 16 digits, starting with 0x.\n");
  printf("  A number in binary up to 64 digits, starting with B.\n");

  while (1) {
    error = 0;
    C = NULL;

    /* Grab A, B and the operator. */

    printf("Enter a problem: number AND|OR|XOR|LS|RS|ANDNOT number (or Rw for a w-bit random problem):\n");
    fflush(stdout);

    if (! (cin >> sa)) return 0;

    /* Generate a random problem . */

    if (sa[0] == 'R') {
      w = atoi(sa.c_str()+1);
      if (w == 0) {
        error = 1;
      } else {
        A = random_number(w);
        sop = random_op();
        if (sop == "LS" || sop == "RS") {
          B = number_from_ull(RNG.Random_Integer()%w);
        } else {
          B = random_number(w);
        }
      }
    } else {
      if (! (cin >> sop >> sb)) return 1;

      /* Convert A and B to instances of the Number class, and error check. */

      A = number_from_string(sa);
      B = number_from_string(sb);
  
      if (A == NULL) {
        printf("Bad format for the first number.\n");
        error = 1;
      } 
      if (B == NULL) {
        printf("Bad format for the second number.\n");
        error = 1;
      }
    }
    
    /* Do the operation if we haven't had an error so far. */

    if (error == 0) {
      if (sop == "AND") {
        C = number_from_ull(A->d & B->d);
      } else if (sop == "OR") {
        C = number_from_ull(A->d | B->d);
      } else if (sop == "XOR") {
        C = number_from_ull(A->d ^ B->d);
      } else if (sop == "LS") {
        C = number_from_ull(A->d << B->d);
      } else if (sop == "RS") {
        C = number_from_ull(A->d >> B->d);
      } else if (sop == "ANDNOT") {
        C = number_from_ull(A->d & (~B->d));
      } else {
        printf("Bad operator.\n");
        error = 1;
      }
    }
    
    /* If everything was successful, print the results. Wait for a word if it was Random */

    if (error == 0) {
      printf("\n");
      printf("Operator: %s\n", sop.c_str());
      printf("A:        %s\n", A->To_String().c_str());
      printf("B:        %s\n", B->To_String().c_str());
      if (sa[0] == 'R') {
        printf("Enter any word to continue: ");
        fflush(stdout);
        if (!(cin >> s)) return 0;
      }
      printf("C:        %s\n", C->To_String().c_str());
      printf("\n");
    }

    /* Free up memory: Call delete on anything that you created
       with new. */

    if (A != NULL) delete A;
    if (B != NULL) delete B;
    if (C != NULL) delete C;
  
  }

  exit(0);
}
