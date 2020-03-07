#include "car_buyer.hpp"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/* This program uses sscanf() instead of the stringstream. */

double CarBuyer::lowestCost(const vector <string> &cars, 
                            int fuelPrice, 
                            int annualDistance, 
                            int years)
{
  size_t i;
  double fp, ad, y, price, tax, efficiency, cost, min;
 
  fp = fuelPrice;
  ad = annualDistance; 
  y = years;
  min = -1;

  for (i = 0; i < cars.size(); i++) {
    sscanf(cars[i].c_str(), "%lf %lf %lf", &price, &tax, &efficiency);
    cost = price + (y * tax) + (y * ad * fp / efficiency);
    if (i == 0 || cost < min) min = cost;
  }
  return min;
}
