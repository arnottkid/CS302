#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

/* Each node is stored in one of these data structures.
   We are using adjacency lists to store edges, but instead
   of using the list data structure, we are using a vector.
   This is because it is space efficient and convenient. */

class Node {
  public:
    int id;                 // The node's number.
    vector <int> edges;     // Adjacency list, holding the 
                            // numbers of the nodes to which
                            // this node is connected.
    int component;          // Component number.
};

class Graph {
  public:
    vector <Node *> nodes;                    // All of the nodes.  nodes[i]->number is i
                                              // Note that it is a vector of pointers.
    void Component_Count(int index, int cn);  // This does the DFS to set components.
    void Print() const;                       // Print the graph.
};

// This is the DFS, where the component variable is used as the visited field.

void Graph::Component_Count(int index, int cn)
{
  Node *n;
  size_t i;

  n = nodes[index];
  if (n->component != -1) return;
  n->component = cn;
  for (i = 0; i < n->edges.size(); i++) Component_Count(n->edges[i], cn);
}

// The Print() function prints each node, its component number and its adjacency list.

void Graph::Print() const
{
  size_t i, j;
  Node *n;

  for (i = 0; i < nodes.size(); i++) {
    n = nodes[i];
    cout << "Node " << i << ": " << n->component << ":";
    for (j = 0; j < n->edges.size(); j++) {
      cout << " " << n->edges[j];
    }
    cout << endl;
  }
}

// The main() function reads in a graph, does the connected component
// determination, and then prints the graph.

int main()
{
  Graph g;
  string s;
  size_t nn, n1, n2, c;
  size_t i;
  Node *n;

  /* Read the number of nodes and create all of the nodes. */

  cin >> s;
  if (s != "NNODES") { cerr << "Bad graph\n"; exit(1); }
  cin >> nn;

  for (i = 0; i < nn; i++) {
    n = new Node;
    n->component = -1;
    n->id = i;
    g.nodes.push_back(n);
  }

  /* Read the edges. */

  while (!cin.fail()) {
    cin >> s >> n1 >> n2;
    if (!cin.fail()) {
      if (s != "EDGE") { cerr << "Bad graph\n"; exit(1); }
      g.nodes[n1]->edges.push_back(n2);
      g.nodes[n2]->edges.push_back(n1);
    }
  }

  /* Do the connected component analyses, and print the graph */

  c = 0;
  for (i = 0; i < g.nodes.size(); i++) {
    if (g.nodes[i]->component == -1) {
      c++;
      g.Component_Count(i, c);
     }
  }
  g.Print();

  return 0;
}
