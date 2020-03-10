/* This program sorts doubles on standard input using a priority queue. */

#include "pqueue.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
  PQueue *pq;
  double d;
  string imps;
  vector <double> v;

  /* Error check, and then create the pq with either the set or heap implementation. */

  imps = "shl";
  if (argc != 2 || imps.find(argv[1][0]) == string::npos) {
    fprintf(stderr, "usage: pqueue_sort c where c is a character in %s\n", imps.c_str());
    exit(1);
  }

  switch (argv[1][0]) { 
    case 's': pq = new PQueueSet(); break;
    case 'h': pq = new PQueueHeap(); break;
    case 'l': pq = NULL; break;
    default:  exit(1);
  }

  /* With 's' and 'h', simply read and push onto the heap.  With 'l', read everything
     into a vector and then construct the heap from the vector. */

  if (pq == NULL) {
    while (cin >> d) v.push_back(d);
    pq = new PQueueHeap(v);
  } else {
    while (cin >> d) pq->Push(d);
  }

  /* Popping everything sorts the doubles. */

  while (!pq->Empty()) cout << pq->Pop() << endl;

  return 0;
}
