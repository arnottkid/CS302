/* Now, I create a second map to store the first letters of the 
   terms.  Its val is a vector of the original strings, sorted
   by the upper-case strings. */

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
  map <string, string> g;                    // Map with upper-case keys, original strings as vals.
  map <string, string>::iterator git;
  map <char, vector <string> > k;            // Map with first letters as keys
  map <char, vector <string> >::iterator kit;
  vector <string> rv;

  /* This is the same code as before. */

  for (i = 0; i < items.size(); i++) {
    s = items[i];
    for (j = 0; j < s.size(); j++) {
      if (s[j] >= 'a' && s[j] <= 'z') s[j] += ('A'-'a');
    }
    g[s] = items[i];
  }

  /* Now create the second map from the first letters of the upper-case strings: */

  for (git = g.begin(); git != g.end(); git++) {     
    k[git->first[0]].push_back(git->second);
  }

  for (kit = k.begin(); kit != k.end(); kit++) {     // Print the second map
    for (i = 0; i < kit->second.size(); i++) {
      cout << kit->first << " " << kit->second[i] << endl;
    }
  }
  return rv;
}
