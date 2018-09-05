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
};

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
  Sudoku S;

  S.Read();
  S.Print();
}
