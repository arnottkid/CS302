#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* Our class definition for the "Balls in Boxes" problem. */

class BallsInBoxes {
  public:
    map <string,int> balls;           // Key = color of the ball.  Val = # of balls with that color
    vector <string> boxes;            // We will put the colors into each of the boxes.
    void GenInstances(size_t index);  // Recursive method to solve the problem.
};

/* Recursive method to solve the problem.  We'll write this later. */

void BallsInBoxes::GenInstances(size_t index)
{
  (void) index;
}

int main()
{
  BallsInBoxes B;                    /* The instance of the BallsInBoxes class. */
  string s;                          /* This is for reading in the color of each ball. */
  int nb;                            /* This stores the number of balls/boxes while reading */
  map <string, int>::iterator mit;

  nb = 0;               /* Read the balls as strings on standard input. */
  while (cin >> s) { 
    B.balls[s]++; 
    nb++; 
  }
  B.boxes.resize(nb);

  /* Print general info. */

  printf("Total balls & boxes: %d\n", nb);
  for (mit = B.balls.begin(); mit != B.balls.end(); mit++) {
    printf("Color: %-10s    # Balls: %d\n", mit->first.c_str(), mit->second);
  }
  
  B.GenInstances(0);
  return 0;
}
