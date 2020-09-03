#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  vector <string> args;
  int set;
  int i;

  for (i = 1; i < argc; i++) args.push_back(argv[i]);
  cin >> hex >> set;

  for (i = 0; i < args.size(); i++) {
     if (set & (1 << i)) cout << args[i];
  }
  cout << endl;
  return 0;
}


