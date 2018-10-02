#include <iostream>
using namespace std;

int main()
{
  double num, den, total, n;

  num = 1;
  den = 2;
  total = 0;
  
  for (n = 0; n < 15; n++) {
    total += (num/den);
    num++;
    den *= 2;
    cout << total << endl;
  }
  return 0;
}
