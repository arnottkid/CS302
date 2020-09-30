#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include "pqueue.hpp"
using namespace std;

typedef runtime_error SRE;

void print_commands(FILE *f)
{
  fprintf(f, "C s|h|v                     - Create as set/heap/from-vector (vals on next line)\n");
  fprintf(f, "PUSH val                    - Push val\n");
  fprintf(f, "POP                         - Call Pop() and return the values.\n");
  fprintf(f, "PRINT                       - Print the state\n");
  fprintf(f, "SIZE                        - Print the size\n");
  fprintf(f, "?                           - Print commands.\n");
  fprintf(f, "Q                           - Quit.\n");
}

int main(int argc, char **argv)
{
  PQueue *pq;

  istringstream ss;
  ofstream fout;
  vector <string> sv;
  vector <double> v;
  string s, l;
  string prompt, cmd;

  double d;

  if (argc > 2 || (argc == 2 && strcmp(argv[1], "--help") == 0)) {
    fprintf(stderr, "usage: bin/pq_tool [prompt]\n");
    fprintf(stderr, "\n");
    print_commands(stderr);
    exit(1);
  }

  if (argc == 2) {
    prompt = argv[1];
    prompt += " ";
  }

  pq = NULL;
  
  while (1) {
    try { 
      if (prompt != "") printf("%s", prompt.c_str());
      if (!getline(cin, l)) return 0;
      sv.clear();
      ss.clear();
      ss.str(l);
      while (ss >> s) sv.push_back(s);
  
      /* Basic commands. */
  
      if (sv.size() == 0) {
      } else if (sv[0][0] == '#') {
      } else if (sv[0] == "?") {
        print_commands(stdout);
      } else if (sv[0] == "Q") {
        exit(0);
      } else if (sv[0] == "C") {
        if (sv.size() != 2 || (sv[1] != "s" && sv[1] != "h" && sv[1] != "v")) {
          cout << "usage: C s|h|v" << endl;
        } else {
          if (pq != NULL) delete pq;
          if (sv[1] == "s") {
            pq = new PQueueSet;
          } else if (sv[1] == "h") {
            pq = new PQueueHeap;
          } else {
            if (!getline(cin, l)) exit(0);
            ss.clear();
            v.clear();
            ss.str(l);
            while (ss >> d) v.push_back(d);
            pq = new PQueueHeap(v);
          }
        }
      } else if (sv[0] == "POP") {
        if (pq == NULL) {
          cout << "Uninitialized priority queue.\n";
        } else {
          printf("%lg\n", pq->Pop());
        }
      } else if (sv[0] == "PUSH") {
        if (sv.size() != 2) {
          cout << "usage: PUSH val\n";
        } else if (pq == NULL) {
          cout << "Uninitialized priority queue.\n";
        } else if (sscanf(sv[1].c_str(), "%lf", &d) == 0) {
          cout << "usage: PUSH val -- val must be a number\n";
        } else {
          pq->Push(d);
        }
      } else if (sv[0] == "PRINT") {
        if (pq == NULL) {
          cout << "Uninitialized priority queue.\n";
        } else {
          pq->Print();
        }
      } else if (sv[0] == "SIZE") {
        if (pq == NULL) {
          cout << "Uninitialized priority queue.\n";
        } else {
          printf("%lu\n", pq->Size());
        }
      } else {
        cout << "Bad command: " << sv[0] << endl;
      }
      
    } catch (const SRE &e) {
      cout << e.what() << endl;
    }
  }

  return 0;
}
