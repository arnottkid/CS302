/* This program is just like cycledet2.cpp, except
   it prints the cycle when it detects it. */

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node 
{
  public:
    int id;
    vector <int> edges;
    int visited;
};

class Graph
{
  public:
    vector <Node *> nodes;
    bool is_cycle(int index, int from);
    void Print() const;
};

bool Graph::is_cycle(int index, int from)
{
  Node *n;
  size_t i;

  n = nodes[index];
  if (n->visited) {                // When we detect the cycle, set the node's
    n->visited = 2;                // visited field to two and return.
    cout << "Cycle: " << index;
    return true;
  }
  n->visited = 1;
  for (i = 0; i < n->edges.size(); i++) {
    if (n->edges[i] != from) {
      if (is_cycle(n->edges[i], index)) {   // If we have detected a cycle, then
        cout << " " << index;               // print the nodes in the cycle.
        if (n->visited == 2) {
          cout << endl;
          exit(1);
        }
        return true;
      }
    }
  }
  return false;
}

void Graph::Print() const
{
  size_t i, j;
  Node *n;

  for (i = 0; i < nodes.size(); i++) {
    n = nodes[i];
    cout << "Node " << i << ": " << n->visited << ":";
    for (j = 0; j < n->edges.size(); j++) {
      cout << " " << n->edges[j];
    }
    cout << endl;
  }
}


int main()
{
  Graph g;
  string s;
  size_t nn, n1, n2, i, c;
  Node *n;

  cin >> s;
  if (s != "NNODES") { cerr << "Bad graph\n"; exit(1); }
  cin >> nn;

  for (i = 0; i < nn; i++) {
    n = new Node;
    n->visited = 0;
    n->id = i;
    g.nodes.push_back(n);
  }

  while (!cin.fail()) {
    cin >> s >> n1 >> n2;
    if (!cin.fail()) {
      if (s != "EDGE") { cerr << "Bad graph\n"; exit(1); }
      g.nodes[n1]->edges.push_back(n2);
      g.nodes[n2]->edges.push_back(n1);
    }
  }

  c = 0;
  for (i = 0; i < g.nodes.size(); i++) {
    if (!g.nodes[i]->visited) {
      if (g.is_cycle(i, -1)) {
        cout << "There is a cycle reachable from node " << i << endl;
      }
    }
  }

  g.Print();
  return 0;
}
