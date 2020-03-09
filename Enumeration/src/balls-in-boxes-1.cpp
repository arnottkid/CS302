#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class BallsInBoxes {
  public:
    map <string,int> balls;
    vector <string> boxes;
    void GenInstances(size_t index);
};

void BallsInBoxes::GenInstances(size_t index)
{
  size_t i;
  map <string, int>::iterator bit;

  /* Base case -- if you have placed all of the balls in boxes,
     print them out, and return. */

  if (index == boxes.size()) {
    cout << boxes[0];
    for (i = 1; i < boxes.size(); i++) cout << " " << boxes[i];
    cout << endl;
    return;
  }

  /* For each color where you haven't placed a ball yet, place the ball, 
     make a recursive call, and remove the ball. */

  for (bit = balls.begin(); bit != balls.end(); bit++) {
    if (bit->second > 0) {
      boxes[index] = bit->first;
      bit->second--;
      GenInstances(index+1);  
      bit->second++;
      /* I don't actually "remove" the ball here, because subsequent iterations
         of the loop, or subsequent recursive calls will overwrite boxes[index]. */
    }
  }
}

int main()
{
  BallsInBoxes B;
  string s;
  int nb;

  nb = 0;
  while (cin >> s) { 
    B.balls[s]++; 
    nb++; 
  }
  B.boxes.resize(nb);
  
  B.GenInstances(0);
}
