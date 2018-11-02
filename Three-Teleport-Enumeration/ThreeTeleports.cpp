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
    void Calculate_Distance();

    vector < vector <long long> >AM;
    char PString[4];
    long long minimum;
};

void ThreeTeleports::Calculate_Distance()
{
  long long d;
  int last_place, front, back;
  int i, j;
  string PS;
  string Dir;

  PS = PString;
  Dir.resize(PS.size(), '-');

  /* Use bit arithmetic to calculate all of the potential directions
     for the teleports. */

  for (i = 0; i < (1 << PS.size()); i++) {
    last_place = 0;
    d = 0;
    for (j = 0; j < PS.size(); j++) {
      front = ((1 << j) & i) ? PS[j]-'0'   : PS[j]-'0'+1;
      back =  ((1 << j) & i) ? PS[j]-'0'+1 : PS[j]-'0';
      Dir[j] = ((1 << j) & i) ? '>' : '<' ;
      d += AM[last_place][front];
      d += 10;
      last_place = back;
    }
    d += AM[last_place][7];
    printf("PS: %3s.  i: %d.  Dir: %3s.  d: %lld\n", PString, i, Dir.c_str(), d);
    if (d < minimum) minimum = d;
  }
}

/* This is recursive code to print all strings with at most one 1, one 3, and one 5. 
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
      Calculate_Distance();

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

  minimum = 0x1000000000LL;
  strcpy(PString, "135");  /* This turns PString into { '1', '3', '5', '\0' } */
  Permute(0);
  
  return minimum;
}
