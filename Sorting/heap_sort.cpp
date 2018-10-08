/* heap_sort.cpp - An implementation of sort_doubles using priority queues from 
                   the Priority Queue lecture notes.
   James S. Plank
   CS302
   September, 2009
 */

#include <iostream>
#include <vector>
#include "sorting.h"
#include "pqueue.h"
using namespace std;

void sort_doubles(vector <double> &v, int print)
{
  int i, j, k;
  double tmp;
  PQueue *heap;

  heap = new PQueueHeap(v);

  if (print) {
    for (j = 0; j < v.size(); j++) printf("%.2lf ", v[j]);
    printf("   ");
    heap->Print();
    cout << endl;
  }

  for (i = 0; i < v.size(); i++) {
    v[i] = heap->Pop();
    if (print) {
      for (j = 0; j < v.size(); j++) printf("%.2lf ", v[j]);
      printf("   ");
      heap->Print();
      cout << endl;
    }
  }
}

