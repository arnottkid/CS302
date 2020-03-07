#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "car_buyer.hpp"
using namespace std;

/* This is a main() program to test the CarBuyer class.

   If you call it with an argument of 0, 1 or 2, it does that
   topcoder example.  If you call it with "-", then you enter
   fuel_price, annual_distance, and years, and then the information
   for the cars.  If you call it with a different numerical argument,
   then it uses the number to seed a random number generator, and
   it generates random input. */

int main(int argc, char **argv)
{
  int i;
  class CarBuyer cb;
  double retval;
  vector <string> cars;
  int fuel_price;
  int annual_distance;
  int years;
  int p, t, fe;
  int num;
  int ncars;
  string s;
  char line[100];

  if (argc != 2) { 
    fprintf(stderr, "usage: bin/car_buyer num\n");
    fprintf(stderr, "       if num is '-' then read from standard input.\n");
    fprintf(stderr, "       if num is 0, 1 or 2, then use Topcoder's examples.\n");
    fprintf(stderr, "       otherwise use num as an RNG seed and generate random input.\n");
    exit(1);
  }

  s = argv[1];
  num = atoi(argv[1]);
 
  if (s == "-") {
    if (!(cin >> fuel_price >> annual_distance >> years) ||
        fuel_price < 1 || fuel_price > 100 ||
        annual_distance < 1 || annual_distance > 100000 ||
        years < 1 || years > 100000) {
      fprintf(stderr, "Bad input -- first line should be fuel_price annual_distance years,\n");
      fprintf(stderr, "and they should match the problem constraints.\n");
      exit(1);
    }
    while (cin >> p >> t >> fe) {
      if (p < 1 || p > 100000 ||
          t < 1 || t > 1000 ||
          fe < 1 || fe > 100) {
        fprintf(stderr, "Bad price/tax/efficiency: %d/%d/%d\n", p, t, fe);
        exit(1);
      }
      sprintf(line, "%d %d %d", p, t, fe);
      cars.push_back(line);
    }
    if (cars.size() == 0) {
      fprintf(stderr, "Bad input -- zero cars specified.\n");
      exit(1);
    }
  
  } else if (num == 0) {
    cars.push_back("10000 50 50");
    cars.push_back("12000 500 10");
    cars.push_back("15000 100 65");
    cars.push_back("20000 20 80");
    cars.push_back("25000 10 90");
    fuel_price = 2;
    annual_distance = 5000;
    years = 2;

  } else if (num == 1) {
    cars.push_back("10000 50 50");
    cars.push_back("12000 500 10");
    cars.push_back("15000 100 65");
    cars.push_back("20000 20 80");
    cars.push_back("25000 10 90");
    fuel_price = 8;
    annual_distance = 25000;
    years = 10;

  } else if (num == 2) {
    cars.push_back("8426 774 19");
    cars.push_back("29709 325 31");
    cars.push_back("30783 853 68");
    cars.push_back("27726 4 81");
    cars.push_back("20788 369 69");
    cars.push_back("17554 359 34");
    cars.push_back("6264 230 69");
    cars.push_back("14151 420 65");
    cars.push_back("25115 528 70");
    cars.push_back("2050 926 40");
    cars.push_back("18618 714 29");
    cars.push_back("173 358 57");
    fuel_price = 33;
    annual_distance = 8673;
    years = 64;

  } else {
    srand48(num);
    fuel_price = drand48() * 100 + 1;
    annual_distance = drand48() * 100000 + 1;
    years = drand48() * 100 + 1;
    ncars = drand48() * 10000 * 1;
    for (i = 0; i < ncars; i++) {
      p = drand48() * 100000 + 1;
      t = drand48() * 10000 + 1;
      fe = drand48() * 100 + 1;
      sprintf(line, "%d %d %d", p, t, fe);
      cars.push_back(line);
    }
  }

  retval = cb.lowestCost(cars, fuel_price, annual_distance, years);
  printf("%lf\n", retval);

  exit(0);
}
