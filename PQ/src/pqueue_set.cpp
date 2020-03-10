#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "pqueue.hpp"
using namespace std;

/* Using a multiset to implement the priority queue makes 
   most of these methods really simple.  The first four
   here are one-liners: */

        PQueueSet::PQueueSet()    { }
void    PQueueSet::Push(double d) { elements.insert(d); }
size_t  PQueueSet::Size() const   { return elements.size(); }
bool    PQueueSet::Empty() const  { return elements.empty(); }

/* With Pop(), we error check, and then if the multiset
   is not empty, we return the first element, and erase
   it from the multiset. */

double PQueueSet::Pop() 
{
  multiset <double>::iterator hit;
  double retval;
  
  if (elements.empty()) {
    throw runtime_error("Called Pop() on an empty PQueue");
  }
  hit = elements.begin();
  retval = *hit;
  elements.erase(hit);
  return retval;
}

/* Print() is straightfoward. */

void PQueueSet::Print() const
{
  multiset <double>::const_iterator hit;

  for (hit = elements.begin(); hit != elements.end(); hit++) {
    if (hit != elements.begin()) cout << " ";
    cout << *hit;
  }
  cout << endl;
}
