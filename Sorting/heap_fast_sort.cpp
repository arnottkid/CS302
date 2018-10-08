/* heap_fast_sort.cpp - An implementation of sort_doubles using heap sort.  Instead
                        of using the priority queue data structure, I do everything
                        in the vector v, and implement a priority queue that grabs
                        the max value instead of the min value.  When I pop the max
                        value off the heap, I put it into the slot that was just 
                        popped off of the vector.
   James S. Plank
   CS302
   September, 2009
 */

#include <iostream>
#include <vector>
#include "sorting.h"
using namespace std;

void sort_doubles(vector <double> &v, int print)
{
  int i, j, k;
  double tmp;
  int ok, lc, rc, index;

  // Turn into a heap where the root is the maximum element 

  for (i = v.size()/2; i >= 0; i--) {
    ok = 1;
    index = i;
    while (ok) {      
      lc = index*2+1;
      rc = lc+1;
      if (lc >= v.size()) {
        ok = 0; 
      } else if (rc == v.size() || v[lc] >= v[rc]) {
        if (v[lc] > v[index]) {
          tmp = v[lc];
          v[lc] = v[index];
          v[index] = tmp;
          index = lc;
        } else {
          ok = 0;
        }
      } else if (v[rc] > v[index]) {
        tmp = v[rc];
        v[rc] = v[index];
        v[index] = tmp;
        index = rc;
      } else {
        ok = 0;
      }
    }
  }

  if (print) {
    for (j = 0; j < v.size(); j++) printf("%.2lf ", v[j]);
    cout << endl;
  }

  // Now remove each element from the root of the heap and put it at the end of the array,
  // and percolate down.

  for (i = v.size()-1; i > 0; i--) {
    tmp = v[i];
    v[i] = v[0];
    v[0] = tmp;
    ok = 1;
    index = 0;
    while (ok) {      
      lc = index*2+1;
      rc = lc+1;
      if (lc >= i) {
        ok = 0; 
      } else if (rc == i || v[lc] >= v[rc]) {
        if (v[lc] > v[index]) {
          tmp = v[lc];
          v[lc] = v[index];
          v[index] = tmp;
          index = lc;
        } else {
          ok = 0;
        }
      } else if (v[rc] > v[index]) {
        tmp = v[rc];
        v[rc] = v[index];
        v[index] = tmp;
        index = rc;
      } else {
        ok = 0;
      }
    }
    if (print) {
      for (j = 0; j < v.size(); j++) printf("%.2lf ", v[j]);
      cout << endl;
    }
  }
}

