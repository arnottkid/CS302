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
                                             /* These are added for Dijkstra's Algorithm: */
    int bestflow;                            /* The best flow discovered so far to this node. */
    class Edge *backedge;                    /* The edge from which this flow came. */
    multimap <int, Node *>::iterator qit;    /* If I'm on the queue, an iterator to my place. */
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
    int index;     /* Where I am on the adjacenty list.  -1 if I have 0 residual */
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
  
     int Dijkstra();
     vector <Edge *> Path;

     int MaxCap;
     Node *Source;
     Node *Sink;
     vector <Node *> Nodes; 
     vector <Edge *> Edges; 
     map <string, Node *> N_Map;
     map <string, Edge *> E_Map;
};

int Graph::Dijkstra()
{
  multimap <int, Node *> Q;     /* Here's the sorted list of best flow to nodes */
  Node *n;                      /* The node that I'm processing from the back of Q. */
  int f;                        /* When I'm processing n, this is the flow to n. */
  Edge *e;                      /* I process each edge from n */
  Node *t;                      /* This is the node that e goes to: e is (n,t) */
  int nf;                       /* This is the flow to t if I go through n.  If it's better than
                                   t's current best flow, I'll delete t from Q and put it back
                                   on Q with this flow. */

  multimap <int, Node *>::iterator qit;
  int i;    

  for (i = 0; i < Nodes.size(); i++) Nodes[i]->bestflow = 0;
  
  /* Start by putting the Source onto the queue with infinite flow. */

  Source->backedge = NULL;
  Source->bestflow = MaxCap;
  Source->qit = Q.insert(make_pair(MaxCap, Source));

  /* Now process the Queue.  
     Always process the last element (that's the one with the most flow). */

  while(!Q.empty()) {

    /* Grab the last element and delete it */
    f = Q.rbegin()->first;
    n = Q.rbegin()->second;
    Q.erase(n->qit);

    /* If we're at the sink, we're done.  
       Create the path by traversing backedges back to the source. */
 
    if (n == Sink) {
      while (n != Source) {
        Path.push_back(n->backedge);
        n = n->backedge->n1;
      }
      return 1;
    }

    /* Otherwise, process each of n's edges, and if the path through n to t
       has better flow than t's current flow, then delete t from Q if it's
       there, and insert t into Q with this new flow. */

    for (i = 0; i < n->adj.size(); i++) {
      e = n->adj[i];
      t = e->n2;
      nf = (e->residual < f) ? e->residual : f;
      if (nf > t->bestflow) {
        if (t->bestflow != 0) Q.erase(t->qit);
        t->backedge = e;
        t->bestflow = nf;
        t->qit = Q.insert(make_pair(nf, t));
      }
    }
  }

  /* Return 0 if there's no path to the sink. */

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
  Edge *e, *swap;
  Node *n;

  Path.clear();
  if (Verbose.find('G') != string::npos) Print();
  if (Dijkstra()) {

    /* Calculate the flow through the path */

    f = MaxCap;
    for (i = 0; i < Path.size(); i++) {
      if (Path[i]->residual < f) f = Path[i]->residual;
    }

    if (Verbose.find('P') != string::npos) {
      printf("Path with flow %d: ", f);
      for (i = Path.size()-1; i >= 0; i--) Path[i]->Print();
      printf("\n");
    }

    /* Process residual Graph */

    for (i = 0; i < Path.size(); i++) {
      e = Path[i];
      e->residual -= f;
      if (e->residual == 0) {
        n = e->n1;
        swap = n->adj[n->adj.size()-1];
        swap->index = e->index;
        n->adj[e->index] = swap;
        n->adj.pop_back();
        e->index = -1;
      }
      e->reverse->residual += f;
      if (e->reverse->residual == f) {
        n = e->n2;
        e->reverse->index = n->adj.size();
        n->adj.push_back(e->reverse);
      }
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
  e->index = -1;
  return e;
}

Node *Graph::Get_Node(string &s)
{
  Node *n;

  if (N_Map.find(s) != N_Map.end()) return N_Map[s];

  n = new Node;
  n->name = s;
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

      if (e->residual == cap) {
        e->index = n1->adj.size();
        n1->adj.push_back(e);  
      }

      if (e->reverse == NULL) {  /* This means that the edge was just created */
        r = Get_Edge(n2, n1);
        e->reverse = r;
        r->reverse = e;

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
