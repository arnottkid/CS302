
#include <iostream>
using namespace std;

string s(string v)
{
  string tmp;
  if (v.size() == 0) return "";
  tmp.push_back(v[0]);
  return s(v.substr(1)) + tmp;
}

int main()
{
  cout << s("Fred") << endl;
}
