#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <queue>
using namespace std;

enum Dir_Type { UP, DOWN, LEFT, RIGHT };

typedef vector <int> int_vector;

class Maze {
  public:
    int pw;
    int r;
    int c;
    vector <int_vector> cells;
    vector <int> path;
    void Print_Index(int index);
    void PPM();
    void set_h_wall(int i, int j, int red, int green, int blue, vector <int> *pixmap);
    void set_v_wall(int i, int j, int red, int green, int blue, vector <int> *pixmap);
    void set_cell(int i, int j, int red, int green, int blue, vector <int> *pixmap);
};

void Maze::Print_Index(int index)
{
      cout << " [" << index/c << "," << index%c << "]";
}
  
void Maze::set_h_wall(int i, int j, int red, int green, int blue, vector <int> *pixmap)
{
  int pix[3];
  int srpix, col, k;
  
  pix[0] = red;
  pix[1] = green;
  pix[2] = blue;

  srpix = (i*pw+pw/2)*pw*(c+1);
  srpix += (pw*j + pw/2);
  for (col = 0; col < 3; col++) {
    for (k = 0; k < pw; k++) pixmap[col][srpix+k] = pix[col];
  }
}
  
void Maze::set_v_wall(int i, int j, int red, int green, int blue, vector <int> *pixmap)
{
  int pix[3];
  int srpix, col, k;
  
  pix[0] = red;
  pix[1] = green;
  pix[2] = blue;

  srpix = (i*pw+pw/2)*pw*(c+1);
  srpix += (pw*j + pw/2);
  for (col = 0; col < 3; col++) {
    for (k = 0; k < pw; k++) pixmap[col][srpix+k*pw*(c+1)] = pix[col];
  }
}
  
void Maze::set_cell(int i, int j, int red, int green, int blue, vector <int> *pixmap)
{
  int pix[3];
  int srpix, col, k, l;
  
  pix[0] = red;
  pix[1] = green;
  pix[2] = blue;

  srpix = (i*pw+pw/2)*pw*(c+1);
  srpix += (pw*j + pw/2);
  for (col = 0; col < 3; col++) {
    for (k = 0; k < pw; k++) {
      for (l = 0; l < pw; l++) {
        pixmap[col][srpix+l*pw*(c+1)+k] = pix[col];
      }
    }
  }
}
  
void Maze::PPM()
{
  int i, j, k, index, r1, c1;
  vector <int> pixmap[3];

  r1 = r+1;
  c1 = c+1;

  for (i = 0; i < 3; i++) {
    pixmap[i].resize(pw*pw*r1*c1);
    for (j = 0; j < pw*pw*r1*c1; j++) pixmap[i][j] = 255;
  }
  for (i = 0; i < r*c; i++) {
    if (path[i]) set_cell(i/c, i%c, 0, 255, 255, pixmap);
  }

  set_h_wall(0, 0, 255, 255, 255, pixmap);
  set_h_wall(r, c-1, 255, 255, 255, pixmap);
  for (j = 1; j < c; j++) set_h_wall(0, j, 0, 0, 0, pixmap);
  for (j = 0; j < c-1; j++) set_h_wall(r, j, 0, 0, 0, pixmap);
  for (i = 0; i < r; i++) set_v_wall(i, 0, 0, 0, 0, pixmap);
  for (i = 0; i < r; i++) set_v_wall(i, c, 0, 0, 0, pixmap);

  for (i = 0; i < r; i++) {
    for (j = 0; j < c-1; j++) {
      if (!cells[i*c+j][RIGHT]) {
        set_v_wall(i, j+1, 0, 0, 0, pixmap);
      }
    }
  }

  for (i = 0; i < r-1; i++) {
    for (j = 0; j < c; j++) {
      if (!cells[i*c+j][DOWN]) {
        set_h_wall(i+1, j, 0, 0, 0, pixmap);
      }
    }
  }

  cout << "P3" << endl << (c+1)*pw << " " << (r+1)*pw << endl << 255 << endl;
  for (j = 0; j < pw*pw*r1*c1; j++) {
    for (i = 0; i < 3; i++) cout << pixmap[i][j] << endl;
  }
}
  
int main(int argc, char **argv)
{
  Maze m;
  string s;
  int i, j, k, index, i1, i2;

  if (argc != 2) {
    cerr << "usage: maze_ppm cell_pixels(must be odd) - Maze is on standard input\n";
    exit(1);
  }

  if (sscanf(argv[1], "%d", &m.pw) != 1 || m.pw <= 0 || m.pw % 2 == 0) {
    cerr << "Bad cell_pixels\n";
    exit(1);
  }

  cin >> s;
  if (cin.fail() || s != "ROWS") { cerr << "Bad Maze -- no ROWS\n"; exit(1); }

  cin >> m.r;
  if (cin.fail() || m.r <= 0) { cerr << "Bad ROWS\n"; exit(1); }

  cin >> s;
  if (cin.fail() || s != "COLS") { cerr << "Bad Maze -- no COLS\n"; exit(1); }

  cin >> m.c;
  if (cin.fail() || m.c <= 0) { cerr << "Bad COLS\n"; exit(1); }

  m.cells.resize(m.r * m.c);
  m.path.resize(m.r*m.c);
  index = 0;
  for (i = 0; i < m.r; i++) {
    for (j = 0; j < m.c; j++) {
      m.path[index] = 0;
      m.cells[index].resize(4);
      for (k = 0; k < 4; k++) m.cells[index][k] = 1;
      if (i == 0) m.cells[index][UP] = 0;
      if (i == m.r-1) m.cells[index][DOWN] = 0;
      if (j == 0) m.cells[index][LEFT] = 0;
      if (j == m.c-1) m.cells[index][RIGHT] = 0;
      index++;
    }
  }

  while (!cin.fail()) {
    cin >> s;
    if (!cin.fail()) {
      if (s == "WALL") { 
        cin >> i1;
        if (cin.fail() || i1 < 0 || i1 >= m.r * m.c) { cerr << "Bad WALL\n"; exit(1); }
        cin >> i2;
        if (cin.fail() || i2 < 0 || i2 >= m.r * m.c) { cerr << "Bad WALL\n"; exit(1); }
        if (i1 > i2) {
          index = i1; 
          i1 = i2;
          i2 = index;
        }
        if (i1 == i2-1 && i2%m.c != 0) {
          m.cells[i1][RIGHT] = 0;
          m.cells[i2][LEFT] = 0;
        } else if (i1 == i2-m.c) {
          m.cells[i1][DOWN] = 0;
          m.cells[i2][UP] = 0;
        } else {
          cerr << "Bad WALL: " << i1 << " has no proper relationship to " << i2 << endl;
          exit(1);
        }
      } else if (s == "PATH") {
        cin >> i1;
        if (cin.fail() || i1 < 0 || i1 >= m.r * m.c) { cerr << "Bad PATH\n"; exit(1); }
        m.path[i1] = 1;
      } else {
        cerr << "Bad word.  Not PATH or WALL: " << s << endl;
      }
    }
  }

/*
  index = 0;
  for (i = 0; i < m.r; i++) {
    for (j = 0; j < m.c; j++) {
      cout << "CELL";
      m.Print_Index(index);
      cout << ":";
      if (m.cells[index][UP]) m.Print_Index(index-m.c);
      if (m.cells[index][DOWN]) m.Print_Index(index+m.c);
      if (m.cells[index][LEFT]) m.Print_Index(index-1);
      if (m.cells[index][RIGHT]) m.Print_Index(index+1);
      cout << endl;
      index++;
    }
  }
 */

  m.PPM();
}

