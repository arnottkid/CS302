#include "car_buyer.hpp"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/* This program uses a stringstream to extract the values from each of
   the car strings.  I then calculate the projected cost of each car,
   and return the minimum.  I convert all integers to doubles, because
   we will be performing floating point operations. */

double CarBuyer::lowestCost(const vector <string> &cars, 
                            int fuelPrice, 
                            int annualDistance, 
                            int years)
{
  size_t i;
  istringstream ss;
  double fp, ad, y, price, tax, efficiency, cost, min;
 
  /* Convert all of those integers to doubles. */

  fp = fuelPrice;
  ad = annualDistance; 
  y = years;

  /* Use a stringstream to extract the values from each string, 
     and compute the cost.  Keep track of the minimum cost. */

  min = -1;  /* I don't technically need this line, but some compilers
                will yell at me if I don't have it. */

  for (i = 0; i < cars.size(); i++) {
    ss.clear();
    ss.str(cars[i]);
    ss >> price >> tax >> efficiency;
    cost = price + (y * tax) + (y * ad * fp / efficiency);
    if (i == 0 || cost < min) min = cost;
  }
  return min;
}
