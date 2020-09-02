#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

typedef set <int> ISet;
typedef vector <ISet> VISet;

class Sudoku {
  public:
    void Read();                        // Read from standard input
    void Print() const;                 // Print to standard output
    void Solve(int r, int c);           // Solve starting at the given row/col
    int row_ok(int r) const;            // Test row r for correctness
    int column_ok(int c) const;         // Test cols r for correctness
    int panel_ok(int pr, int pc) const; // Test panel pr/pc (both 0,1,2) for correctness
  protected:
    vector <string> puzzle;             // Hold the puzzle in a vector of 9 strings
    vector <ISet> vrows;       // Sets of legal values for each row.
    vector <ISet> vcols;       // Sets of legal values for each row.
    vector <VISet> vpanels;    // Sets of legal values for each panel.
};

void Sudoku::Solve(int r, int c)
{
  int i, j, e;
  vector <int> to_try;
  ISet::iterator rit, cit, pit;

  /* At the beginning, first put all values into the three vectors of sets: */

  if (r == 0 && c == 0) {
    vrows.resize(9);
    vcols.resize(9);
    vpanels.resize(3);
    for (i = 0; i < 3; i++) vpanels[i].resize(3);

    for (i = 0; i < 9; i++) {
      for (j = '1'; j <= '9'; j++) {
        vrows[i].insert(j);
        vcols[i].insert(j);
        vpanels[i/3][i%3].insert(j);
      }
    }
    
    /* Then, run through each row, column and panel of the puzzle,
       and remove values from the sets. */

    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        if (puzzle[i][j] != '-') {
          e = puzzle[i][j];
          vrows[i].erase(vrows[i].find(e));
          vcols[j].erase(vcols[j].find(e));
          vpanels[i/3][j/3].erase(vpanels[i/3][j/3].find(e));
        }
      }
    }
  }
      
  if (c == 9) { c = 0; r++; }

  /* Now, instead of trying every value and testing for legality, we instead create
     a vector from all of the legal values in the row.  We traverse that vector, and
     if a value is legal in the column and panel, then we add it to the puzzle and
     remove it from the three sets.  Then we make the recursive call, and add the value
     back to the sets.  This code is kind of a pain, isn't it? */

  while (r < 9) {
    if (puzzle[r][c] == '-') {
      for(rit = vrows[r].begin(); rit != vrows[r].end(); rit++) to_try.push_back(*rit);
      for (i = 0; i < (int) to_try.size(); i++) {
        e = to_try[i];
        cit = vcols[c].find(e);
        if (cit != vcols[c].end()) {
          pit = vpanels[r/3][c/3].find(e);
          if (pit != vpanels[r/3][c/3].end()) {
            rit = vrows[r].find(e);
            vrows[r].erase(rit);
            vcols[c].erase(cit);
            vpanels[r/3][c/3].erase(pit);
            puzzle[r][c] = e;
            Solve(r, c+1);
            vrows[r].insert(e);
            vcols[c].insert(e);
            vpanels[r/3][c/3].insert(e);
          }
        }
      }
      puzzle[r][c] = '-';
      return;
    }
    c++;
    if (c == 9) { c = 0; r++; }
  }
  Print();
  exit(0);
}

int Sudoku::row_ok(int r) const
{
  vector <int> checker;     /* Use this to make sure no digit is set twice. */
  int c;

  checker.clear();
  checker.resize(10, 0);
  for (c = 0; c < 9; c++) {
    if (puzzle[r][c] != '-') {
      if (checker[puzzle[r][c]-'0']) return 0;
      checker[puzzle[r][c]-'0'] = 1;
    }
  }
  return 1;
}
   
int Sudoku::column_ok(int c) const
{
  vector <int> checker;
  int r;

  checker.resize(10, 0);
  for (r = 0; r < 9; r++) {
    if (puzzle[r][c] != '-') {
      if (checker[puzzle[r][c]-'0']) return 0;
      checker[puzzle[r][c]-'0'] = 1;
    }
  }
  return 1;
}
   
int Sudoku::panel_ok(int pr, int pc) const
{
  vector <int> checker;
  int r, c;
  int i, j;

  checker.resize(10, 0);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      r = pr*3+i;
      c = pc*3+j;
      if (puzzle[r][c] != '-') {
        if (checker[puzzle[r][c]-'0']) return 0;
        checker[puzzle[r][c]-'0'] = 1;
      }
    }
  }
  return 1;
}

void Sudoku::Read() 
{
  int i, j;
  char c;

  puzzle.clear();
  puzzle.resize(9);

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      do {
        if (!(cin >> c)) { 
          cerr << "Not enough cells.\n";
          exit(1);
        }
      } while (isspace(c));
      if (c != '-' && (c < '1' || c > '9')) {
        cerr << "Bad character " << c << endl;
        exit(1);
      }
      puzzle[i].push_back(c);
    }
  }
}

void Sudoku::Print() const
{
  size_t i, j;

  for (i = 0; i < puzzle.size(); i++) {
    for (j = 0; j < puzzle[i].size(); j++) {
      cout << puzzle[i][j];
      if (j == 2 || j == 5) cout << " ";
    }
    cout << endl;
    if (i == 2 || i == 5) cout << endl;
  }
}
  
int main()
{
  int r, c;
  Sudoku S;

  S.Read();
  
  for (r = 0; r < 9; r++) if (!S.row_ok(r)) printf("Bad row %d\n", r);
  for (c = 0; c < 9; c++) if (!S.column_ok(c)) printf("Bad col %d\n", c);
  for (r = 0; r < 3; r++) for (c = 0; c < 3; c++) {
    if (!S.panel_ok(r, c)) printf("Bad panel %d %d\n", r, c);
  }

  S.Solve(0,0);
  printf("No Solution\n");
  exit(0);
}
