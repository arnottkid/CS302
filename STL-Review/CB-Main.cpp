#include "CarBuyer.cpp"

int main(int argc, char **argv)
{
  int i;
  class CarBuyer TheClass;
  double retval;
  vector <string> cars;
  int fuelPrice;
  int annualDistance;
  int years;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  cars = ;
  fuelPrice = ;
  annualDistance = ;
  years = ;
*/


 if (atoi(argv[1]) == 0) {
    cars.push_back("10000 50 50");
    cars.push_back("12000 500 10");
    cars.push_back("15000 100 65");
    cars.push_back("20000 20 80");
    cars.push_back("25000 10 90");
    fuelPrice = 2;
    annualDistance = 5000;
    years = 2;
  }

 if (atoi(argv[1]) == 1) {
    cars.push_back("10000 50 50");
    cars.push_back("12000 500 10");
    cars.push_back("15000 100 65");
    cars.push_back("20000 20 80");
    cars.push_back("25000 10 90");
    fuelPrice = 8;
    annualDistance = 25000;
    years = 10;
  }

 if (atoi(argv[1]) == 2) {
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
    fuelPrice = 33;
    annualDistance = 8673;
    years = 64;
  }

  retval = TheClass.lowestCost(cars, fuelPrice, annualDistance, years);
  printf("%lf\n", retval);

  exit(0);
}
