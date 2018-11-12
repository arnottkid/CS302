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
    int LCS();
};

int Subseq::LCS()
{
  int r1, r2, i, i1, i2, index, other;

  cache.resize(2);
  for (i = 0; i < cache.size(); i++) cache[i].resize(s2.size()+1, 0);

  for (i1 = s1.size()-1; i1 >= 0; i1--) {
    index = i1%2;
    other = (i1+1)%2;
    for (i2 = s2.size()-1; i2 >= 0; i2--) {
      if (s1[i1] == s2[i2]) {
       cache[index][i2] = 1 + cache[other][i2+1];
      } else {
        r1 = cache[index][i2+1];
        r2 = cache[other][i2];
        cache[index][i2] = (r1 > r2) ? r1 : r2;
      }
    }
  }
  return cache[0][0]; 
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

  cout << ss.LCS() << endl;

}
  
