#include <cstdio>
#include <cstdlib>
#include <iostream> 
#include <vector>
#include <string>
using namespace std;

typedef vector <int> IArray;

class Apple {
  public:
    int rows;
    int cols;
    vector <IArray> apples;
    int find_max(int r1, int c1);
};

int Apple::find_max(int r, int c)
{
  int a;
  int r1, r2;
  int retval;

  a = apples[r][c];
  if (r == 0 && c == 0) return a;
  if (r == 0) return a + find_max(r, c-1);
  if (c == 0) return a + find_max(r-1, c);
  r1 = find_max(r, c-1);
  r2 = find_max(r-1, c);
  return (r1 > r2) ? a+r1 : a+r2;
}

int main(int argc, char **argv)
{
  int r, c;
  Apple a;

  if (argc != 3) {
    cerr << "usage: apples1 rows cols -- apples on standard input\n";
    exit(1);
  }
  
  a.rows = atoi(argv[1]);
  a.cols = atoi(argv[2]);
  a.apples.resize(a.rows);
  for (r = 0; r < a.rows; r++) a.apples[r].resize(a.cols);
  
  for (r = 0; r < a.rows; r++) {
    for (c = 0; c < a.cols; c++) {
      cin >> a.apples[r][c];
      if (cin.fail()) {
        cerr << "Not enough apples\n";
        exit(1);
      }
    }
  }
  cout << a.find_max(a.rows-1, a.cols-1) << endl;
}
