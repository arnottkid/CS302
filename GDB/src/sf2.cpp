#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Event {
  public: 
    string type;
    double time;
};

int main()
{
  multimap <double, Event *> events;
  multimap <double, Event *>::iterator eit;
  Event *e;
  string type;
  double time;
  int arrival_events;

  arrival_events = 0;

  while (cin >> type >> time) {
    if (type != "Arrival") {
      e = new Event;
      e->type = type;
      e->time = time;
      events.insert(make_pair(time, e));
    } else {
      arrival_events++;
      e = new Event;
      e->type = "Arrival";
      e->time = time;
      events.insert(make_pair(time, e));
    }
  }

  for (eit = events.begin(); eit != events.end(); eit++) {
    e = eit->second;
    printf("%7.4lf %s\n", e->time, e->type.c_str());
  }
  
  printf("Arrival events: %d\n", arrival_events);
  return 0;
}
