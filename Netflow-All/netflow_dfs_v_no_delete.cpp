#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Node {
  public: 
    string name;
    vector <class Edge *> adj;
    int visited;
};

class Edge {
  public:
    void Print();
    string name;
    Node *n1;
    Node *n2;
    Edge *reverse;
    int original;
    int residual;
};

class Graph {
  public:
     Graph();
     ~Graph();
     string Verbose;   /* G = print graph at each step. P = print paths.  B = Basic */
     void Print();
     Node *Get_Node(string &s);
     Edge *Get_Edge(Node *n1, Node *n2);
     int MaxFlow();
     int Find_Augmenting_Path();
     int NPaths;
  
     int DFS(Node *n);
     vector <Edge *> Path;

     int MaxCap;
     Node *Source;
     Node *Sink;
     vector <Node *> Nodes; 
     vector <Edge *> Edges; 
     map <string, Node *> N_Map;
     map <string, Edge *> E_Map;
};

int Graph::DFS(Node *n)
{
  int i;
  Edge *e;

  if (n->visited) return 0;
  if (n == Sink) return 1;
  n->visited = 1;

  for (i = 0; i < n->adj.size(); i++) {
    e = n->adj[i];
    if (e->residual != 0) {
      if (DFS(e->n2)) {
        Path.push_back(e);
        return 1;
      }
    }
  }
  return 0;
}

int Graph::MaxFlow()
{
  int mf, f;

  NPaths = 0;
  mf = 0;
  while (1) {
    f = Find_Augmenting_Path();
    mf += f;
    if (f == 0) return mf;
    NPaths++;
  }
}

int Graph::Find_Augmenting_Path()
{
  int i, f;
  Edge *e;

  for (i = 0; i < Nodes.size(); i++) Nodes[i]->visited = 0;
  Path.clear();
  if (Verbose.find('G') != string::npos) Print();
  if (DFS(Source)) {

    /* Calculate the flow through the path */

    f = MaxCap;
    for (i = 0; i < Path.size(); i++) {
      if (Path[i]->residual < f) f = Path[i]->residual;
    }

    /* The path is in reverse order, so we print the vector from back to front */

    if (Verbose.find('P') != string::npos) {
      printf("Path with flow %d: ", f);
      for (i = Path.size()-1; i >= 0; i--) Path[i]->Print();
      printf("\n");
    }

    /* Process residual Graph */

    for (i = 0; i < Path.size(); i++) {
      e = Path[i];
      e->residual -= f;
      e->reverse->residual += f;
    }

    return f;
  }
  return 0;
}

Edge *Graph::Get_Edge(Node *n1, Node *n2)
{
  string en;
  Edge *e;

  en = n1->name + "->";
  en += n2->name;

  if (E_Map.find(en) != E_Map.end()) return E_Map[en];
  e = new Edge;
  e->name = en;
  E_Map[en] = e;
  Edges.push_back(e);
  e->original = 0;
  e->residual = 0;
  e->n1 = n1;
  e->n2 = n2;
  e->reverse = NULL;
  return e;
}

Node *Graph::Get_Node(string &s)
{
  Node *n;

  if (N_Map.find(s) != N_Map.end()) return N_Map[s];

  n = new Node;
  n->name = s;
  n->visited = 0;
  N_Map[s] = n;
  Nodes.push_back(n);
  return n;
}


void Edge::Print()
{
  printf("[%s:%d]", name.c_str(), residual);
}

void Graph::Print()
{
  int i, j;
  Node *n;

  printf("Graph:\n");
  for (i = 0; i < Nodes.size(); i++) {
    n = Nodes[i];
    printf("  ");
    printf("Node: %s - ", n->name.c_str());
    for (j = 0; j < n->adj.size(); j++) n->adj[j]->Print();
    printf("\n");
  }
}

Graph::Graph()
{
  string s, nn, nn2, en;
  int cap, i;
  Node *n1, *n2;
  Edge *e, *r, *tmp;

  MaxCap = 0;
  Source = NULL;
  Sink = NULL;

  while (cin >> s) {
    if (s == "SOURCE" || s == "SINK") {
      if (!(cin >> nn)) exit(0);
      n1 = Get_Node(nn);
      if (s == "SOURCE") {
        if (Source != NULL) { cerr << "Two sources.\n"; exit(1); }
        Source = n1;
      } else {
        if (Sink != NULL) { cerr << "Two sinks.\n"; exit(1); }
        Sink = n1;
      }
    } else if (s == "EDGE") {
      if (!(cin >> nn >> nn2 >> cap)) exit(0);
      if (cap <= 0) exit(0);

      n1 = Get_Node(nn);
      n2 = Get_Node(nn2);
      e = Get_Edge(n1, n2);
      e->original += cap;
      e->residual += cap;
      if (e->residual > MaxCap) MaxCap = cap + 1;
       
      if (e->reverse == NULL) {  /* This means that the edge was just created */
        r = Get_Edge(n2, n1);
        e->reverse = r;
        r->reverse = e;
        n1->adj.push_back(e);
        n2->adj.push_back(r);
      }
    }
  }
  MaxCap *= 2;        /* This is because you can add flow in both directions (just trust me) */
  if (Source == NULL) { cerr << "No Source.\n"; exit(1); }
  if (Sink == NULL) { cerr << "No Sink.\n"; exit(1); }
}

Graph::~Graph()
{
  int i;

  for (i = 0; i < Nodes.size(); i++) delete Nodes[i];
  for (i = 0; i < Edges.size(); i++) delete Edges[i];
}

int main(int argc, char **argv)
{
  Graph *G;
  int f;

  if (argc > 2) {
    cerr << "usage: netflow verbosity(BGP) - graph on stdin\n";
    exit(1);
  }
  G = new Graph();

  if (argc == 2) G->Verbose = argv[1];
  if (G->Verbose.find('B') != string::npos) G->Print();

  f = G->MaxFlow();
  printf("Max flow is %d - Paths: %d\n", f, G->NPaths);
  
  if (G->Verbose.find('B') != string::npos) G->Print();

  delete G;   /* Doing this just to make sure that the destructor works */
}
