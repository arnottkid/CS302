#include <vector>
#include <set>
using namespace std;

class PQueue {
  public:
    PQueue();
    PQueue(vector <double> &v);
    void Push(double d);
    double Pop();
    int Size();
    int Empty();
    void Print();
  protected:
    multiset <double> h;
};
