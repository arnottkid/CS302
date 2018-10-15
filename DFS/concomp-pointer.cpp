#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* The Node class:  

   Each node's adjacency list contains pointers to the nodes that are
   adjacent to them.  This is unlike the code in the main set of
   lecture notes, where the adjacency lists contains integers, and
   the integers are used as indices to a vector that contains all of
   the nodes. */

class Node {
  public:
    int id;
    int component;
    vector <Node *> Adj;
};

/* Because our adjacency list contains pointers, we don't need a Graph
   class.  We don't need to access the vector of nodes, because
   we access each node directly in the adjacency list with a pointer.
   Contrast this with the other code in the lecture notes, where
   DFS() is a method that is part of a Graph class, which is
   necessary because you need to use the indices to the vector of
   nodes in the graph class.

   Also, in this code, I print out the beginning of each DFS call, indenting
   it with two spaces for every nested level of recursion.  You should take a look
   at that printf call.  I include it here:

   printf("%*sDFS(%d,%d)\n", indent, "", n->id, cn);

   The asterisk says to read the field width from the next argument -- that means
   that that part of the output will be padded to "indent" spaces.  Following the 
   asterisk is an "s", which means to print out a string (C style).  
   I give it the empty string.  So, if, for example, "indent" is equal to 4, this
   will print out four spaces.
*/

void DFS(Node *n, int cn, int indent)
{
  int i;

  printf("%*sDFS(%d,%d)\n", indent, "", n->id, cn);
  if (n->component != -1) return;
  n->component = cn;
  for (i = 0; i < n->Adj.size(); i++) DFS(n->Adj[i], cn, indent+2);  
}

/* The main() routine -- this reads in the graph, and then calls the DFS
   on each node whose "component" field is -1.  At the end, it prints each
   node. */

int main()
{
  vector <Node *> Nodes;     /* These are the nodes.  Note that they are pointers. */
  int nn;
  int f, t;
  int i, j;
  string s;
  Node *nf, *nt;
  int cn;

  getline(cin, s);
  sscanf(s.c_str(), "NNODES %d", &nn);

  /* Because "Nodes" is a vector of pointers, for each of the i nodes, we need
     to allocate it with new.  We then set its id, and set its component number 
     to be negative one. */

  Nodes.resize(nn);
  for (i = 0; i < Nodes.size(); i++) {
    Nodes[i] = new Node;
    Nodes[i]->id = i;
    Nodes[i]->component = -1;
  }

  /* Read the edges.  We then put each node on the other's adjacency list.  Once
     again, the nodes are pointers, so it's cleaner to use the temporary variables
     "nf" and "nt", which are also pointers. */

  while (getline(cin, s)) {
    sscanf(s.c_str(), "EDGE %d %d", &f, &t);
    nf = Nodes[f];
    nt = Nodes[t];
    nf->Adj.push_back(nt);
    nt->Adj.push_back(nf);
  }

  /* Do the DFS()'s */

  cn = 0;
  for (i = 0; i < Nodes.size(); i++) {
    if (Nodes[i]->component == -1) {
      DFS(Nodes[i], cn, 0);
      cn++;
    }
  }

  /* Print out each node. */

  for (i = 0; i < Nodes.size(); i++) {
    nf = Nodes[i];
    printf("%2d: Component:%2d Edges:", nf->id, nf->component);
    for (j = 0; j < nf->Adj.size(); j++) {
      nt = nf->Adj[j];
      printf(" %d", nt->id);
    }
    printf("\n");
  }
  
  return 0;
}

