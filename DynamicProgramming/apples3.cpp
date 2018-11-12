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
    vector <IArray> cache;
    int find_max();
};

int Apple::find_max()
{
  int r1, r2;
  int retval;
  int r, c;
  
  cache[0][0] = apples[0][0];
  for (r = 1; r < rows; r++) cache[r][0] = apples[r][0] + cache[r-1][0];
  for (c = 1; c < cols; c++) cache[0][c] = apples[0][c] + cache[0][c-1];
  
  for (r = 1; r < rows; r++) {
    for (c = 1; c < cols; c++) {
      r1 = cache[r][c-1];
      r2 = cache[r-1][c];
      if (r1 > r2) {
        cache[r][c] =  apples[r][c]+r1;
      } else {
        cache[r][c] = apples[r][c]+r2;
      }
    }
  }
  return cache[rows-1][cols-1];
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
  a.cache.resize(a.rows);
  for (r = 0; r < a.rows; r++) a.cache[r].resize(a.cols, -1);
  
  for (r = 0; r < a.rows; r++) {
    for (c = 0; c < a.cols; c++) {
      cin >> a.apples[r][c];
      if (cin.fail()) {
        cerr << "Not enough apples\n";
        exit(1);
      }
    }
  }
  cout << a.find_max() << endl;
}
