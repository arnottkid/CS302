#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int LCS(string s1, string s2)
{
  int r1, r2;

  /* Base case -- if either string is empty, return 0. */

  if (s1.size() == 0 || s2.size() == 0) return 0;

  /* If the first characters of the two strings equal each other,
     then the answer is one plus the LCS of the two string with
     the first characters chopped off. */

  if (s1[0] == s2[0]) return 1 + LCS(s1.substr(1), s2.substr(1));

  /* Otherwise, the answer is either:
       - The LCS of the 1st string, and the 2nd string without its first character
       - The LCS of the 2nd string, and the 1st string without its first character
   */   

  r1 = LCS(s1, s2.substr(1));
  r2 = LCS(s1.substr(1), s2);
  return (r1 > r2) ? r1 : r2;
}

int main(int argc, char **argv)
{
  string s1, s2;

  if (argc != 3) {
    cerr << "usage: subseq s1 s2\n";
    exit(1);
  }

  s1 = argv[1];
  s2 = argv[2];

  cout << LCS(s1, s2) << endl;
}
  
