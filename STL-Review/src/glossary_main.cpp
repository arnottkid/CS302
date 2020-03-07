#include "glossary.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  int ssize, i, j;
  class Glossary TheClass;
  vector <string> retval;
  vector <string> items;
  string term;
  double rn;

  if (argc != 2) {
    fprintf(stderr, "usage: bin/glossary num\n");
    fprintf(stderr, "       if num is '-' then read the terms from standard input.\n");
    fprintf(stderr, "       if num is 0, 1 or 2, then use Topcoder's examples.\n");
    fprintf(stderr, "       otherwise use num as an RNG seed and generate random input.\n");
    exit(1);
  }

  if (strcmp(argv[1], "-") == 0) {
    while (cin >> term) items.push_back(term);

  } else if (atoi(argv[1]) == 0) {
    items.push_back("Canada");
    items.push_back( "France");
    items.push_back( "Germany");
    items.push_back( "Italy");
    items.push_back( "Japan");
    items.push_back( "Russia");
    items.push_back( "United Kingdom");
    items.push_back( "United States");

  } else if (atoi(argv[1]) == 1) {
    items.push_back("alpha");
    items.push_back( "beta");
    items.push_back( "gamma");
    items.push_back( "delta");
    items.push_back( "omega");

  } else if (atoi(argv[1]) == 2) {
    items.push_back("AVL tree");
    items.push_back( "backtracking");
    items.push_back( "array");
    items.push_back( "balanced tree");
    items.push_back( "binary search");

  } else if (atoi(argv[1]) == 3) {
    items.push_back("XXXXXXXXXXXXXXXXX");
    items.push_back( "YYYYYYYYYYYYYYYYY");
    items.push_back( "ZZZZZZZZZZZZZZZZZ");

  } else if (atoi(argv[1]) == 4) {
    items.push_back("Asteria");
    items.push_back( "Astraeus");
    items.push_back( "Atlas");
    items.push_back( "Clymene");
    items.push_back( "Coeus");
    items.push_back( "Crius");
    items.push_back( "Cronus");
    items.push_back( "Dione");
    items.push_back( "Epimetheus");
    items.push_back( "Helios");
    items.push_back( "Hyperion");
    items.push_back( "Iapetus");
    items.push_back( "Leto");
    items.push_back( "Mnemosyne");
    items.push_back( "Oceanus");
    items.push_back( "Ophion");
    items.push_back( "Phoebe");
    items.push_back( "Prometheus");
    items.push_back( "Rhea");
    items.push_back( "Tethys");
    items.push_back( "Theia");
    items.push_back( "Themis");

  } else {
    srand48(atoi(argv[1]));
    rn = drand48();
    if (rn < .5) {
      ssize = drand48() * 10 + 2;
    } else if (rn < .9) {
      ssize = drand48() * 100 + 2;
    } else if (rn < .95) {
      ssize = drand48() * 1000 + 2;
    } else {
      ssize = drand48() * 1000000 + 1;
    }
    for (i = 0; i < ssize; i++) {
      term.clear();
      for (j = 0; j < 8; j++) {
        if (drand48() < .5) {
          term.push_back('A'+drand48()*26);
        } else {
          term.push_back('a'+drand48()*26);
        }
      }
      items.push_back(term);
    }
  }

  retval = TheClass.buildGlossary(items);
  for (i = 0; i < (int) retval.size(); i++) {
    cout << retval[i] << endl;
  }

  exit(0);
}
