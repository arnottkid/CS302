#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef vector <double> Dvec;

typedef map <int, Dvec> IDMap;
typedef map <string, IDMap> SIDMap;

int main()
{
  SIDMap t;
  map <int, Dvec>::iterator idit;
  map <string, IDMap>::iterator sidit;
  string program;
  int n, i, j;
  double timing;
  int paths;
  double ttiming, ntiming;
  vector <string> lines;

  while (cin >> program >> n >> timing >> paths) {
    t[program][n].push_back(paths);
  }
  
  lines.push_back("newline linethickness 2 color 0 0 0");
  lines.push_back("newline linethickness 2 color 1 0 0");
  lines.push_back("newline linethickness 2 color 0 .5 0");
  lines.push_back("newline linethickness 2 color 0 0 1");
  lines.push_back("newline linethickness 2 color .8 0 .8");
  lines.push_back("newline linethickness 2 color .8 .8 0");
  lines.push_back("newline linethickness 2 color 0 .8 .8");
  lines.push_back("newline linethickness 2 color .5 .5 .5");

  printf("newgraph\n");
  printf("xaxis size 6 min 0 max 250 hash_labels fontsize 12 hash 50 mhash 4\n");
  printf("  label fontsize 14 : Interior Nodes\n");
  printf("yaxis size 3 min 0 max 1000 hash_labels fontsize 12\n");
  printf("label fontsize 14 : Average number of paths\n");
  printf("title fontsize 16 : Augmenting Paths of Network Flow Algorithms\n");
  printf("clip legend defaults fontsize 12 hjl vjb\n");

  j = 0;
  for (sidit = t.begin(); sidit != t.end(); sidit++) {
    if (j == 4) printf("copygraph xaxis nodraw yaxis nodraw legend defaults hjr vjb\n");
    program = sidit->first;
    printf("%s label : %s\npts\n", lines[j].c_str(), program.c_str());
    
    for (idit = sidit->second.begin(); idit != sidit->second.end(); idit++) {
      ttiming = 0;
      ntiming = 0;
      for (i = 0; i < idit->second.size(); i++) {
        ntiming++;
        ttiming += idit->second[i];
      } 
      printf("%d %lf\n", idit->first, ttiming/ntiming);
    }
    j++;
  }
}
