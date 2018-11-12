#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Subseq {
  public:
    string s1, s2;
    vector < vector <int> > cache;
    int LCS(int i1, int i2);
};

int Subseq::LCS(int i1, int i2)
{
  int r1, r2, i;

  if (s1.size() == i1 || s2.size() == i2) return 0;

  if (cache.size() == 0) {
    cache.resize(s1.size());
    for (i = 0; i < s1.size(); i++) cache[i].resize(s2.size(), -1);
  }

  if (cache[i1][i2] != -1) return cache[i1][i2];

  if (s1[i1] == s2[i2]) {
   cache[i1][i2] = 1 + LCS(i1+1, i2+1);
  } else {
    r1 = LCS(i1, i2+1);
    r2 = LCS(i1+1, i2);
    cache[i1][i2] = (r1 > r2) ? r1 : r2;
  }
  return cache[i1][i2]; 
}


int main(int argc, char **argv)
{
  Subseq ss;
  int i, j, c;

  if (argc != 3) {
    cerr << "usage: subseq s1 s2\n";
    exit(1);
  }

  ss.s1 = argv[1];
  ss.s2 = argv[2];

  cout << ss.LCS(0, 0) << endl;

}
  
