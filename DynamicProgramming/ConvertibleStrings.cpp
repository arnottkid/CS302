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

class ConvertibleStrings {
  public:
    int leastRemovals(string A, string B);
    map <string, int> Cache;
};

int ConvertibleStrings::leastRemovals(string A, string B)
{
  int i;
  int v1, v2, p;
  string newa, newb;
  string key;

  /* Base case: The size equals zero. */

  if (A.size() == 0) return 0;

  /* Check the Cache.  Use a concatenation of the strings as a key. */

  key = A + " ";
  key += B;
  if (Cache.find(key) != Cache.end()) return Cache[key];

  /* First recursive call -- remove the first character 
     of each string, and add one to the return value.  */

  v1 = 1 + leastRemovals(A.substr(1), B.substr(1));

  /* Second recursive call -- match the first character of A to the first character of B.
     Add up the "penalty" in p, and construct new strings for A and B those characters
     are deleted. */

  p = 0;
  newa = "";
  newb = "";
  for (i = 0; i < A.size(); i++) {
    if (A[i] == A[0] && B[i] == B[0]) {
      /* If there's a match, do nothing. */
    } else if (A[i] == A[0] || B[i] == B[0]) {
      p++;
    } else {
      newa.push_back(A[i]);
      newb.push_back(B[i]);
    }
  }

  /* Make your second recursive call to these new strings, and add the penalty. */

  v2 = p + leastRemovals(newa, newb);

  /* The answer is the minimum of these two. */

  Cache[key] = (v2 < v1) ? v2 : v1;
  return Cache[key];
}

/* The main() compiles in the examples. */

int main(int argc, char **argv)
{
  class ConvertibleStrings TheClass;
  int retval;
  string A;
  string B;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

 if (atoi(argv[1]) == 0) {
    A = "DD";
    B = "FF";
  }

 if (atoi(argv[1]) == 1) {
    A = "AAAA";
    B = "ABCD";
  }

 if (atoi(argv[1]) == 2) {
    A = "AAIAIA";
    B = "BCDBEE";
  }

 if (atoi(argv[1]) == 3) {
    A = "ABACDCECDCDAAABBFBEHBDFDDHHD";
    B = "GBGCDCECDCHAAIBBFHEBBDFHHHHE";
  }

 if (atoi(argv[1]) == 4) {
    A = "DEFDEDFFDEED";  
    B = "WYZYXYWYZYXY";
  }

  retval = TheClass.leastRemovals(A, B);
  cout << retval << endl;

  exit(0);
}
