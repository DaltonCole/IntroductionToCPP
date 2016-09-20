//Programmer: DALTON COLE
//Class and Section: 53, A
//Date: 11/11/13
//Description: driver file

#include "customer.h"
#include "business.h"
#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;

//constants
//const float Cost = 40; // cost per item

int main()
{
  //set random to time
  srand(time(NULL));

//  customer Joe, Dalton, Poory

  customer Joe(111, "Joe");
  customer Dalton(223, "Dalton");
  customer Poory(10, "Poory");

  business DRC("DRC Co", 12);
  
  DRC.cust_add(Joe);
  DRC.make_a_sale();

  DRC.cust_add(Dalton);
  DRC.make_a_sale();
  
  DRC.cust_add(Poory);
  DRC.make_a_sale();
  
  DRC.printbus();

  return 0;
}
