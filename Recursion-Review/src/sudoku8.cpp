#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

typedef vector <int> IVec;

class Sudoku {
  protected:
    vector <IVec> P;
    int Is_Row_Legal(int r);
    int Is_Col_Legal(int c);
    int Is_Panel_Legal(int r, int c);
    vector <int> RS;
    vector <int> CS;
    vector <int> PS;
    char vecs[0x400][10];
    vector <int> Empty_Cells;
  public:
    Sudoku();
    int Solve(size_t index);
    void Print();
};

int rctoindex(int r, int c)
{
  r /= 3;
  c /= 3;
  return r*3+c;
}

void usage(string s)
{
  cout << s << endl;
  exit(1);
}

int Sudoku::Solve(size_t index)
{
  int i, j, k, r, c, pi;

  if (index == Empty_Cells.size()) return 1;
  
  r = Empty_Cells[index]/9;
  c = Empty_Cells[index]%9;
  pi = rctoindex(r, c);

  j = (RS[r] & CS[c] & PS[rctoindex(r, c)]);
  for (i = 0; vecs[j][i] != 0; i++) {
    k = vecs[j][i];
    P[r][c] = k;
    RS[r] &= (~(1 << k));
    CS[c] &= (~(1 << k));
    PS[pi] &= (~(1 << k));
    if (Solve(index+1)) return 1;
    RS[r] |= (1 << k);
    CS[c] |= (1 << k);
    PS[pi] |= (1 << k);
  }
  P[r][c] = 0;
  return 0;
}

int Sudoku::Is_Row_Legal(int r)
{
  vector <int> l;
  int c, i;

  l.resize(10, 0);
  for (i = 0; i < 9; i++) {
    c = P[r][i];
    if (c != 0) {
      if (l[c] != 0) return 0;
      l[c]++;
    }
  }
  return 1;
}

int Sudoku::Is_Col_Legal(int c)
{
  vector <int> l;
  int x, i;

  l.resize(10, 0);
  for (i = 0; i < 9; i++) {
    x = P[i][c];
    if (x != 0) {
      if (l[x] != 0) return 0;
      l[x]++;
    }
  }
  return 1;
}

int Sudoku::Is_Panel_Legal(int r, int c)
{
  vector <int> l;
  int i, x, j;

  r -= (r%3);
  c -= (c%3);

  l.resize(10, 0);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      x = P[r+i][c+j];
      if (x != 0) {
        if (l[x] != 0) return 0;
        l[x]++;
      }
    }
  }
  return 1;
}


Sudoku::Sudoku()
{
  int i, j, k;
  string s;
  istringstream ss;
  char c;

  P.resize(9);

  for (i = 0; i < 9; i++) {
    if (!getline(cin, s)) usage("Not enough lines\n");
    ss.clear();
    ss.str(s);
    while (ss >> c) {
      if (c >= '1' && c <= '9') {
        P[i].push_back(c-'0');
      } else if (c == '-') {
        P[i].push_back(0);
      } else usage("Illegal character\n");
    }
    if (P[i].size() == 0) {
      i--; /* This needs a comment */
    } else if (P[i].size() != 9) usage("Wrong number of characters in a line.\n");
  }
  if (getline(cin, s) && s.size() > 0) usage("Extra junk at the end.\n");

  for (i = 0; i < 9; i++) {
    if (!Is_Row_Legal(i)) usage("Bad row.");
    if (!Is_Col_Legal(i)) usage("Bad column.");
  }
  for (i = 0; i < 9; i += 3) {
    for (j = 0; j < 9; j += 3) {
      if (!Is_Panel_Legal(i, j)) usage("Bad Panel.");
    }
  }

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) if (P[i][j] == 0) Empty_Cells.push_back(i*9+j);
  }

  RS.resize(9, 0);
  CS.resize(9, 0);
  PS.resize(9, 0);

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (P[i][j] != 0) {
        RS[i] |= (1 << P[i][j]);
        CS[j] |= (1 << P[i][j]);
        PS[rctoindex(i, j)] |= (1 << P[i][j]);
      }
    }
  }

  for (i = 0; i < 9; i++) {
    RS[i] = (~RS[i] & 0x3fe);
    CS[i] = (~CS[i] & 0x3fe);
    PS[i] = (~PS[i] & 0x3fe);
  }

  vecs[0][0] = 0;
  for (i = 2; i < (1 << 10); i++) {
    k = 0;
    for (j = 1; j <= 9; j++) if (i & (1 << j)) {
      vecs[i][k] = j;
      k++;
    }
    vecs[i][j] = 0;
  }
}

void Sudoku::Print()
{
  int i;
  int j;
  string s;
  set <int>::iterator sit;

  s = "-123456789";

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      printf("%c", s[P[i][j]]);
      if (j == 2 || j == 5) cout << " ";
    }
    if (i == 2 || i == 5) cout << endl;
    printf("\n");
  }

/*
  for (i = 0; i < 9; i++) {
    printf("Row %d:", i);
    for (j = 1; j <= 9; j++) if (RS[i] & (1 << j)) printf(" %d", j);
    printf("\n");
  }
  for (i = 0; i < 9; i++) {
    printf("Col %d:", i);
    for (j = 1; j <= 9; j++) if (CS[i] & (1 << j)) printf(" %d", j);
    printf("\n");
  }
  for (i = 0; i < 9; i++) {
    printf("Panel %d:", i);
    for (j = 1; j <= 9; j++) if (PS[i] & (1 << j)) printf(" %d", j);
    printf("\n");
  }
*/
}

int main()
{
  Sudoku *s;

  s = new Sudoku();

  s->Solve(0); 
  s->Print();

  delete s;
}
