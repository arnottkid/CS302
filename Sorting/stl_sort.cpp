/* Using the stl's sort routine to sort. */

#include "sorting.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort_doubles(vector <double> &v, int print)
{
  sort(v.begin(), v.end());
}

