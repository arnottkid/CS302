#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;

class Subseq {
  public:
    map <string, int> cache;
    int LCS(string s1, string s2);
};

int Subseq::LCS(string s1, string s2)
{
  string key;
  int r1, r2;

  if (s1.size() == 0 || s2.size() == 0) return 0;

  key = s1 + ":";
  key += s2;
  if (cache.find(key) != cache.end()) return cache[key];

  if (s1[0] == s2[0]) {
   cache[key] = 1 + LCS(s1.substr(1), s2.substr(1));
  } else {
    r1 = LCS(s1, s2.substr(1));
    r2 = LCS(s1.substr(1), s2);
    cache[key] = (r1 > r2) ? r1 : r2;
  }
  return cache[key];
}

int main(int argc, char **argv)
{
  Subseq ss;
  string s1, s2;

  if (argc != 3) {
    cerr << "usage: subseq s1 s2\n";
    exit(1);
  }

  s1 = argv[1];
  s2 = argv[2];

  cout << ss.LCS(s1, s2) << endl;
}
  
