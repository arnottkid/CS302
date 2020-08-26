#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int find_em(const vector <int> &r,
            const map <int, int> &p,
            int n) 
{
  int found;
  int i, index;

  found = 0;
  for (i = 0; i < n; i++) {
    index = rand() % r.size();
    if (p.find(r[index]) != p.end()) found++;
  }
  return found;
}

int main(int argc, char **argv)
{
  int n, m;
  map <int, int> p;
  vector <int> r;
  int i;

  /* Read the command line and error check. */
  try {
    if (argc != 3) throw runtime_error("");
    if (sscanf(argv[1], "%d", &n) != 1) throw runtime_error("Bad n");
    if (sscanf(argv[2], "%d", &m) != 1) throw runtime_error("Bad m");
  } catch (const runtime_error &e) {
    fprintf(stderr, "usage: bin/click1 n m\n%s\n", e.what());
    return 1;
  }
    
  /* Create a vector with 2m numbers, and put the even ones into a map: */

  for (i = 0; i < 2*m; i++) {
    r.push_back(rand());
    if (i % 2 == 0) p[r[i]] = rand();
  }

  /* Call find_em to find n random numbers from r in the map */

  cout << find_em(r, p, n) << endl;
  return 0;
}
