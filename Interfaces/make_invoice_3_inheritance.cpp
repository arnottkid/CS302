/* make_invoice_3_inheritance.cpp.
   James S. Plank
   Mon Sep 24 18:10:59 EDT 2018

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

    // We have moved these variables and members into the class.

    string color;
    double yards;
    double price;

    double Price();
    double Expenses();
};

/* And we implement them here. */

double Item::Price() { return price; }
double Item::Expenses() { return yards * 2.25; }

/* Our Dog class now only has the items that are specific to it. */

class Dog : public Item {
  public:
    Dog(istringstream &ss);
    string Description();
  protected:
    string size;
};

Dog::Dog(istringstream &ss)
{
  ss >> size >> color;

  if (size == "S") {
    yards = 3.0;
    price = 20.0;
  } else if (size == "L") {
    yards = 6.0;
    price = 20.0;
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

/* Same with the Koozie class. */

class Koozie : public Item {
  public:
    Koozie(istringstream &ss);
    string Description();
  protected:
    string monogram;
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

/* The main code is identical to the interface version. */

int main()
{
  Item *i;           
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
    if (key == "Koozie") {          
      i = new Koozie(ss);           
    } else if (key == "Dog") {      
      i = new Dog(ss);              
    }
    desc = i->Description();        
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
