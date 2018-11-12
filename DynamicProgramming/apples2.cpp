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
    int find_max(int r1, int c1);
};

int Apple::find_max(int r, int c)
{
  int a;
  int r1, r2;
  int retval;

  if (cache[r][c] != -1) return cache[r][c];

  a = apples[r][c];
  if (r == 0 && c == 0) {
    retval = a;
  } else if (r == 0) {
    retval = a + find_max(r, c-1);
  } else if (c == 0) {
    retval = a + find_max(r-1, c);
  } else {
    r1 = find_max(r, c-1);
    r2 = find_max(r-1, c);
    if (r1 > r2) {
      retval =  a+r1;
    } else {
      retval = a+r2;
    }
  }
  cache[r][c] = retval;
  return retval;
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
  cout << a.find_max(a.rows-1, a.cols-1) << endl;
}
