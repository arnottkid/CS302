/* This program prints out the summation 
   of i/(2^i) for i from 0 to 15 */

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
