#include "pqueue.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  PQueue *pq;
  int i, j, nelements, niterations;
  vector <double> v;
  string imps;
  char c;

  srand48(time(0));

  /* Error check and read the variables from the command line */

  imps = "shl";

  if (argc != 4 || imps.find(argv[1][0]) == string::npos) {
    cerr << "usage: massive_create_heap s|h|l nelements niterations\n";
    exit(1);
  }
 
  c = argv[1][0];
  nelements = atoi(argv[2]);
  niterations = atoi(argv[3]);

  /* If c == 'l', then repeatedly create the heap from the vector. */

  if (c == 'l') {
    v.resize(nelements);
    for (i = 0; i < niterations; i++) {
      for (j = 0; j < nelements; j++) v[j] = drand48();
      pq = new PQueueHeap(v);
      delete pq;
    }

  /* Otherwise, repeatedly create the heap by pushing. */

  } else {
    for (i = 0; i < niterations; i++) {
      if (c == 's') {
        pq = new PQueueSet();
      } else {
        pq = new PQueueHeap();
      }
      for (j = 0; j < nelements; j++) pq->Push(drand48());
      delete pq;
    }
  }
  
  return 0;
}
