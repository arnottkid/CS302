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
  map <char, SVec> bychar;
  map <char, SVec>::iterator bit;
  char f;
  SVec atm, ntz, rv, *v;
  char cs[100];

  /* Create the map g, which has the strings converted 
     to upper-case as keys, and the strings themselves as vals. */

  for (i = 0; i < I.size(); i++) {
    s = I[i];
    for (j = 0; j < s.size(); j++) {
      if (s[j] >= 'a' && s[j] <= 'z') s[j] += ('A'-'a');
    }
    g[s] = I[i];
  }

  /* Now, create the map "bychar", which has the starting
     letters as keys, and vectors of the original strings as vals. */

  for (git = g.begin(); git != g.end(); git++) {
    f = git->first[0];
    bychar[f].push_back(git->second);
  }

  /* Create the formatted strings for each column.  Put the
     strings onto a vector for each column. */

  for (bit = bychar.begin(); bit != bychar.end(); bit++) {
    v = (bit->first < 'N') ? &atm : &ntz;
    s.clear();
    s.resize(19, ' ');
    s[0] = bit->first;
    v->push_back(s);
    s.clear();
    s.resize(19, '-');
    v->push_back(s);

    for (i = 0; i < bit->second.size(); i++) {
      sprintf(cs, "  %-17s", bit->second[i].c_str());
      s = cs;
      v->push_back(s);
    }
  }

  /* Print the vectors to error check. */

  for (i = 0; i < atm.size(); i++) cout << atm[i] << endl;
  cout << endl;
  for (i = 0; i < ntz.size(); i++) cout << ntz[i] << endl;
    
  return rv;
}

