#include <cstdio>
using namespace std;

int main()
{
  int a, b;

  a = 67;
  b = 3;

  printf("0x%x 0x%x 0x%x\n", 
         a, a & b, a ^ b );
  return 0;
}
