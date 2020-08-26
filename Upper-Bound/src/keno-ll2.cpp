#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define VIT(i, v) for (i = 0; i < v.size(); i++) 
#define IT(it, ds) for (it = ds.begin(); it != ds.end(); it++)
#define FUP(i, n) for (i = 0; i < n; i++)

void usage(string s)
{
  cerr << "usage: keno-ll #balls #picked payout iterations-(zero-to-play) verbose(y|n)\n";
  if (s != "") cerr << s << endl;
  exit(1);
}
 
class Keno_LL {
  public:
    int NB;
    int NP;
    int Wins, Losses, Ties;
    vector <int> Balls;      // This is new -- a vector of all of the balls.  
    set <int> Picked;
    int Iterations;
    double Payout;
    double Winnings;
    double N;
    int Verbose;
    void Do_Picking();
    void Calculate_Payout(int b);
};

/* This is new -- choosing random elements of Balls, rather than
   calling random() to pick balls.  */

void Keno_LL::Do_Picking()
{
  int i, j, first, last, tmp;
  set <int>::iterator pbit;

  Picked.clear();
  
  for (i = 0; i < NP; i++) {
    j = random()%(NB-i);
    tmp = Balls[j];
    Balls[j] = Balls[NB-i-1];
    Balls[NB-i-1] = tmp;
    Picked.insert(Balls[NB-i-1]);
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

  for (i = 1 ; i <= K.NB; i++) K.Balls.push_back(i);

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
      K.Do_Picking();
      K.Calculate_Payout(b);
    }
  }

  while (K.N < K.Iterations) {
    b = random()%(K.NB)+1;
    if (K.Verbose) printf("Picked %d\n", b);
    K.Do_Picking();
    K.Calculate_Payout(b);
  }
  if (!K.Verbose) {
    printf("Total = %.2lf.  Avg = %.6lf.  W/L/T: %d %d %d\n", 
           K.Winnings, K.Winnings/K.N, K.Wins, K.Losses, K.Ties);
  }
  exit(0);
}
