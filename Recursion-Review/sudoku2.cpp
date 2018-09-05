#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

class Sudoku {
  public:
    vector <string> puzzle;
    void Read();
    void Print();
    int row_ok(int r);
    int column_ok(int c);
    int panel_ok(int pr, int pc);
};

int Sudoku::row_ok(int r)
{
  vector <int> checker;
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
   
int Sudoku::column_ok(int c)
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
   
int Sudoku::panel_ok(int pr, int pc)
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

void Sudoku::Print() 
{
  int i, j;

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
}
