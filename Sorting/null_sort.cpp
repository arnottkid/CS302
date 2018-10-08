/* null_sort.cpp - Baseline control for the sorting example.
   James S. Plank
   CS302
   September, 2009
 */

#include <iostream>
#include <vector>
using namespace std;

#include "sorting.h"

void sort_doubles(vector <double> &v, int print)
{
  int j;

  if (print) {
    for (j = 0; j < v.size(); j++) printf("%4.2lf ", v[j]);
    cout << endl;
  }

  return;
}
