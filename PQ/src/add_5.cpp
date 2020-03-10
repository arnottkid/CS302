/* This is a simple testing program for priority queues, which
   reads five numbers from standard input, pushes them onto
   a priority queue, and then prints the priority queue. */

#include "pqueue.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
  PQueue *pq;
  int i;
  double d;

  /* Construct the proper implementation of the priority queue. */

  if (argc != 2 || (argv[1][0] != 's' && argv[1][0] != 'h')) {
    fprintf(stderr, "usage: add_5 s|h\n");
    exit(1);
  }

  switch (argv[1][0]) { 
    case 's': pq = new PQueueSet(); break;
    case 'h': pq = new PQueueHeap(); break;
    default:  exit(1);
  }

  /* Prompt for five numbers.  Push them and print the PQueue. */

  cout << "Enter five numbers.\n";

  for (i = 0; i < 5; i++) {
    if (!(cin >> d)) exit(1);
    pq->Push(d);
  }
  pq->Print();
  return 0;
}
