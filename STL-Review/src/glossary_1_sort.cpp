/* In my first pass at a solution, I create a map from the items.  I
   convert each string to upper-case, and then store that string in 
   the map as a key, with the value being the original string.  I
   print it out at the end. */

#include "glossary.hpp"
#include <map>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector <string> Glossary::buildGlossary(const vector <string> &items)
{
  size_t i, j;
  string s;
  map <string, string> g;
  map <string, string>::iterator git;
  vector <string> rv;

  for (i = 0; i < items.size(); i++) {
    s = items[i];                            // s is the upper-case string.
    for (j = 0; j < s.size(); j++) {
      if (s[j] >= 'a' && s[j] <= 'z') s[j] += ('A'-'a');
    }
    g[s] = items[i];                         // This puts s and items[i] into the map.
  }

  for (git = g.begin(); git != g.end(); git++) {     // Print the map
    cout << git->first << " " << git->second << endl;
  }
  return rv;
}
