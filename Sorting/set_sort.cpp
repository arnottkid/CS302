/* set_sort.cpp - An implementation of sort_doubles using multisets from the STL.
   James S. Plank
   CS302
   September, 2009
 */

#include "sorting.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void sort_doubles(vector <double> &v, int print)
{
  multiset <double> s;
  int i;
  multiset <double>::iterator sit;

  for (i = 0; i < v.size(); i++) s.insert(v[i]);
  i = 0;
  for (sit = s.begin(); sit != s.end(); sit++) {
    v[i] = *sit;
    i++;
  }
}
