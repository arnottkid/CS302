/* destruct.cpp.
   James S. Plank
   Tue Sep 25 14:47:43 EDT 2018

   This shows how destructors work with interfaces.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* We'll have one superclass called Superclass.  It will have no virtual methods
   with the exception of a destructor. */

class Superclass {
  public:
    virtual ~Superclass();
};

/* The destructor will simply print out that it is being called. */

Superclass::~Superclass() { printf("Superclass destructor.\n"); }

/* Now, we have two subclasses, S1 and S2.  Each of their destructors are declare
   as virtual, and print out that they are being called: */

class S1 : public Superclass {
  public:
    virtual ~S1();
};

S1::~S1() { printf("S1 destructor.\n"); }

class S2 : public Superclass {
  public:
    virtual ~S2();
};

S2::~S2() { printf("S2 destructor.\n"); }

/* The main is pretty sparse.  It simply allocates instances of S1 and S2, and
   then deletes them. Each delete call will call the destructor of the subclass,
   and then the destructor of the superclass. */

int main()
{
  Superclass *s1, *s2;

  s1 = new S1;
  s2 = new S2;

  delete s1;
  delete s2;

  return 0;
}
