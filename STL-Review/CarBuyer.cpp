#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class CarBuyer {
  public:
    double lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years);
};

double CarBuyer::lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years)
{
  int i;
  istringstream ss;

  double fp, ad, y, price, tax, efficiency, cost, min;
 
  /* Convert all of those integers to doubles. */

  fp = fuelPrice;
  ad = annualDistance; 
  y = years;

  /* Use a stringstream to extract the values from each string, 
     and compute the cost.  Keep track of the minimum cost. */

  min = -1;
  for (i = 0; i < cars.size(); i++) {
    ss.clear();
    ss.str(cars[i]);
    ss >> price >> tax >> efficiency;
    cost = price + (y * tax) + (y * ad * fp / efficiency);
    if (min == -1 || cost < min) min = cost;
  }
  return min;
}
