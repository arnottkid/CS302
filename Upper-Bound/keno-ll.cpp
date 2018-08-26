#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void usage(string s)
{
  cerr << "usage: keno-ll #balls #picked payout iterations-(zero-to-play) verbose(y|n)\n";
  if (s != "") cerr << s << endl;
  exit(1);
}
 
class Keno_LL {
  public:
    int NB;              // Initial parameter: Number of balls in play (80 in our example)
    int NP;              // Initial parameter: Number of balls picked each time (20 in our example)
    double Payout;       // This is how much you win in the Lucky Loser bet (1.25 in our example)
    int Iterations;      // Number of iterations for the simulation. 0 if interactive
    int Verbose;         // Output on each iteration, or just at the end?

    set <int> Picked;    // This is used for the balls picked at each iteration

    int Wins, Losses, Ties;       // Stats - total wins, losses and ties
    double Winnings;              // Total winnings (yes, we could calculate from above)
    double N;                     // Iteration so far

    void Pick_Balls();            // Creates Picked randomly
    void Calculate_Payout(int b); // Given a ball b, and set Picked, calculates the payout and updates the stats.
};

/* Procedure to pick balls randomly.  The balls are put into the 
   set "Picked," which is sentinelized so that the first ball is 
   at the end of the set, after the maximum numbered ball, and the 
   last ball is at the beginning of the set, before ball 1. */

void Keno_LL::Pick_Balls()
{
  int i, j, first, last;
  set <int>::iterator pbit;

  Picked.clear();
  
  for (i = 0; i < NP; i++) {
    do j = random()%NB+1; while (Picked.find(j) != Picked.end());
    Picked.insert(j);
  }

  if (Verbose) {
    cout << "Balls Picked:";
    for (pbit = Picked.begin(); pbit != Picked.end(); pbit++) {
      cout << " " << *pbit;
    }
    cout << ".\n";
  }

  first = *(Picked.begin());       /* Sentinelize Picked */
  last = *(Picked.rbegin());
  Picked.insert(NB+first);
  Picked.insert(last-NB);
}

void Keno_LL::Calculate_Payout(int b)
{
  set <int>::iterator pbit;
  int u, l;
  double win;
  
  /* Determine whether b is picked (a tie), a winner or a loser. */

  pbit = Picked.lower_bound(b);
  if (*pbit == b) {
    win = 0;
    Ties++;
  } else {
    u = *pbit;
    pbit--;
    l = *pbit;
    if (u - b < b - l) {
      win = Payout;
      Wins++;
    } else {
      win = -1;
      Losses++;
    }
  }
 
  /* Update stats, and print out what happened, if desired. */

  Winnings += win;
  N++;

  if (Verbose) {
    if (win == 0) {
      printf("  Your ball was picked. +0: ");
    } else {
      printf("  D to higher: %d.  D to lower: %d.  %+.2lf: ",
        u-b, b-l, win);
    }
    printf("Total = %.2lf.  Avg = %.6lf\n", Winnings, Winnings/N);
  }
}

int main(int argc, char **argv)
{
  Keno_LL K;
  int i, b;
  string a5;

  if (argc != 6) usage("");

  if (sscanf(argv[1], "%d", &(K.NB)) == 0 || K.NB <= 0) usage("#Balls must be > 0\n");
  if (sscanf(argv[2], "%d", &(K.NP)) == 0 || K.NP <= 0) usage("#Picked must be > 0\n");
  if (sscanf(argv[3], "%lf", &(K.Payout)) == 0 || K.Payout <= 0) usage("Payout must be > 0\n");
  
  if (sscanf(argv[4], "%d", &(K.Iterations)) == 0 || K.Iterations < 0) {
    usage("Iterations must be >= 0\n");
  }
  a5 = argv[5];
  if (a5 == "y" || a5 == "Y") {
    K.Verbose = 1;
  } else if (a5 == "n" || a5 == "N") {
    K.Verbose = 0;
  } else usage("Verbose must be y|n\n");


  K.Winnings = 0;
  K.N = 0;
  K.Wins = 0;
  K.Losses = 0;
  K.Ties = 0;

  srandom(time(0));

  if (K.Iterations == 0) {
    while(1) {
      b = 0;
      do {
        if (K.Verbose) {
          cout << "Pick your ball: "; 
          cout.flush();
        }
        if (!(cin >> b)) {
          if (!K.Verbose && K.N > 0) {
            printf("Total = %.2lf.  Avg = %.6lf.  W/L/T: %d %d %d\n", 
                    K.Winnings, K.Winnings/K.N, K.Wins, K.Losses, K.Ties);
          }
          exit(0);
        }
        if (b <= 0 || b > K.NB) {
          cin.clear(); 
          cout << "You must pick a ball between 1 and " << K.NB << ".\n";
        }
      } while (b <= 0 || b > K.NB);
      K.Pick_Balls();
      K.Calculate_Payout(b);
    }
  }

  while (K.N < K.Iterations) {
    b = random()%(K.NB)+1;
    if (K.Verbose) printf("Picked %d\n", b);
    K.Pick_Balls();
    K.Calculate_Payout(b);
  }
  if (!K.Verbose) {
    printf("Total = %.2lf.  Avg = %.6lf.  W/L/T: %d %d %d\n", 
           K.Winnings, K.Winnings/K.N, K.Wins, K.Losses, K.Ties);
  }
  exit(0);
}
