#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

class Graph {
  public:
    vector < vector <int> > Adj;
    vector < vector <long long> > W;
    long long Shortest_Path();
    int Edges_Processed;
};

int main(int argc, char **argv)
{
  string p;
  int maxcap, window, mincap;
  int seed;
  int n, i, j, k, l;
  Graph G;
  double start, create, stop;
  struct timeval tp;
  long long sp, tedges;

  if (argc != 7) {
    cerr << "usage: topo n maxcap mincap window seed print(y|n)\n";
    cerr << "       If window < 0, it = the number of layers.\n";
    exit(1);
  }

  n = atoi(argv[1]);
  maxcap = atoi(argv[2]);
  mincap = atoi(argv[3]);
  window = atoi(argv[4]);
  seed = atoi(argv[5]);
  p = argv[6];
  tedges = 0;

  if (maxcap <= 0) { cerr << "maxcap has to be > 0\n"; exit(1); }
  if (mincap <= 0) { cerr << "mincap has to be > 0\n"; exit(1); }
  if (window == 0) { cerr << "window has to be != 0\n"; exit(1); }

  srand48(seed);
  gettimeofday(&tp, NULL);
  start = tp.tv_usec;
  start /= 1000000.0;
  start += tp.tv_sec;

  G.Adj.resize(n);
  G.W.resize(n);

  if (window > 0) {
    for (i = 0; i < G.Adj.size(); i++) {
      for (j = 1; j <= window && i+j < G.Adj.size(); j++) {
        G.Adj[i].push_back(i+j);
        G.W[i].push_back(lrand48()%(maxcap-mincap+1)+mincap);
        tedges++;
      }
    }
  } else {
    window = -window;
    i = 0;
    for (l = 1; l < n-1; l += n/window) {
      for (j = i; j < l; j++) {
        for (k = l; k < l + n/window && k < n; k++) {
          G.Adj[j].push_back(k);
          G.W[j].push_back(lrand48()%(maxcap-mincap+1)+mincap);
          tedges++;
        }
      }
      i = l;
    }
    for (j = i; j < n-1; j++) {
      G.Adj[j].push_back(n-1);
      G.W[j].push_back(lrand48()%(maxcap-mincap+1)+mincap);
          tedges++;
    }
  }

  if (p == "y") {
    for (i = 0; i < G.Adj.size(); i++) {
      printf("Node %d: ", i);
      for (j = 0; j < G.Adj[i].size(); j++) {
        printf("[%d,%lld]", G.Adj[i][j], G.W[i][j]);
      }
      printf("\n");
    }
  }

  gettimeofday(&tp, NULL);
  create = tp.tv_usec;
  create /= 1000000.0;
  create += tp.tv_sec;

  sp = G.Shortest_Path();

  gettimeofday(&tp, NULL);
  stop = tp.tv_usec;
  stop /= 1000000.0;
  stop += tp.tv_sec;

  printf("Total edges in graph:  %10lld\n", tedges);
  printf("Shortest Path:         %10lld\n", sp);
  printf("Edges Processed:       %10d\n", G.Edges_Processed);
  printf("Graph Creation Time:   %10.3lf\n", create-start);
  printf("Shortest Path Time:    %10.3lf\n", stop-create);
  exit(0);
}

long long Graph::Shortest_Path()
{
  int nn, f, t, c, i, n, j;
  long long d, nd;
  deque <int> Q;
  vector < int > In;
  vector < long long > SP;

  nn = Adj.size();
  In.resize(nn, 0);
  SP.resize(nn, -1);

  for (i = 0 ; i < nn; i++) {
    for (j = 0; j < Adj[i].size(); j++) {
      t = Adj[i][j];
      In[t]++;
    }
  }

  for (i = 0 ; i < In.size(); i++) {
    if (In[i] == 0) Q.push_back(i);
  }

  SP[0] = 0;
  Edges_Processed = 0;

  while (!Q.empty()) {
    f = Q[0];
    Q.pop_front(); 
    if (f == nn-1) return SP[f];
    d = SP[f];
    for (i = 0; i < Adj[f].size(); i++) {
      Edges_Processed++;
      t = Adj[f][i];
      In[t]--;
      if (In[t] == 0) Q.push_back(t);
      if (d != -1) {
        nd = d + W[f][i];
        if (SP[t] == -1 || nd < SP[t]) SP[t] = nd;
      }
    }
  }
  return -1;
}
