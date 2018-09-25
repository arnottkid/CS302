/* make_invoice_1_normal.cpp.
   James S. Plank
   Sun Sep 23 14:27:27 EDT 2018

   This is our example program of processing sales in our fictitious Esty store.
   We have a C++ class for a Dog Sweater, and for a Koozie.  They have quite a lot
   in common, and because we're not using inheritance or interfaces, we don't
   take advantage of their commonalities.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* The Dog class is written using Dr. Plank-style C++, with no code in the
   class definitions, no default values, and non-inline definitions of the methods.
 */

class Dog {
  public:
    Dog(istringstream &ss);
    string Description();
    double Price();
    double Expenses();
  protected:
    string color;
    string size;
    double yards;
    double price;
};

Dog::Dog(istringstream &ss)
{
  ss >> size >> color;

  if (size == "S") {
    yards = 3.0;
    price = 20.0;
  } else if (size == "L") {
    yards = 6.0;
    price = 40.0;
  } else {
    fprintf(stderr, "Bad dog size: %s\n", size.c_str());
    exit(1);
  }
}

string Dog::Description()
{
  string s;
 
  s = (size == "S") ? "Small " : "Large ";
  s += color;
  s += " Dog Sweater";
  return s;
}

double Dog::Price()
{
  return price;
}

double Dog::Expenses()
{
  return yards * 2.25;
}

/* On the flip side, the Koozie definition is code in the style of C++ that I don't like:
   Method definitions inline, with default values set in the constructor specification. 
   You may prefer this style, and while I acknowledge the simplicity of the specifications
   of Price() and Expenses(), I still don't like it. I like to have defintions and 
   implementations separated. */

class Koozie {
  protected:
    string color;
    string monogram;
    double yards;
    double price;
  public:
    Koozie(istringstream &ss) : 
       yards(1.5), 
       price(10.0) 
       { ss >> color >> monogram; };
    string Description() {
      string s;
      s = color + " Koozie with monogram ";
      s += monogram; 
      return s;
    }
    double Price() { return price; }
    double Expenses() { return yards * 2.25; }
};

/* The main code is really straightforward: */

int main()
{
  istringstream ss;
  string name;
  string line;
  string key;
  Dog *d;
  Koozie *k;
  string desc;    // Description of an item.
  double p;       // Price of an item.
  double e;       // Expenses of an item.
  double tp;      // Running total of prices.
  double te;      // Running total of expenses.
  double fees;    // Fees

  /* Customer name. */

  getline(cin, name);
  printf("Customer: %s\n", name.c_str());
  printf("\n");

  printf("%-60s %6s %6s\n", "Description", "Price", "Costs");

  /* Print each item -- description, price, expenses. 
     You'll note that there's some code duplication, because Dog and Koozie
     are different classes.  */

  tp = 0;
  te = 0;
  while (getline(cin, line)) {
    ss.clear();
    ss.str(line);
    ss >> key;
    if (key == "Koozie") {
      k = new Koozie(ss);
      desc = k->Description();
      p = k->Price();
      e = k->Expenses();
      delete k;
    } else if (key == "Dog") {
      d = new Dog(ss);
      desc = d->Description();
      p = d->Price();
      e = d->Expenses();
      delete d;
    }
    tp += p;
    te += e;
    printf("%-60s %6.2lf %6.2lf\n", desc.c_str(), p, e);
  }

  /* Print the final information. */

  printf("\n");
  fees = tp * 0.08;
  printf("Gross:  %8.2lf\n", tp);
  printf("Costs:  %8.2lf\n", te);
  printf("Fees:   %8.2lf\n", fees);
  printf("Profit: %8.2lf\n", tp - te - fees);
  return 0;
}
