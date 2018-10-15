#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
  int n;
  int e;
  int i;
  int n1, n2;
  set <string> edges;
  set <string>::iterator eit;
  string s;
  char edge[100];

  if (argc != 3) {
    cerr << "usage: ggraph n e\n";
    exit(1);
  }

  n = atoi(argv[1]);
  
  e = atoi(argv[2]);
  if (e > (n-1) * n / 2) {
    cerr << "e is too big\n";
    exit(1);
  }
  srand48(time(0));

  cout << "NNODES " << n << endl;
  for (i = 0; i < e; i++) {
    do {
      n1 = lrand48()%n;
      do n2 = lrand48()%n; while (n2 == n1);
      if (n1 < n2) {
        sprintf(edge, "%d %d", n1, n2);
      } else {
        sprintf(edge, "%d %d", n2, n1);
      }
      s = edge;
    } while (edges.find(s) != edges.end());
    
    edges.insert(s);

    cout << "EDGE " << s << endl;
  }
}
