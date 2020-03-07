#include "car_buyer.hpp"
using namespace std;

/* This is a skeleton implementation of the topcoder method.
   It simply returns zero.  I include it, because it is a good starting point. */

double CarBuyer::lowestCost(const vector <string> &cars, 
                            int fuel_price, 
                            int annual_distance, 
                            int years)
{
  size_t i;

  printf("fuel_price: %d\n", fuel_price);
  printf("annual_distance: %d\n", annual_distance);
  printf("years: %d\n", years);
  for (i = 0; i < cars.size(); i++) {
    printf("Car %5lu: %s\n", i, cars[i].c_str());
  }

  return 0;
}
