#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef vector <string> SVec;

class Glossary {
  public:
    vector <string> buildGlossary(vector <string> items);
};

vector <string> Glossary::buildGlossary(vector <string> I)
{
  int i, j;
  string s;
  map <string, string> g;
  map <string, string>::iterator git;
  SVec rv;

  /* Create the map g, which has the strings converted to upper-case as
     keys, and the strings themselves as vals. */

  for (i = 0; i < I.size(); i++) {
    s = I[i];
    for (j = 0; j < s.size(); j++) {
      if (s[j] >= 'a' && s[j] <= 'z') s[j] += ('A'-'a');
    }
    g[s] = I[i];
  }

  for (git = g.begin(); git != g.end(); git++) {
    cout << git->first << " " << git->second << endl;
  }
  return rv;
}
