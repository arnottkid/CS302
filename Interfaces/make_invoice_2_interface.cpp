/* make_invoice_2_interface.cpp.
   James S. Plank
   Mon Sep 24 00:41:49 EDT 2018

   This is another  example program of processing sales in our fictitious Esty store.
   Now, we have an interface for an Item class, which has three virtual methods:
   Description(), Price() and Expenses().  Our Dog and Koozie classes implement this
   interface, and that simplifies the code in our main().
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Item {
  public:
    virtual ~Item() {};
    virtual string Description() = 0;
    virtual double Price() = 0;
    virtual double Expenses() = 0;
};

/* Our Dog class is identical to before, except in the first line of its specification,
   it declares that it implements the <b>Item</b> interface: */

class Dog : public Item {
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

double Dog::Price() { return price; }
double Dog::Expenses() { return yards * 2.25; }

/* The Koozie class is also the same except that it too implements the
   Item interface.  I also made it look like the Dog class, because I 
   really can't stand having code in my specifications. */

class Koozie : public Item {
  public:
    Koozie(istringstream &ss);
    string Description();
    double Price();
    double Expenses();
  protected:
    string color;
    string monogram;
    double yards;
    double price;
};

Koozie::Koozie(istringstream &ss) 
{
  yards = 1.5;
  price = 10.0;
  ss >> color >> monogram; 
};

string Koozie::Description() 
{
  string s;
  s = color + " Koozie with monogram ";
  s += monogram; 
  return s;
}

double Koozie::Price() { return price; }
double Koozie::Expenses() { return yards * 2.25; }

/* The main code is similar, except now you declare an item, and set it
   at run-time to be either a Dog or Koozie.  That removes the code 
   duplication that we had in the previous code. */

int main()
{
  Item *i;           // No longer do we have separate Dog / Koozie.
  istringstream ss;
  string name;
  string line;
  string key;
  string desc;       // Description of an item.
  double p;          // Price of an item.
  double e;          // Expenses of an item.
  double tp;         // Running total of prices.
  double te;         // Running total of expenses.
  double fees;       // Fees

  /* Customer name. */

  getline(cin, name);
  printf("Customer: %s\n", name.c_str());
  printf("\n");

  printf("%-60s %6s %6s\n", "Description", "Price", "Costs");

  tp = 0;
  te = 0;
  while (getline(cin, line)) {
    ss.clear();
    ss.str(line);
    ss >> key;
    if (key == "Koozie") {          // Here is the relevant code.
      i = new Koozie(ss);           // Since Koozie/Dog implement the 
    } else if (key == "Dog") {      // Item interface, we can treat 
      i = new Dog(ss);              // them as items.
    }
    desc = i->Description();        // Now there is no code duplication.
    p = i->Price();
    e = i->Expenses();
    delete i;

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
