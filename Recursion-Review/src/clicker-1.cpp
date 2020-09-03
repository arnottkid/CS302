
#include <iostream>
using namespace std;

int s(int i)
{
  if (i == 0) return 0;
  return i + s(i-1);
}

int main()
{
  cout << s(10) << endl;
}
