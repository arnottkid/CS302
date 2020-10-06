#include "disjoint.hpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

typedef std::runtime_error SRE;

void usage()
{
  fprintf(stderr, "usage: bin/dj_tool [prompt]\n");
  exit(1);
}

void print_commands()
{
  printf("N s|h|r # - Create a new instance of by-size/by-height/by-rank-wpc with # elements.\n");
  printf("F e       - Call Find(e).\n");
  printf("U s1 s2   - Call Union(s1, s2) -- s1 and s2 must be set id's and not random elements.\n");
  printf("P         - Call Print().\n");
  printf("?         - Print commands.\n");
  printf("Q         - Quit.\n");
}

int main(int argc, char **argv)
{
  DisjointSet *d;
  istringstream ss;
  vector <string> sv;
  string line, s;
  string shr;

  shr = "shr";
  d = NULL;
  if ((argc != 1 && argc != 2) || (argc == 2 && (string) argv[1] == "--help")) usage();  

  while (true) {
    if (argc == 2) {
      printf("%s ", argv[1]);
      fflush(stdout);
    }
    if (!getline(cin, line)) return 0;
    try {
      sv.clear();
      ss.clear();
      ss.str(line);
      while (ss >> s) sv.push_back(s);
      if (sv.size() == 0 || sv[0][0] == '#') {

      } else if (sv[0] == "N") {
        if (sv.size() != 3) throw SRE("N must be called with s|h|r and # of elements.");
        if (sv[1].size() != 1) throw SRE("N must be called with s|h|r and # of elements.");
        if (shr.find(sv[1][0]) == string::npos) throw SRE("s|h|r must be one of 's', 'h' or 'r'");
        if (atoi(sv[2].c_str()) <= 0) throw SRE("# elements must be > 0");
        if (d != NULL) delete d;
        switch(sv[1][0]) {
          case 's': d = new DisjointSetBySize(atoi(sv[2].c_str())); break;
          case 'h': d = new DisjointSetByHeight(atoi(sv[2].c_str())); break;
          case 'r': d = new DisjointSetByRankWPC(atoi(sv[2].c_str())); break;
          default: exit(1);
        }

      } else if (sv[0] == "F") {
        if (sv.size() != 2) throw SRE("F must be called with a element number.");
        cout << d->Find(atoi(sv[1].c_str())) << endl;

      } else if (sv[0] == "U") {
        if (sv.size() != 3) throw SRE("U must be called with two set ids");
        cout << d->Union(atoi(sv[1].c_str()), atoi(sv[2].c_str())) << endl;

      } else if (sv[0] == "P") {
        d->Print();

      } else if (sv[0] == "?") {
        print_commands();

      } else if (sv[0] == "Q") {
        exit(0);

      } else {
        printf("Unknown command: %s\n", sv[0].c_str());
        printf("Use '?' for a list of commands.\n");
      }
    } catch (const std::runtime_error &e) {
      cout << e.what() << endl;
    }
  }
}
