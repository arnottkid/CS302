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
  vector <string> atm, ntz;                  // The two string vectors for A-M & N-Z
  vector <string> rv, *v;                    // Return value and a pointer that makes life easier.
  char cs[100];                              // A buffer so we can use sprintf to create strings.


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

  /* Create the formatted strings for each column.  Put the
     strings onto a vector for each column. */

  for (kit = k.begin(); kit != k.end(); kit++) {

    v = (kit->first < 'N') ? &atm : &ntz;    // V points to the proper string vector.
    s.clear();                               // Create the key string and the dashes.
    s.resize(19, ' ');
    s[0] = kit->first;
    v->push_back(s);
    s.clear();
    s.resize(19, '-');
    v->push_back(s);

    for (i = 0; i < kit->second.size(); i++) {         // Now, for each term, format it and push
      sprintf(cs, "  %-17s", kit->second[i].c_str());  // it onto the string vector.
      s = cs;
      v->push_back(s);
    }
  }

  /* Make atm and ntz the same size. */

  s.clear();
  s.resize(19, ' ');
  while (atm.size() < ntz.size()) atm.push_back(s);
  while (ntz.size() < atm.size()) ntz.push_back(s);

  /* Create the final strings */

  s = "  ";
  for (i = 0; i < atm.size(); i++) {
    rv.push_back(atm[i] + s + ntz[i]);
  }
  return rv;
}
