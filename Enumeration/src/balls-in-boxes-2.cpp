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

  if (index == boxes.size()) {
    cout << boxes[0];
    for (i = 1; i < boxes.size(); i++) cout << " " << boxes[i];
    cout << endl;
    return;
  }

  for (bit = balls.begin(); bit != balls.end(); bit++) {
    boxes[index] = bit->first;
    bit->second--;
    if (bit->second == 0) {
      balls.erase(bit);
      bit = balls.end();
    }
    GenInstances(index+1);  
    if (bit == balls.end()) {
      bit = balls.insert(make_pair(boxes[index], 1)).first;
    } else bit->second++;
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
