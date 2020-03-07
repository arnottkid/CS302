#include "glossary.hpp"
#include <iostream>
using namespace std;

/* This is a skeleton implementation of the topcoder method.
   It prints the terms, and then returns an empty vector. */

vector <string> Glossary::buildGlossary(const vector <string> &items)
{
  size_t i;
  vector <string> rv;

  for (i = 0; i < items.size(); i++) cout << items[i] << endl;
  return rv;
}

