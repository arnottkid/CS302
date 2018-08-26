#include "Glossary.cpp"

#define VIT(i, v) for (i = 0; i < v.size(); i++)

int main(int argc, char **argv)
{
  int i;
  class Glossary TheClass;
  vector <string> retval;
  vector <string> items;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  items = ;
*/


 if (atoi(argv[1]) == 0) {
    items.push_back("Canada");
    items.push_back( "France");
    items.push_back( "Germany");
    items.push_back( "Italy");
    items.push_back( "Japan");
    items.push_back( "Russia");
    items.push_back( "United Kingdom");
    items.push_back( "United States");
  }

 if (atoi(argv[1]) == 1) {
    items.push_back("alpha");
    items.push_back( "beta");
    items.push_back( "gamma");
    items.push_back( "delta");
    items.push_back( "omega");
  }

 if (atoi(argv[1]) == 2) {
    items.push_back("AVL tree");
    items.push_back( "backtracking");
    items.push_back( "array");
    items.push_back( "balanced tree");
    items.push_back( "binary search");
  }

 if (atoi(argv[1]) == 3) {
    items.push_back("XXXXXXXXXXXXXXXXX");
    items.push_back( "YYYYYYYYYYYYYYYYY");
    items.push_back( "ZZZZZZZZZZZZZZZZZ");
  }

 if (atoi(argv[1]) == 4) {
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
  }

  retval = TheClass.buildGlossary(items);
  VIT(i, retval) cout << retval[i] << endl;

  exit(0);
}
