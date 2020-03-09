#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
  vector <string> people;
  string s;
  size_t j;
  int k;

  while (cin >> s) people.push_back(s);
  if (people.size() > 30) {
    cerr << "Sorry, not generating more than 2^30 teams\n";
    exit(1);
  }

  for (k = 1; k < (1 << people.size()); k++) {
    for (j = 0; j < people.size(); j++) {
      printf("%c", (k & (1 << j)) ? '1' : '0');
    }
    for (j = 0; j < people.size(); j++) {
      if (k & (1 << j)) printf(" %s", people[j].c_str());
    }
    printf("\n");
  }
  exit(0);
}

  
