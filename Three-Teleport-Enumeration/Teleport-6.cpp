#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class ThreeTeleports {
  public:
    int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports);
    void Permute(int index);

    vector < vector <long long> >AM;
    char PString[4];
};

/* This is recursive code to print all strings with at most one A, one B, and one C. 
   It is similar to the permutation code in the Enumeration lecture notes, but
   it also permutes the NULL character, and then doesn't make a recursive call when
   the NULL character is the one in "index." */

void ThreeTeleports::Permute(int index)
{
  int i;
  char tmp;

  for (i = index; i < 4; i++) {

    tmp = PString[i];             /* Swap each character from index to the end */
    PString[i] = PString[index];
    PString[index] = tmp;

    if (PString[index] == '\0') { /* Stop at the NULL character */
      printf("%s\n", PString);

    } else {                      /* Otherwise, keep making recursive calls. */
      Permute(index+1);
    }

    tmp = PString[i];             /* Swap the character back. */
    PString[i] = PString[index];
    PString[index] = tmp;
  }
}

int ThreeTeleports::shortestDistance(int xMe, int yMe, int xHome, int yHome, 
                                     vector <string> teleports)
{
  vector <long long> X, Y;
  int i, j, x1, x2, y1, y2;
  long long xd, yd;

  /* Create the vectors X and Y, which hold the x and y coordinates of the eight
     locations that we care about. */

  X.push_back(xMe);
  Y.push_back(yMe);

  for (i = 0; i < teleports.size(); i++) {
    sscanf(teleports[i].c_str(), "%d %d %d %d", &x1, &y1, &x2, &y2);
    X.push_back(x1);
    Y.push_back(y1);
    X.push_back(x2);
    Y.push_back(y2);
  }

  X.push_back(xHome);
  Y.push_back(yHome);
  
  /* Create the adjacency matrix. */

  AM.resize(X.size());
  for (i = 0; i < X.size(); i++) {
    for (j = 0; j < X.size(); j++) {
      xd = X[j]-X[i];
      if (xd < 0) xd = -xd;
      yd = Y[j]-Y[i];
      if (yd < 0) yd = -yd;
      AM[i].push_back(xd+yd);
    }
  }

  /* Add the teleports to the adjacency matrix. */

  AM[1][2] = 10;
  AM[2][1] = 10;
  AM[3][4] = 10;
  AM[4][3] = 10;
  AM[5][6] = 10;
  AM[6][5] = 10;

  /* Create the string that we'll permute, and make the recursive permute call. */

  strcpy(PString, "ABC");  /* This turns PString into { 'A', 'B', 'C', '\0' } */
  Permute(0);
  
  return 0;
}
